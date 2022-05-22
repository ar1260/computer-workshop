
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "big_number.h"

struct BigNumber* Enter()
{
	FILE* f;

	fopen_s(&f, "number.txt", "r");

	if (!f)
	{
		printf("Malloc error\n");
		return NULL;
	}

}

struct BigNumber* BigNumberContructor(const char* number_)
{
	struct BigNumber* obj = malloc(sizeof(struct BigNumber));
	if (!obj)
	{
		printf("BigNumber memory error!\n");
		return NULL;
	}

	obj->number = malloc(strlen(number_) * sizeof(char));
	if (!obj->number)
	{
		printf("obj_->number memory error!\n");

		free(obj);
		return NULL;
	}

	obj->size = strlen(number_);

	obj->number[0] = 0;
	for (size_t i = 1; i < strlen(number_); ++i)
		obj->number[i] = number_[i];

	return obj;
}

struct BigNumber* BigNumberFileContructor(FILE* f_, size_t size_)
{
	struct BigNumber* obj = BigNumberContructor(size_);
	if (!obj)
		return NULL;

	char digit = 0;

	for (size_t i = 0; (i < size_); ++i)
	{
		if (fscanf_s(f_, "%c", &digit, 1) == EOF)
			break;

		obj->number[i] = digit - 48;
	}

	return obj;
}

void BigNumberPrint(struct BigNumber* obj_)
{
	if (!obj_)
	{
		printf("obj_ is NULL!\n");
		return;
	}

	for (size_t i = 0; i < obj_->size; ++i)
	{
		if (obj_->number[i] == -1)
			break;

		printf("%i", obj_->number[i]);
	}

	printf("\n");
}


struct BigNumber* BigNumberFileContructor_1(FILE* f_, size_t size_)
{
	struct BigNumber* obj = BigNumberContructor(size_);
	if (!obj)
		return NULL;

	

	char digit = 0;

	for (size_t i = 0; obj->number[i] != '+'; ++i)
		obj->number[i] = digit - 48;

	return obj;
}

