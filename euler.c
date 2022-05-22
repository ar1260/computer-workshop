#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Date 20


void N1();
void N2();
void N3();
void N4();
void N5();
void N6();
void N7();
void N8();
void N9();
void N10();
void N12();
void N14();
void N15();
void N11();
int Task_2(char* str);
void Task_3();



int main()
{
	//N1();

	//printf("%d", Task_2("d)i((fhjj)knfke"));


	Task_3();

}

void N1()
{
	int Sum = 0;

	for (int number = 1; number < 1000; number++)
	{
		if (number % 3 == 0 || number % 5 == 0)
			Sum += number;
	}

	printf("%d", Sum);

	return;
}

void N2()
{
	unsigned long long int Sum = 0;

	int element1 = 0;
	int element2 = 1;
	int tmp = 0;

	while (element2 < 4000000)
	{
		if (element2 % 2 == 0)
			Sum += element2;

		tmp = element2;
		element2 = element2 + element1;
		element1 = tmp;
	}

	printf("%llu", Sum);
	return;
}

int Prime_number(unsigned long long int number)
{
	for (unsigned long long int divider = 2; divider < number; ++divider)
	{
		if (number % divider == 0)
			return 0;
	}

	return 1;
}

void N3()
{
	unsigned long long number = 600851475143;
	unsigned long long max_div = 2;

	while (1)
	{
		if (number == 1)
		{
			printf("%llu", max_div);
			return;
		}
		while (number % max_div == 0)
			number = number / max_div;
		++max_div;
	}
	return;
}

int Palindrom(unsigned long long int number)
{
	unsigned long long int number_copy = number;

	int len = 0;
	while (number_copy > 0)
	{
		++len;
		number_copy /= 10;
	}

	int* numbers = (int*)malloc(len * sizeof(int));

	if (!numbers)
	{
		printf("Malloc error/n");
		return 0;
	}

	for (int i = 0; i < len; ++i)
	{
		numbers[i] = number % 10;
		number /= 10;
	}

	for (int i = 0; i < (len / 2); ++i)
	{
		if (numbers[i] != numbers[len - 1 - i])
			return 0;
	}
	return 1;
}

void N4()
{
	int max_palinrom = 0;
	for (int i = 999; i > 99; --i)
	{
		for (int j = 999; j > 99; --j)
		{
			int tmp = i * j;
			if (Palindrom(tmp) && tmp > max_palinrom)
				max_palinrom = tmp;
		}
	}
	printf("%d", max_palinrom);
	return;
}

void N5()
{
	int flag = 0;
	int number = 1;

	while (!flag)
	{
		flag = 1;

		for (int div = 2; div < 21; ++div)
		{
			if (number % div != 0)
			{
				flag = 0;
				break;
			}
		}

		++number;
	}

	printf("%d", number - 1);
	return;
}

void N6()
{
	int sqr_sum = ((1 + 100) / 2) * 100;
	sqr_sum *= sqr_sum;

	int sum_sqr = 0;

	for (int number = 1; number < 100; ++number)
	{
		sum_sqr += number * number;
	}

	printf("%d", abs(sqr_sum - sum_sqr));
	return;
}

void N7()
{
	int prime = 2;
	int i = 1;

	while (i != 10001)
	{
		++prime;

		if (Prime_number(prime))
			++i;
	}

	printf("%d", prime);
	return;
}

void N8()
{
	FILE* f;
	fopen_s(&f, "bignumber.txt", "r");

	if (!f)
	{
		printf("file not open\n");
		return;
	}

	int arr[1000];

	for (int i = 0; i < 1000; ++i)
		arr[i] = 0;

	int i = 0;
	while (!feof(f))
	{
		i++;
		printf("%d ", arr[i]);
	}

	/*unsigned long long int tmp = arr[0] * arr[1] * arr[2] * arr[3] * arr[4] * arr[5] * arr[6] * arr[7] * arr[8] * arr[9] * arr[10] * arr[11] * arr[12];*/
	unsigned long long int tmp = 1;
	for (int i = 0; i < 13; ++i)
		tmp *= arr[i];
	//printf("%llu", tmp);

	unsigned long long int max_m = tmp;

	for (int i = 1; i < 986; ++i)
	{
		tmp = tmp / arr[i - 1] * arr[i + 12];
		if (tmp > max_m)
			max_m = tmp;
	}

	//printf("%llu", max_m);
	return;
}

void N9()
{
	for (int a = 1; a < 1000; ++a)
	{
		for (int b = a + 1; b < 1000; ++b)
		{
			for (int c = b + 1; c < 1000; ++c)

				if ((a + b + c == 1000) && (a * a + b * b == c * c))
				{
					printf("%d", a * b * c);
					return;
				}
		}
	}
}

void N10()
{
	int  sum_of_primes = 0;

	for (int p_number = 2; p_number < 2000000; ++p_number)
	{
		if (Prime_number(p_number) == 1)
			sum_of_primes += p_number;
	}

	printf("%d", sum_of_primes);
	return;
}

void N11()
{
	int array[20][20] = { 8, 2, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 7, 78, 52, 12, 50, 77, 91, 8,
49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 4, 56 ,62 ,0,
81, 49, 31, 73, 55 ,79, 14 ,29 ,93, 71, 40, 67, 53, 88, 30, 3, 49, 13, 36, 65,
52 ,70, 95, 23, 4, 60, 11, 42, 69, 24, 68, 56, 1, 32, 56 ,71, 37, 2, 36, 91,
22, 31, 16, 71, 51, 67, 63, 89 ,41 ,92 ,36, 54, 22, 40, 40, 28, 66, 33, 13, 80,
24, 47, 32, 60, 99 ,3 ,45, 2 ,44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50,
32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70,
67, 26, 20, 68, 2, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21,
24, 55, 58, 5, 66, 73 ,99 ,26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72,
21, 36, 23, 9 ,75, 0, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95
,78, 17 ,53, 28, 22, 75, 31, 67, 15, 94, 3, 80, 04, 62, 16, 14 ,9, 53, 56, 92,
16, 39, 05, 42, 96, 35, 31, 47, 55, 58, 88, 24, 00, 17, 54, 24, 36, 29, 85, 57,
86, 56, 00 ,48, 35, 71, 89, 07, 05, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58,
19, 80, 81 ,68 ,05 ,94 ,47 ,69 ,28, 73, 92, 13, 86, 52, 17, 77, 04, 89 ,55, 40,
04, 52, 8 ,83 ,97, 35, 99, 16, 07, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66,
88, 36, 68, 87, 57, 62 ,20, 72, 03, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69,
04, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8 ,46, 29, 32, 40, 62, 76, 36,
20, 69, 36, 41, 72, 30, 23, 88 ,34 ,62 ,99 ,69, 82, 67, 59, 85, 74, 04, 36, 16,
20, 73, 35, 29, 78, 31, 90, 01, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 05, 54,
01, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33 ,48 ,61, 43, 52, 01, 89, 19, 67, 48 };

	/*for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
			printf("%4d", array[i][j]);
		printf("\n");
	}*/

	long long int max_product = 0;

	long long int down = 1;
	long long int right = 1;
	long long int diag = 1;

	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if (i < 17)
				down = array[i][j] * array[i + 1][j] * array[i + 2][j] * array[i + 3][j];
			if (j < 17)
				right = array[i][j] * array[i][j + 1] * array[i][j + 2] * array[i][j + 3];
			if (i < 17 && j < 17)
				diag = array[i][j] * array[i + 1][j + 1] * array[i + 2][j + 2] * array[i + 3][j + 3];

			max_product = max(max_product, max(down, max(right, diag)));
		}
	}

	printf("%llu", max_product);
	return;
}

int Amount_of_Divisiors(unsigned long long int number) 
{
	int amount = 0;
	for (int div = 1; div <= number; ++div)
	{
		if (number % div == 0)
			++amount;
	}
	return amount;
}

void N12()
{
	unsigned long long int number = 2;

	unsigned long long int traingle_number = 1;

	while (Amount_of_Divisiors(traingle_number) <= 500)
	{
		traingle_number += number;
		++number;
	}

	printf("%llu", traingle_number);
	return;
}

int Sequence(int number)
{
	int count = 1;

	while (number != 1)
	{
		if (number % 2 == 0)
			number /= 2;
		else
			number = 3 * number + 1;

		++count;
	}
	return count;
}

void N14()
{
	int max_len = 0;
	int number = 1;

	while (number < 1000000)
	{
		int s = Sequence(number);
		if (max_len < s)
			max_len = s;
		++number;
	}

	printf("%d", max_len);
	return;
}

void N15()
{
	unsigned long long int array[21][21];

	for (int i = 0; i < 21; ++i)
		array[i][0] = 1;

	for (int j = 0; j < 21; ++j)
		array[0][j] = 1;


	for (int i = 1; i < 21; ++i)
	{
		for (int j = 1; j < 21; ++j)
		{
			array[i][j] = array[i - 1][j] + array[i][j - 1];
		}
	}

	printf("%llu", array[20][20]);
	return;
}

int Task_2(char* str)
{
	char* str_ = (char*)malloc((strlen(str) + 1) * sizeof(char));

	if (!str_)
	{
		printf("malloc error\n");
		return 2;
	}

	strcpy_s(str_, strlen(str) + 1, str);
	str_[strlen(str)] = '\0';

	//printf("%s ", str_);

	for (int i = 0; i < strlen(str); ++i)
	{
		if (str_[i] == '(')
		{
			str_[i] = 0;

			int j = i;

			while (str_[j] != ')' && str_[j] != '\0')
				++j;

			if (str_[j] == ')')
				str_[j] = 0;

			if (str_[i] == '\0')
				return-1;

		}

		if (str_[i] == ')')
			return i;
	}

	return 0;
}

void quickSort(int* numbers, int left, int right)
{
	int pivot;
	int l_hold = left;
	int r_hold = right;
	pivot = numbers[left];
	while (left < right)
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--;

		if (left != right)
		{
			numbers[left] = numbers[right];
			left++;
		}

		while ((numbers[left] <= pivot) && (left < right))
			left++;

		if (left != right)
		{
			numbers[right] = numbers[left];
			right--;
		}
	}
	numbers[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;

	if (left < pivot)
		quickSort(numbers, left, pivot - 1);
	if (right > pivot)
		quickSort(numbers, pivot + 1, right);
}

void Task_3()
{
	FILE* f;
	fopen_s(&f, "date.txt", "r");

	if (!f)
	{
		printf("file not open\n");
		return;
	}

	FILE* g;
	fopen_s(&g, "date_.txt", "w");

	if (!g)
		return;

	/*int size = 0;

	while (!feof(f))
		size++;


	int* array = (int*)malloc(size * sizeof(int));
	if (!array)
		return;

	for (int i = 0; i < size; ++i)
		array[i] = fgetc(f);

	for (int i = 0; i < size; ++i)
	{
		printf("%d ", array[i]);
	}*/

	int array[Date * 10];

	for (int i = 0; i < Date * 10; ++i)
	{
		array[i] = getc(f);
	}

	for (int i = 0; i < Date * 10; ++i)
	{
		printf("%d ", array[i]);
	}

	int arr[Date][10];

	for (int i = 0; i < Date; ++i)
	{
		for (int j = 0; j < 10; ++j)
			arr[i][j] = 400;
	}

	int m = 0;

	for (int i = 0; i < Date; ++i)
	{
		if (array[m] == 32)
			++m;

		for (int j = 0; j < 10; ++j)
		{
			if (array[m] == 48 || array[m] == 49 || array[m] == 50 || array[m] == 51 || array[m] == 52 || array[m] == 53 || array[m] == 54 || array[m] == 55 || array[m] == 56 || array[m] == 57)
			{
				arr[i][j] = array[m] - 48;
				++m;
			}
			else
			{
				if (array[m] == 47)
				{
					arr[i][j] = 20;
					++m;
				}
			}

		}

	}

	int day[Date];

	for (int i = 0; i < Date; ++i)
	{
		if (arr[i][1] != 400)
		{
			day[i] = (arr[i][6] * 1000 + arr[1][7] * 100 + arr[i][8] * 10 + arr[i][9]) * 10000 + (arr[i][3] * 10 + arr[i][4]) * 100 + arr[i][0] * 10 + arr[i][1];

		}
		else
		{
			for (int m = 0; m < 3; ++m)
				day[i] = -1;
		}
	}

	quickSort(day, 0, Date - 1);

	for (int i = Date; i > 0; --i)
	{
		if (day[i] > 1000)
		{
			fprintf(g, "%d", day[i] % 100);
			fpintf(g, "%c", '/');
			day[i] /= 100;
			fprintf(g, "%d", day[i] % 100);
			fpintf(g, "%c", '/');
			day[i] /= 100;
			fprintf(g, "%d", day[i]);
			fprintf(g, "%c", ' ');

		}

	}

	return;
}