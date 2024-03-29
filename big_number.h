#pragma once

/*
* @brief ��� "������� �����"
*/
struct BigNumber
{
	char* number;
	size_t size;
};

/*
* @brief �����������
* @param size_ - ������ �����
*/
struct BigNumber* BigNumberContructor(const char* number_);

/*
* @brief ����������� "�������� �����" �� �����
* @param f_ - ��������� �� ���� � ������
*/
struct BigNumber* BigNumberFileContructor(FILE* f_, size_t size_);

/*
* @brief ������ "�������� �����"
* @param obj_ - ��������� �� ��������� "�������� �����"
*/
void BigNumberPrint(struct BigNumber* obj_);

struct BigNumber* BigNumberSum(const struct BigNum* obj1_, const struct BigNum* obj2_);