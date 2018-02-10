#include "stdafx.h"
#include "Question.h"

namespace HomeWork
{
	Question::Question(const char*query, const char* ans1, const char* ans2, const char* ans3, short num) :num(num)
	{
		this->query = new char[strlen(query) + 1]; //выделяем память под указатели
		this->ans1 = new char[strlen(ans1) + 1];
		this->ans2 = new char[strlen(ans2) + 1];
		this->ans3 = new char[strlen(ans3) + 1];

		strcpy_s(this->query, strlen(query)+1, query);// то что считаем и скопируем в поля класа
		strcpy_s(this->ans1, strlen(ans1)+1, ans1);
		strcpy_s(this->ans2, strlen(ans2)+1 , ans2);
		strcpy_s(this->ans3, strlen(ans3)+1 , ans3);
	}


	Question::~Question()//чистим память 
	{
		delete[] this->query;
		delete[] this->ans1;
		delete[] this->ans2;
		delete[] this->ans3;
	}

	bool Question::test(short variant)noexcept// проверка ответа
	{
		return variant == num; //вернет 1 если истина
	}

	std::ostream& operator<<(std::ostream& out, const Question& q)//оператор вывода слева поток <<  справа наш вопрос 
	{
		out << q.query;
		out << "--------"<<std::endl;
		out << "variant 1. " << q.ans1;
		out << "variant 2. " << q.ans2;
		out << "variant 3. " << q.ans3;
		out << "--------";
		
		return out;
	}
}