#include <stdio.h.>
#include <string.h>
#include <stdlib.h>

void EX_1(const char* str_)
{
	int first_1 = 0;
	int last_1 = 0;
	int first_2 = 0;
	int last_2 = 0;
	int i = 0;

	while (str_[i] == ' ')
	{
		++first_1;
		++i;
	}

	while (str_[i] != ' ')
	{
		++last_1;
		++i;
	}

	--last_1;

	while (str_[i] != '\0')
	{
		++i;
		++last_2;
	}

	++last_2;

	while (str_[i] != ' ')
		--i;

	first_2 = i + 1;

	int first_word = last_1 - first_1 + 1 ;
	int last_word = last_2 - first_2;

	char Fw[64];

	for (int i = 0; i < first_word; ++i)
		Fw[i] = str_[i];

	Fw[i - 3] = '\0';

	char Lw[64];

	for (int i = 0; i < last_word; ++i)
		Lw[i] = str_[ strlen(str_) - last_word + 1];

	Lw[i] = '\0';

	int len = strlen(str_) + 1;

	char* New_string = (char*)malloc(len * sizeof(char));

	for (int i = 0; i < len; ++i)
		New_string[i] = str_[i];
	
	for (int i = 0; i < first_word; ++i)
		New_string[i] = Lw[i];

	for (int i = len - 1 - last_word; i < len - 1; ++i)
		New_string[i] = Fw[i - len + 1 + last_word];

	printf("%s", New_string);

	return;
}

struct Human {
	char Surname[20];
	char Name[20];
	char Patronymic[20];

	char Sex;// "f" or "m"

	char Post[40];

	char Date[11];
};

void EX_2(struct Human* arr)
{
	for (int i = 0; i < 4; ++i)
	{
		if (arr[i].Post == "engineer")
		{
			int c = 0;
			int date = 0;

			while (*arr[i].Date)
			{
				for (int i = 0; c < 2; ++i)
				{
					if (arr[i].Date == ".")
						++c;
				}
				date = date * 10 + atoi(arr[i].Date);
			}

			if (arr[i].Sex == 'm' && 2021 - date > 65)
				printf("%s %s %s", arr[i].Surname, arr[i].Name, arr[i].Patronymic);
			if (arr[i].Sex == 'f' && 2021 - date > 60)
				printf("%s %s %s", arr[i].Surname, arr[i].Name, arr[i].Patronymic);
		}
	}
	return;
}

void EX_3()
{
	FILE* F;
	errno_t err = fopen_s(&F, "f.txt", "r");

	if (err)
	{
		perror("file F");
		return;
	}

	FILE* G;
	errno_t err_ = fopen_s(&G, "g.txt", "w+");

	if (err_)
	{
		perror("file G");
		return;
	}
	int count = 0;

	for (char tmp = 0; fscanf_s(F, "%d", &tmp) != EOF;)
	{
		if (tmp == ' ')
		{
			++count;
		}

		if((count +1)%4 != 0)
			fscanf_s(F, "%c", G);
	}
	return;
}

int main()
{
	struct Human arr[4];

	arr[1] = {
		"Xyzin",
		"Marat",
		"Rustemovich",

		'm',
		"student",
		"12.09.2003",
	};

	arr[2] = {
		"Herrington",
		"Billy",
		" ",

		'm',
		"boss of this gym",
		"14.07.1969",
	};

	arr[3] = {
		"1",
		" ",
		" ",

		'm',
		"engineer",
		"12.03.1955",
	};

	arr[4] = {
		"2",
		" ",
		" ",

		'f',
		"engineer",
		"4.07.1959"
	};

	//EX_2(arr);

	EX_3();

	return 0;
}