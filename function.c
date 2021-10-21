#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "function.h"

 /*     ДЗ на 1-й модуль    */

void EX_1()
{
	int x = 0;
	int a = 0;
	int c = 0;

	printf("введите числа\n");

	scanf_s("%d%d%d", &x, &a, &c);

	float ccos = 0;
	float ssqrt = 0;
	float L_1 = 0;
	float arctg = 0;
	float L_2 = 0;
	int d_abs = 0;
	int aabs = 0;
	float L = 0;

	ccos = cos(pow(x, 2) * pow(a, 5));
	ssqrt = sqrt(exp(x) - pow(ccos, 4));
	arctg = atan(a - pow(x, 5));
	L_1 = ssqrt + pow(arctg, 4);
	d_abs = a + x * pow(c, 4);
	aabs = abs(d_abs);
	L_2 = exp(1) * sqrt(aabs);
	L = L_1 / L_2;

	printf("ответ: %f", L);

	return;
}

void EX_2()
{
	float t = 0;
	float S = 0;

	printf("введите время\n");

	scanf_s("%f", &t);

	S = 3 * pow(t, 2) - 6 * t;
	
	printf("скорость в момент времени равна %f", S);

	return;
}

void EX_3()
{
	float a = 0;
	float b = 0;
	float c = 0;

	float x_1 = 0;
	float x_2 = 0;

	printf("введите a, b и c\n");

	scanf_s("%f%f%f", &a, &b, &c);

	if (a == 0)
	{
		printf("a не должна быть равна 0");

			return;
	}

	float D = 0;

	D = pow(b, 2) - 4 * a * c;

	if (D == 0)
	{
		x_1 = (-b) / (2 * a);

		printf("ответ: %f", x_1);

		return;

	}
	if (D < 0)
		printf("нет действительных корней");

	if (D > 0)
	{
		x_1 = (-b - sqrt(D)) / (2 * a);

		x_2 = (-b + sqrt(D)) / (2 * a);

		printf("корни уравнения: %f, %f", x_1, x_2);

		return;
	}

}

void EX_4()
{
	int code = 0;
	int s = 0;
	float S = 0;

	printf("введите код города\n");

	scanf_s("%d", &code);

	switch (code)
	{
		case 48: s = 15; break;

		case 44: s = 18; break;

		case 46: s = 13; break;

		case 45: s = 11; break;

		default: 
			printf("вы ввели неправильное значение кода города\n");
				return;
	}
	float t = 0;

	printf("введите время разговора в минутах\n");

	scanf_s("%f", &t);

	if (t < 0)
	{
		printf("введено неправильное значение времени\n");

		return;
	}

	S = s * t;

	printf("Стоимость разговора равна %f", S);

	return;
}

void EX_5()
{
	printf("четырехзначные числа Армстронга:\n");

	for (int a_1 = 1; a_1 < 10; ++a_1)
	{
		for (int a_2 = 0; a_2 < 10; ++a_2)
		{
			for (int a_3 = 0; a_3 < 10; ++a_3)
			{
				for (int a_4 = 0; a_4 < 10; ++a_4)
				{
					int a = a_1 * 1000 + a_2 * 100 + a_3 * 10 + a_4;

					if (pow(a_1, 4) + pow(a_2, 4) + pow(a_3, 4) + pow(a_4, 4) == a)

						printf("%d ", a);
				}
			}
		}
	}

	return;
}

void EX_6()
{

	int n = 0;

	printf("введите размер массива (длину двоичной записи числа)\n");

	scanf_s("%d", &n);

	int* arr = (int*)malloc(n * sizeof(int));

	if (!arr)
	{
		printf("Malloc error!\n");
		return;
	}

	printf("введите число\n");

	int number = 0;

	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &arr[i]);
		
		if ((arr[i] != 0) && (arr[i] != 1))
		{
			printf("введено неправильное число");
			return;
		}

		number = number * 2 + arr[i];
	}

	free(arr);

	printf("%d", number);

	return;

}

void EX_7()
{
	int I = 0;
	int J = 0;

	printf("ввдите размер матрицы\n");

	scanf_s("%d%d", &I, &J);

	int* L = (int*)malloc(I * J * sizeof(int));

	if (!L)
	{
		printf("Malloc error!\n");
		return;
	}

	srand(time(NULL));

	for (int i = 0; i < I * J; ++i)
		L[i] = rand() % 21 - 10;

	for (int n = 0; n < I; ++n)
	{
		for (int m = 0; m < J; ++m)
		{
			printf("%d ",- L[n * J + m] * 3);
		}

		printf("\n");
	}

	free(L);

	return;
}




