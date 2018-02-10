#include "stdafx.h"
#include "Test.h"
#include<stdio.h>

namespace HomeWork
{
	Test::Test(const char* path)//открытие файла 
	{
		
		auto err = fopen_s(&testfile, path, "r");
		if (err)
		{
			//errno  стандартный класс в котором хранится код ошибки
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

			while (!feof(this->testfile))// пока не закончился файл 
			{
				try {
					queryList.push_back(this->readQueryFromFile()); // со списка считуем вставляем к конец в метод push_back  из метода readQueryFromFile
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
		for (auto it = queryList.begin(); it != queryList.end(); ++it)//перебор списка ведет себя как указатель список 
			delete *it;
		fclose(testfile);
		testfile = nullptr;
	}

	Question* Test:: readQueryFromFile()//считывание из файла 
	{
		char q[255], an1[255], an2[255], an3[255], var[5];//буферы для хранения строк
		fgets(q, 255, this->testfile);// считует символы с потока и сохраняет как строку  пока не конец строки или конец файла
		fgets(an1, 255, this->testfile);
		fgets(an2, 255, this->testfile);
		fgets(an3, 255, this->testfile);
		if (feof(this->testfile)) throw _exception();
		fgets(var, 5, this->testfile);
		return new Question(q, an1, an2, an3, atoi(var)); // создали новый вопрос atoi---string->int
	}

	void Test::exec()// вывод списка теста 
	{
		for (auto it = queryList.begin(); it != queryList.end(); ++it)
		{
			system("cls");
//выведем тест
			int v;
			
				std::cout << (**it) << std::endl;// разыменовуем обьект списка, так как он указатель разыменовуем два раза	
		    do
			{
				std::cout << "Enter 1-3" << std::endl;
				std::cin >> v;
				
			} 
			while (v < 1 || v > 3);
			
			if ((*it)->test(v))// так как это указатель то через-> сравниваем значение ответа с правильным 
				correct++;
		}
	}

	int Test::GetResult()
	{
		int r = correct *12 / queryList.size();
		return r;
	}

}