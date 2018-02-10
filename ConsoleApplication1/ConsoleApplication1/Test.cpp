#include "stdafx.h"
#include "Test.h"
#include<stdio.h>

namespace HomeWork
{
	Test::Test(const char* path)//�������� ����� 
	{
		
		auto err = fopen_s(&testfile, path, "r");
		if (err)
		{
			//errno  ����������� ����� � ������� �������� ��� ������
			switch (errno)
			{
			case 2:
				std::cout << "Error code = " << errno << "[description No such file or Directory ]" << std::endl;
				break;
			}
		}
		else
		{
			std::cout << "Ok" << std::endl;

			while (!feof(this->testfile))// ���� �� ���������� ���� 
			{
				try {
					queryList.push_back(this->readQueryFromFile()); // �� ������ ������� ��������� � ����� � ����� push_back  �� ������ readQueryFromFile
				}
				catch (const std::exception &ex)
				{
					std::cout << ex.what() << std::endl;
					break;
				}
				
			}
		}
	}


	Test::~Test()
	{
		for (auto it = queryList.begin(); it != queryList.end(); ++it)//������� ������ ����� ���� ��� ��������� ������ 
			delete *it;
		fclose(testfile);
		testfile = nullptr;
	}

	Question* Test:: readQueryFromFile()//���������� �� ����� 
	{
		char q[255], an1[255], an2[255], an3[255], var[5];//������ ��� �������� �����
		fgets(q, 255, this->testfile);// ������� ������� � ������ � ��������� ��� ������  ���� �� ����� ������ ��� ����� �����
		fgets(an1, 255, this->testfile);
		fgets(an2, 255, this->testfile);
		fgets(an3, 255, this->testfile);
		if (feof(this->testfile)) throw _exception();
		fgets(var, 5, this->testfile);
		return new Question(q, an1, an2, an3, atoi(var)); // ������� ����� ������ atoi---string->int
	}

	void Test::exec()// ����� ������ ����� 
	{
		for (auto it = queryList.begin(); it != queryList.end(); ++it)
		{
			system("cls");
//������� ����
			int v;
			
				std::cout << (**it) << std::endl;// ������������ ������ ������, ��� ��� �� ��������� ������������ ��� ����	
		    do
			{
				std::cout << "Enter 1-3" << std::endl;
				std::cin >> v;
				
			} 
			while (v < 1 || v > 3);
			
			if ((*it)->test(v))// ��� ��� ��� ��������� �� �����-> ���������� �������� ������ � ���������� 
				correct++;
		}
	}

	int Test::GetResult()
	{
		int r = correct *12 / queryList.size();
		return r;
	}

}