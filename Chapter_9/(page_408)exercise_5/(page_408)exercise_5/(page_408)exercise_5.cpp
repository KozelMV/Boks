// (page_408)exercise_5.cpp : Defines the entry point for the console application.
// пример написания базы данных сотрудников с использованием наследования
/*
1. Создайте производный класс employee2 от базового класса employee из программы EMPLOY этой главы.
2. Добавьте в новый класс поле compensation типа double  и поле period типа enum для обозначения периода оплаты работы служащего : почасовая, понедельная или помесячная.Для простоты
вы можете изменить классы laborer, manager и scientist так, чтобы они стали производными нового класса employee2.Однако заметим, что во многих случаях создание отдельного класса compensation и трех его производ -
ных классов manager2, scientist2 и laborer2 более соответствовало бы духу
ООП.Затем можно применить множественное наследование и сделать так, чтобы эти три новых класса стали производными класса compensation и первоначальных классов manager, scientist и laborer.Таким путем можно
избежать модификации исходных классов.
*/

#include "stdafx.h"
#include <iostream>

const int LEN = 80;       // максимальная длина имени
class compensation {
private:
double salary;
enum period { na, hWage, wSalary, mSalary };
public:
	compensation() :salary(0.0) {}
	short int entPer;
	void getdata() {
		std::cout << "  Введите оклад: $"; std::cin >> salary;
		std::cout << "\t-периуд(ежедневно(1), еженедельно(2), раз в месяц(3)): ";
		std::cin >> entPer;
}
	void putdata() const {
		std::cout << "\n  Оклад: $" << salary;
		std::cout << " -периуд: ";
		switch (entPer)
		{
		case na: std::cout << "n\a"; break;
		case hWage:	 std::cout << "ежедневно\n";	break;
		case wSalary:std::cout << "еженедельно\n";	 break;
		case mSalary:std::cout << "раз в месяц\n";	break;
		default:
			std::cout << "n\\a\n"; break;
		}
	}
};
class employee            // некий сотрудник
{
private:
	char name[LEN];       // имя сотрудника
	unsigned long number; // номер сотрудника
public:
	void getdata()
	{
		std::cout << "\n  Введите фамилию: "; std::cin >> name;
		std::cout << "  Введите номер: ";     std::cin >> number;
	}
	void putdata() const
	{
		std::cout << "\n  Фамилия: " << name;
		std::cout << "\n  Номер: " << number;
	}
};
///////////////////////////////////////////////////////////
class manager : public employee // менеджер
{
private:
	char title[LEN];      // должность, например вице-президент
	double dues;          // сумма взносов в гольф-клуб
public:
	void getdata()
	{
		employee::getdata();
		std::cout << "  Введите должность: "; std::cin >> title;
		std::cout << "  Введите сумму взносов в гольф-клуб: "; std::cin >> dues;
	}
	void putdata() const
	{
		employee::putdata();
		std::cout << "\n  Должность: " << title;
		std::cout << "\n  Сумма взносов в гольф-клуб: " << dues;
	}
};
class manager2 :public manager, public compensation  {

};
///////////////////////////////////////////////////////////
class scientist : public employee // ученый
{
private:
	int pubs;                     // количество публикаций
public:
	void getdata()
	{
		employee::getdata();
		std::cout << "  Введите количество публикаций: "; std::cin >> pubs;
	}
	void putdata() const
	{
		employee::putdata();
		std::cout << "\n  Количество публикаций: " << pubs;
	}
};
class scientist2 :public compensation, public scientist {

};
///////////////////////////////////////////////////////////
class laborer : public employee   // рабочий
{
};
class laborer2 :public compensation, public laborer {
};
///////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "");
	manager2 m1;
	scientist2 s1;
	laborer2 l1;

	// введем информацию о нескольких сотрудниках
	std::cout << std::endl;
	std::cout << "\nВвод информации о первом менеджере";
	m1.manager::getdata();
	m1.compensation::getdata();


	std::cout << "\nВвод информации о первом ученом";
	s1.scientist::getdata();
	s1.compensation::getdata();
	//
	std::cout << "\nВвод информации о первом рабочем";
	l1.laborer::getdata();
	l1.compensation::getdata();
	// выведем полученную информацию на экран
	std::cout << "\nИнформация о первом менеджере";
	m1.manager::putdata();
	m1.compensation::putdata();
	std::cout << "\nИнформация о первом ученом";
	s1.scientist::putdata();
	s1.compensation::putdata();
	
	std::cout << "\nИнформация о первом рабочем";
	l1.laborer::putdata();
	l1.compensation::putdata();
	
	std::cout << std::endl;
	system("pause");
	return 0;
}

