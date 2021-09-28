#include <stdio.h>
#include "function.h"

#include <locale.h>

int main()
{

	setlocale(LC_ALL, "Russian");

	unsigned long long E = 600851475143;

	unsigned long long max = 0;

	for (unsigned long long i = 1; i <= E; ++i)
	{
		if (E % i == 0)

			if (Number(i) == 0)
			{
				max = i;

				printf("%llu\n", i); // с таким огромным числом мой ноут явно не справится ((( хотя с числами поменьше вроде работает

			}
	}
	printf("максимальный простой делитель числа %llu равен %llu", E,max);

	return 0;
} 


//работать года два будет