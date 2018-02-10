#pragma once
#include"Question.h"

namespace HomeWork
{
	class Stack
	{
	public:

		Stack();
		Stack(const char*query, const char* ans1, const char* ans2, const char* ans3, short num);
		~Stack();
	public:
		struct Node
		{
			// поле в которой будет храниться данные строки
			char* query;
			char* ans1;
			char* ans2;
			char* ans3;
			short num;
			Node* pNext = nullptr;  // указатеь на такую же структуру
		};

	private:
		Node * pTop = nullptr;
		std::size_t count = 0;
	public:
		void Push( char*query,  char* ans1,  char* ans2,  char* ans3, short num);
		int Pop(void);


		std::size_t Size(void)const noexcept
		{
			return this->count;
		}

		bool Empty(void)const noexcept
		{
			return this->pTop == nullptr;
		}

	};

}