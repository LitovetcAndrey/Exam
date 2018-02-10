#pragma once
#include"Question.h"
#include<cstdio>
namespace HomeWork
{
	// будет хранится список(массив) вопросов с ответами
	class Test
	{
		// список вопросов (нужно написать клас лист и его использовать (список лист)
		std::list<Question*>queryList;//двухсвяхный список Question*- массив указателей назовем queryList
		//будем считывать с файла
		int correct = 0;//колличество правильных ответов
		FILE* testfile;
		Question* readQueryFromFile();//будет считывать следующий вопрос с файла вернет Question*
		

	public:
		Test(const char* path);//конструктор укажет путь для считывания вопросов
		~Test();
		void exec();//метод перебирающий вопросы с листа и сравнивающий с ответами
		int GetResult(void);//метод выодит оценку(noexcept-исключения выбрасывать не будет)
		int GetCorrect(void) { return correct; }
		int GetQuery(void) { return queryList.size();}
	};

}