#include "stdafx.h"
#include <iostream>
#include <conio.h>  //_getch
#include <cstdlib>  //exit()
#include <cstdio>  //sprintf()
#include <string>  //length()
#include <iomanip> //setw() setwill('_')


const double conv = 0.20833333333333333333333333333333;

class bMoney
{
private:
	enum { SZ = 33 };
	char userEnter[SZ]; //��������: 1. ���� ������������. 2. ��������� �������� ���� �����.
	char parsUserEnter[SZ];
	std::string result;
	long double namberParsUserEnter;
public:
	bMoney():namberParsUserEnter() {}
	bMoney(long double x) : namberParsUserEnter(x*conv) { showResult(); }
	// 1. ---> ���� ������
	void getmoney()
	{
		char temp;
		int i = 0;
		do
		{
			temp = _getch();
			if (temp != 13)
			{
				userEnter[i] = temp;
				std::cout << userEnter[i];
				i++;
			}
			if (i >= SZ) //���� �������� ������ ������� ��������� ���������
			{
				std::cout << "\nERROR ARR_SZ 1" << std::endl;
				system("pause");
				exit(1);
			}

		} while (temp != 13);
		userEnter[i] = '\0'; //��������� ������, ����� ������
		std::cout << std::endl;

		// 2. ---> ������� ����� � ����� �� ��������� ������
		for (int i = 0, z = 0; i < SZ; i++)
		{
			switch (userEnter[i])
			{
			case '0': {parsUserEnter[z] = userEnter[i]; z++; }; break;
			case '1': {parsUserEnter[z] = userEnter[i]; z++; }; break;
			case '2': {parsUserEnter[z] = userEnter[i]; z++; }; break;
			case '3': {parsUserEnter[z] = userEnter[i]; z++; }; break;
			case '4': {parsUserEnter[z] = userEnter[i]; z++; }; break;
			case '5': {parsUserEnter[z] = userEnter[i]; z++; }; break;
			case '6': {parsUserEnter[z] = userEnter[i]; z++; }; break;
			case '7': {parsUserEnter[z] = userEnter[i]; z++; }; break;
			case '8': {parsUserEnter[z] = userEnter[i]; z++; }; break;
			case '9': {parsUserEnter[z] = userEnter[i]; z++; }; break;
			case '.': {parsUserEnter[z] = userEnter[i]; z++; }; break;
			default:
				break;
			}
			if (userEnter[i] == '\0')
				parsUserEnter[z] = '\0';
		}
		
		//std::cout << "!test(char[])parsUserEnter ---> " << parsUserEnter << std::endl; //!test
		// 3. ---> ������� ������ � long double
			namberParsUserEnter = strtold(parsUserEnter, '\0');
			//std::cout << "!test(long double)namberParsUserEnter ---> " << std::fixed << namberParsUserEnter << std::endl; //!test
		
	}

	// 9. --> ����� ����������� �� �����
	void showResult()
	{
		// 5. ---> ������� ���������� ����� � ������
			sprintf_s(userEnter, "%f", namberParsUserEnter);
			//std::cout << "!test(char[])userEnter ---> " << userEnter << std::endl;
			
			// 6. ---> �������������� ������������ ������ � ������ $9'999'999'999'999'990.000000 //29
				char temp[SZ];
				temp[0] = '$';
				temp[1] = '0';
				temp[2] = '\'';
				for (int i = 3, q = 6; i < SZ; i++)
				{
					if (i == 22)
					{
						temp[i] = '.';
						i++;
						for (; i < SZ; i++)
						{
							temp[i] = '0';
						}
						break;
					}
					if (i >= 6 && i % q == 0)
					{

						temp[i] = '\'';
						q += 4;
					}
					else
						temp[i] = '0';
				}
				temp[SZ - 4] = '\0';

				//std::cout << "!test(temp) ---> " << temp << std::endl; //!test

				//���������� �������� ����� �����
				int strLen = 0;

				for (int i = 0; i < SZ; i++) //�������� ������ �������
				{
					if (userEnter[i] != '\0')
						strLen++;
					else
					{
						strLen -= 7;
						//std::cout << "!test(length) ---> " <<  strLen << std::endl; //!test
						break;
					}
				}
				//���������� 0 ����� �������� �����	
				int itemp = ((SZ - strLen) - 7) - 4;
				if (strLen > 3)
					itemp -= strLen / 3;
				//std::cout << "!test(itemp) ---> " << itemp << std::endl; //!test
				//�������� ������ ������ � ������

				strLen += strLen / 3;//������ + ������� '\''

				for (int i = 0, q = 0; i < strLen + 7; i++)
				{
					if (temp[(((SZ - 4) - 7) - strLen) + i] == '\'')
					{
					}
					else
					{
						temp[(((SZ - 4) - 7) - strLen) + i] = userEnter[q];
						q++;
					}
				}
				//std::cout << "!test(temp) ---> " << temp << std::endl; //!test

				// 7. ---> ������� ������ ������� � ������ $9'990.000000
				result = temp;
				if (temp[itemp] == '\'')
					result.erase(1, itemp);
				else
					result.erase(1, itemp - 1);
				//std::cout << "!test(result) ---> " << result << std::endl; //!test
				// 8. ---> ������� ������ ������� � ����� ������� $9'999'999'999'999'990.00 
				for (int i = 0; i < 4; i++)
					result.pop_back();
				//std::cout << "!test(result) ---> " << result << std::endl; //!test
			
		
				std::cout << result;// << std::endl;
	}
	long double res() {
		// 0.2 ---> ������� � ����� � � �������
		if (namberParsUserEnter < conv)
			namberParsUserEnter = 0.0;
		else
			namberParsUserEnter /= conv;
		
		if (namberParsUserEnter > 12.0)
			namberParsUserEnter = namberParsUserEnter / 12.0;
		else
			namberParsUserEnter /= 100;
		return namberParsUserEnter;
	}

/*========================== ��������� ������������� �������� =====================*/

	bMoney operator+(bMoney bm1);  //1
	bMoney operator-(bMoney bm1);  //2
	bMoney operator*(long double); //3
	bMoney operator/(bMoney bm1);  //4
	bMoney operator/(long double); //5
};



bMoney bMoney::operator+(bMoney bm1)
{
	bMoney temp;
	temp.namberParsUserEnter = namberParsUserEnter + bm1.namberParsUserEnter;
	return temp;
}

bMoney bMoney::operator-(bMoney bm1)
{
	bMoney temp;
	temp.namberParsUserEnter = namberParsUserEnter - bm1.namberParsUserEnter;
	return temp;
}

bMoney bMoney::operator*(long double t)
{
	bMoney temp;
	temp.namberParsUserEnter = namberParsUserEnter * t;
	return temp;
}

bMoney bMoney::operator/(bMoney bm1)
{
	bMoney temp;
	temp.namberParsUserEnter = namberParsUserEnter / bm1.namberParsUserEnter;
	return temp;
}

bMoney bMoney::operator/(long double t)
{
	bMoney temp;
	temp.namberParsUserEnter = namberParsUserEnter / t;
	return temp;
}
/*=================================================================================*/