#define _CRT_SECURE_NO_WARNINGS
#include "Bankomat.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>

//����������� �������������� ��������� ������������ �������� �����
//������� ����� ����� �� ���
const int Bankomat::MAX_AMOUNT = 10000;

//����������� �������������� ��������� ����������� �������� �����
//������� ����� ����� �� ���
const int Bankomat::MIN_AMOUNT = 10; 

//Bankomat::Bankomat()
//����������� ����������� ��� ������ Bankomat
//������� ������
Bankomat::Bankomat() { 	
	id_number = nullptr;
	current_amount = 0;
}

//Bankomat::Bankomat(const char* id, int _curr_amount)
//����������� ��� ������ Bankomat
//������� ������
//args:
// - const char* id - id ���������, int _curr_amount - ���-�� ����� � ���������
Bankomat::Bankomat(const char* id, int _curr_amount) { //����������� � ����������
	int len = strlen(id);
	id_number = new char[len + 1];
	strcpy(id_number, id);
	current_amount = _curr_amount;
}

//Bankomat::Bankomat(const Bankomat& bank)
//����������� ����������� ������ Bankomat
//�������� �������
//args:
// - const Bankomat& bank - ������ � �������� ��������� �����
Bankomat::Bankomat(const Bankomat& bank) {
	if (bank.id_number) {
		id_number = new char[strlen(bank.id_number) + 1];
		strcpy(id_number, bank.id_number);
	}
	else id_number = (char*)"OOO000000";

	current_amount = bank.current_amount;
}

//Bankomat::~Bankomat()
//���������� ������ Bankomat
//������� ������������ ������
Bankomat::~Bankomat() {
		delete[] id_number;
}

//void Bankomat::SetID(const char* id)
//������ ������� ID
//args:
// - const char* id - ID, ������� ����� ������� �������
void Bankomat::setID(const char* id) {
	int len = strlen(id);
	id_number = new char[len + 1];
	strcpy(id_number, id);
}

//char* Bankomat::GetID()
//�������� ID �������
//return - id ����� �������
char* Bankomat::getID() {
	return id_number;
}

//const int Bankomat::GetMax()
//�������� ������������ ���-�� ����� ��� ������
//return - ����������� ���������� ����� ��� ������
const int Bankomat::getMax() {
	return MAX_AMOUNT;
}

//const int Bankomat::GetMin()
//�������� ����������� ���-�� ����� ��� ������
//return - ����������� ���������� ����� ��� ������
const int Bankomat::getMin() { //�������� ���������� ���������� ����� ��� ������ ��� ��������
	return MIN_AMOUNT;
}

//void Bankomat::SetCurAmoun(int _current_amount)
//������ ���-�� ����� � ���������
//args:
// - int _current_amount - ���������� �����, ������� ����� ��������� ���������
void Bankomat::setCurAmoun(int _current_amount) {
	current_amount = _current_amount; 
}

//int Bankomat::GetCurAmoun()
//������ ���-�� ����� � ���������
//return - ���������� ����� � ���������
int Bankomat::getCurAmoun() { 
	return current_amount; 
}

//void Bankomat::LoadMoney(int money) { 
//�������� ����� � ��������
//args:
// - int money - ������, ������� ����� ������ � ��������
void Bankomat::loadMoney(int money) {
	if (money < MIN_AMOUNT)
		std::cout << "\nYou can't deposit less than the" 
		<< " minimum amount of 100 rubeles.\n";
	else
		current_amount += money;
}

//void Bankomat::TakeMoney(int money) { 
//������ ����� � ���������
//args:
// - int money - ������, ������� ����� ����� � ���������
void Bankomat::takeMoney(int money) {
	if (money < MIN_AMOUNT)
		std::cout << "\nYou can't deposit less than the"
		<< " minimum amount of 10 rubeles.\n";
	else if (money > MAX_AMOUNT)
		std::cout << "\nThe maximum amount("<< MAX_AMOUNT <<") of money has been exceeded.\n";
	else
		current_amount -= money;
}

//void Bankomat::StrObj() { 
//��������� ������������
//return - ���������� � id-������ ��������� � ���-�� ����� � ��
char* Bankomat::strObj() {
	char* id;
	id = getID();

	char buf[16];
	int i = getCurAmoun();
	sprintf(buf, "%d", i);
	const char* money = buf;

	int len = 32;
	char* string = new char[len + 1];
	sprintf(string,"%s %s",  id, money);

	return string;
}