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

				printf("%llu\n", i); // � ����� �������� ������ ��� ���� ���� �� ��������� ((( ���� � ������� �������� ����� ��������

			}
	}
	printf("������������ ������� �������� ����� %llu ����� %llu", E,max);

	return 0;
} 


//�������� ���� ��� �����