// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"Question.h"
#include"Test.h"
#include<iostream>
#include<string>
#include<iostream>
#include<fstream>
#include<ctime>


using namespace HomeWork;
int main()
{
	try
	{
		
		const char* Path = "Resalt.txt";
		time_t seconds = time(NULL);
		tm* timeinfo = localtime(&seconds);
		std::cout << "Current Datatime:" << asctime(timeinfo) << std::endl;
		std::string name;
		std::cout << "Enter you surname and group: " ;
	
		std::getline(std::cin, name);//строки с пробелами 
		system("cls");
		
		Test t("1.txt");
		t.exec();
		system("cls");
		std::cout << "-------------" << std::endl;
		std::cout << "Total :" << t.GetQuery() << std::endl;
		std::cout << "Right :" << t.GetCorrect() << std::endl;
		std::cout << "Rezult :" << t.GetResult() <<" whis 12"<< std::endl;
		std::cout << "The end" << std::endl;

		std::ofstream app(Path, std::ofstream::app);
		app << name;
		app << "   Rezult " << t.GetResult();
		app << "   Current Datatime:" << asctime(timeinfo);//запись в поток
		app.close();
		
	
	
	}
	catch (const std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Error" << std::endl;
	}
	 

    return 0;
}

