#define _CRT_SECURE_NO_WARNINGS
#include "Bankomat.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>

//Присваиваем статистической константе максимальное значение денег
//которое можно снять за раз
const int Bankomat::MAX_AMOUNT = 10000;

//Присваиваем статистической константе минимальное значение денег
//которое можно снять за раз
const int Bankomat::MIN_AMOUNT = 10; 

//Bankomat::Bankomat()
//Стандартный конструктор для класса Bankomat
//Создает объект
Bankomat::Bankomat() { 	
	id_number = nullptr;
	current_amount = 0;
}

//Bankomat::Bankomat(const char* id, int _curr_amount)
//Конструктор для класса Bankomat
//Создает объект
//args:
// - const char* id - id банкомата, int _curr_amount - кол-во денег в банкомате
Bankomat::Bankomat(const char* id, int _curr_amount) { //Конструктор с параметром
	int len = strlen(id);
	id_number = new char[len + 1];
	strcpy(id_number, id);
	current_amount = _curr_amount;
}

//Bankomat::Bankomat(const Bankomat& bank)
//Конструктор копирования класса Bankomat
//Копирует объекты
//args:
// - const Bankomat& bank - объект с которого снимается копия
Bankomat::Bankomat(const Bankomat& bank) {
	if (bank.id_number) {
		id_number = new char[strlen(bank.id_number) + 1];
		strcpy(id_number, bank.id_number);
	}
	else id_number = (char*)"OOO000000";

	current_amount = bank.current_amount;
}

//Bankomat::~Bankomat()
//Деструктор класса Bankomat
//Удаляет динамическую строку
Bankomat::~Bankomat() {
		delete[] id_number;
}

//void Bankomat::SetID(const char* id)
//Задать стороку ID
//args:
// - const char* id - ID, который нужно вписать объекту
void Bankomat::setID(const char* id) {
	int len = strlen(id);
	id_number = new char[len + 1];
	strcpy(id_number, id);
}

//char* Bankomat::GetID()
//Получить ID объекта
//return - id номер объекта
char* Bankomat::getID() {
	return id_number;
}

//const int Bankomat::GetMax()
//Получить Максимальное кол-во денег для снятия
//return - максимально количество денег для снятия
const int Bankomat::getMax() {
	return MAX_AMOUNT;
}

//const int Bankomat::GetMin()
//Получить Минимальное кол-во денег для снятия
//return - минимальное количество денег для снятия
const int Bankomat::getMin() { //Получить минимально количество денег для снятия или вложения
	return MIN_AMOUNT;
}

//void Bankomat::SetCurAmoun(int _current_amount)
//Задать кол-во денег в банкомате
//args:
// - int _current_amount - количество денег, которые нужно присвоить банкомату
void Bankomat::setCurAmoun(int _current_amount) {
	current_amount = _current_amount; 
}

//int Bankomat::GetCurAmoun()
//Узнать кол-во денег в банкомате
//return - количество денег в банкомате
int Bankomat::getCurAmoun() { 
	return current_amount; 
}

//void Bankomat::LoadMoney(int money) { 
//Загрузка денег в банкомат
//args:
// - int money - Деньги, которые нужно внести в банкомат
void Bankomat::loadMoney(int money) {
	if (money < MIN_AMOUNT)
		std::cout << "\nYou can't deposit less than the" 
		<< " minimum amount of 100 rubeles.\n";
	else
		current_amount += money;
}

//void Bankomat::TakeMoney(int money) { 
//Взятие денег с банкомата
//args:
// - int money - деньги, которые нужно снять с банкомата
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
//Строковое предствление
//return - информация о id-номере банкомата и кол-ве денег в нём
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