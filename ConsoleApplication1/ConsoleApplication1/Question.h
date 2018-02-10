#pragma once
#include<iostream>
#include<cstring>
#include <list>
#include<fstream>
#include<stdio.h>

namespace HomeWork
{

//для хранеия вопроса
	class Question
	{
		char* query;
		char* ans1;
		char* ans2;
		char* ans3;
		short num;

	public:
		Question(const char*query, const char* ans1, const char* ans2, const char* ans3, short num);
		~Question();
		bool test(short)noexcept;
		friend std::ostream& operator<<(std::ostream& out, const Question& q);
	};

}