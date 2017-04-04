// (page_471)exercise_2.cpp : Defines the entry point for the console application.
/*
X	1.Используйте класс String из примера NEWSTR этой главы. 
	2.Добавьте к нему метод upit(), который будет переводить символы строки в верхний регистр.
--> 3.Вы можете использовать библиотечную функцию toupper(), которая принимает отдельный символ в качестве аргумента и возвращает символ, пере-
веденный в верхний регистр (если это необходимо). Эта функция использует заголовочный файл Cctype. 
	4.Добавьте в функцию main() необходимые строки для тестирования метода upit().
*/

#include "stdafx.h"
#include <iostream>
#include <cctype> //upit()
#include <cstring>     // для strcpy(), и т.д.


///////////////////////////////////////////////////////////

class String
{
private:
	char* str;                         // указатель на строку
public:
	String(char* s)                    // конструктор с одним параметром
	{
		int length = strlen(s);        // вычисляем длину строки
		str = new char[length + 1];    // выделяем необходимую память
		strcpy(str,s);                // копируем строку
	}
	~String()                          // деструктор
	{
		std::cout << "Deleting the string\n";
		delete[] str;                  // освобождаем память
	}
	void upit() {
		for (int i = 0; i < strlen(str); i++)
			*(str + i) = toupper(*(str+i));
	}
	void display()                     // покажем строку на экране
	{
		std::cout << str << std::endl;
	}
};
///////////////////////////////////////////////////////////


int main()
{
	String testString("test 123 TEST");

	testString.upit();
	testString.display();

	system("pause");
    return 0;
}

