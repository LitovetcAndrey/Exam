#include "stdafx.h"
#include "Stack.h"

namespace HomeWork
{
	Stack::Stack()
	{
	}


	Stack::Stack(const char*query, const char* ans1, const char* ans2, const char* ans3, short num)
	{
		auto p = new Node;
		p->query= query;
		p->ans1= ans1;
		p->ans2=ans2;
		p->ans3=ans3;
		p->num=num;

		if (!this->pTop)
			this->pTop = p;//первый эл стека
		else
		{
			p->pNext = this->pTop;// последующие елементы стека
			this->pTop = p;
		}
		++count;
	}


	Stack::~Stack()
	{
		auto p = this->pTop;// презначение вершины
		while (p)
		{
			this->pTop = p->pNext;
			delete p;
			p = this->pTop;
		}

	}


	void Stack::Push( char* query, char* ans1,  char* ans2,  char* ans3, short num)//поместить
	{
		auto p = new Node;
		p->query = query;
		p->ans1 = ans1;
		p->ans2 = ans2;
		p->ans3 = ans3;
		p->num = num;
		if (!this->pTop)
			this->pTop = p;//первый эл стека
		else
		{
			p->pNext = this->pTop;// последующие елементы стека
			this->pTop = p;
		}
		++count;
	}



	int Stack::Pop(void)//извлечь
	{
		//pTop самый верхний элемент
		if (!this->pTop)
			throw std::runtime_error("Stask is empty");// нет элементов
		auto p = this->pTop;
		this->pTop = p->pNext;
		auto num = p->num;
		auto query= p->query;
		auto ans1= p->ans1;
		auto ans2= p->ans2;
		auto ans3= p->ans3;
		delete p;
		--count;

		return p;
	};
}