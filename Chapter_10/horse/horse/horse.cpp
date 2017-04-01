// horse.cpp : Defines the entry point for the console application.
// модель лошадиных скачек (Коментируем каждую строчку)
#include "stdafx.h"
#include "\Users\Максим\Google Диск\Обучение\Ништячки C++\msoftcon.h" //Подключаем консольную графику
#include <iostream> // Для ввода\вывода
#include <cstdlib>	// Для random()
#include <ctime>	// Для time()
#include <Windows.h>

using namespace std;
const int CPF = 5; //Количество столбцов в час
const int maxHorses = 7; //Максимальное количество лошадей
class track; //Для видимости в классе horse
///////////////////////////////////////////////////////////
class horse
{
private:
	const track* ptrTrack;  //Указатель на track
	const int horse_number; //Номер лошади
	float finish_time; //Время финиширования лошади
	float distance_run; //Пройденая дистанция
public:
	horse(const int n, const track* ptrT) : //Создаем лошадь
		horse_number(n), //Номер
		ptrTrack(ptrT),	 //Её расположение по Y
		distance_run(0.0) //Её расположение по Х
	{ }
	~horse() //Диструктор лошади
	{ }
	void display_horse(const float elapsed_time); //Показывае лошадь
}; //Конец класса лошади
///////////////////////////////////////////////////////////
class track
{
private:
	horse* hArray[maxHorses]; //Масив лошадей
	int total_horses; //Количество лошадей
	int horse_count;  //Количество созданных лошадей
	const float track_length; //Длина трека
	float elapsed_time; //Время начала гонки
public:
	track(float lenT, int nH); //Конструктор трека
	~track(); //Деструктор
	void display_track(); //Показать трек
	void run(); //Начать гонку
	float get_track_len() const; //Возвратить длину трека
}; //Конец класса track
///////////////////////////////////////////////////////////
void horse::display_horse(float elapsed_time) //Отрисовываем лошадь и номер
{
/*msoftcon.h*/	set_cursor_pos(1 + int(distance_run * CPF), 2 + horse_number * 2);
/*msoftcon.h*/	set_color(static_cast<color>(cBLUE + horse_number));
	char horse_char = '0' + static_cast<char>(horse_number);
	_putch(' '); _putch('\xDB'); _putch(horse_char); _putch('\xDB');
	if (distance_run < ptrTrack->get_track_len() + 1.0 / CPF)
	{
		if (rand() % 3)
			distance_run += 0.2F;
		finish_time = elapsed_time;
	}
	else
	{
		int mins = int(finish_time) / 60;
		int secs = int(finish_time) - mins * 60;
		cout << " Время =" << mins << ":" << secs;
	}
}
///////////////////////////////////////////////////////////
track::track(float lenT, int nH) :
	track_length(lenT),
	total_horses(nH),
	horse_count(0),
	elapsed_time(0.0)
{
	init_graphics();
	total_horses = (total_horses > maxHorses) ? maxHorses : total_horses;
	for (int j = 0; j < total_horses; j++)
		hArray[j] = new horse(horse_count++, this);

	time_t aTime;
	srand(static_cast<unsigned>(time(&aTime)));
	display_track();
}
///////////////////////////////////////////////////////////
track::~track()
{
	for (int j = 0; j < total_horses; j++)
		delete hArray[j];
}
///////////////////////////////////////////////////////////
void track::display_track()
{
	clear_screen();

	for (int f = 0; f <= track_length; f++)
		for (int r = 1; r <= total_horses * 2 + 1; r++)
		{
			set_cursor_pos(f * CPF + 5, r);
			if (f == 0 || f == track_length)
				cout << '\xDE';
			else
				cout << '\xB3';
		}
}
///////////////////////////////////////////////////////////
void track::run()

{
	while (!_kbhit())
	{
		elapsed_time += 1.75;

		for (int j = 0; j < total_horses; j++)
			hArray[j]->display_horse(elapsed_time);
		wait(500);
	}
	_getch();
	cout << endl;
}
///////////////////////////////////////////////////////////
float track::get_track_len() const
{
	return track_length;
}
///////////////////////////////////////////////////////////
int main()
{
	//
	
	float length;
	int total;
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	cout << "\nВведите длину дистанции (от 1 до 12): ";
	cin >> length;
	cout << "\nВведите количество лошадей (от 1 до 7): ";
	cin >> total;
	SetConsoleOutputCP(866); // установка кодовой страницы win-cp 866 в поток вывода
	track theTrack(length, total);
	theTrack.run();

	return 0;
}
