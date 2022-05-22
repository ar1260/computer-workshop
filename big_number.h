#pragma once

/*
* @brief Тип "Большое число"
*/
struct BigNumber
{
	char* number;
	size_t size;
};

/*
* @brief Конструктор
* @param size_ - Размер числа
*/
struct BigNumber* BigNumberContructor(const char* number_);

/*
* @brief Конструктор "Большого числа" из файла
* @param f_ - указатель на файл с числом
*/
struct BigNumber* BigNumberFileContructor(FILE* f_, size_t size_);

/*
* @brief Печать "Большого числа"
* @param obj_ - Указатель на структуру "Большого числа"
*/
void BigNumberPrint(struct BigNumber* obj_);

struct BigNumber* BigNumberSum(const struct BigNum* obj1_, const struct BigNum* obj2_);