#pragma once
#include"Question.h"
#include<cstdio>
namespace HomeWork
{
	// ����� �������� ������(������) �������� � ��������
	class Test
	{
		// ������ �������� (����� �������� ���� ���� � ��� ������������ (������ ����)
		std::list<Question*>queryList;//����������� ������ Question*- ������ ���������� ������� queryList
		//����� ��������� � �����
		int correct = 0;//����������� ���������� �������
		FILE* testfile;
		Question* readQueryFromFile();//����� ��������� ��������� ������ � ����� ������ Question*
		

	public:
		Test(const char* path);//����������� ������ ���� ��� ���������� ��������
		~Test();
		void exec();//����� ������������ ������� � ����� � ������������ � ��������
		int GetResult(void);//����� ������ ������(noexcept-���������� ����������� �� �����)
		int GetCorrect(void) { return correct; }
		int GetQuery(void) { return queryList.size();}
	};

}