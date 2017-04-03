//msoftcon.h
//ќбъ¤влени¤ функций консольной графики от Lafore
//используютс¤ консольные функции Windows 

#ifndef _INC_WCONSOLE    //ƒеректива провер¤ет включение файла аналогично оператору if(!define)
#define _INC_WCONSOLE    //»м¤ _INC_WCONSOLE выбрано произвольно 
						 //»спользуютс¤ чтобы исключить повторное включение содержимого заголовочных файлов т.к. 
						 //include втупую подставл¤ет всЄ содержимое по месту объ¤влени¤. 
#include <windows.h>     //дл¤ консольных функций Windows Sleep()
#include <conio.h>       //дл¤ kbhit(), getche()
#include <math.h>        //дл¤ sin, cos fabs()

enum fstyle { SOLID_FILL, X_FILL, O_FILL, //—писок возможных заполнений символами, заливок
	LIGHT_FILL, MEDIUM_FILL, DARK_FILL }; 

enum color { //—писок цветавой палитры
   cBLACK=0,     cDARK_BLUE=1,  cDARK_GREEN=2, DARK_CYAN=3, 
   cDARK_RED=4,  cDARK_MAGENTA=5, cBROWN=6,  cLIGHT_GRAY=7,
   cDARK_GRAY=8, cBLUE=9,         cGREEN=10,     cCYAN=11, 
   cRED=12,      cMAGENTA=13,     cYELLOW=14,    cWHITE=15 };
//---------------------------------------------------------
void init_graphics();
void set_color(color fg, color bg = cBLACK); //‘ункци¤ цвета(цвет элемента, цвет заднего фона)
void set_cursor_pos(int x, int y); //‘ункци¤ установки курсора в заданные координаты
void clear_screen(); //‘ункци¤ очистки экрана
void wait(int milliseconds); //‘ункци¤ останавливает выполнение программы на заданное врем¤
void clear_line(); //ќчищаем строку
void draw_rectangle(int left, int top, int right, int bottom); //–исуем пр¤моугольник по заданным пораметрам                    
void draw_circle(int x, int y, int rad); //–исуем круг
void draw_line(int x1, int y1, int x2, int y2); //–исуем линию
void draw_pyramid(int x1, int y1, int height); //–исуем треугольник
void set_fill_style(fstyle); //‘ункци¤ заливки

#endif /* _INC_WCONSOLE */


