#define _CRT_SECURE_NO_WARNINGS
#include "Bankomat.h"
#include "Functions.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <sstream> 
using namespace std;
//Присваиваем статистической константе максимальное значение денег
//которое можно снять за раз
const int Bankomat::MAX_AMOUNT = 10000;

//Присваиваем статистической константе минимальное значение денег
//которое можно снять за раз
const int Bankomat::MIN_AMOUNT = 100;

//int diff(int x, int y)
	//Calculates difference betwen current amount of money in ATM and compared amount 
	//Returns absolute value of x and y
	//required for avoiding repetition of code in comparison overload function
	//args: 
	// - int x, int y - args for difference calculation

int diff(int x, int y)
{
	return abs(x - y);
}

char* intToChar(int num) {

	int arrSize = 0;
	int numCpy = num;
	while (numCpy != 0) {
		numCpy /= 10;
		arrSize++;
	}
	int i = arrSize - 1;
	char* str = new char[arrSize + 1];
	str[arrSize] = '\0';
	while (num != 0) {
		str[i] = num % 10 + '0';
		num /= 10;
		i--;
	}
	return str;
}

//Bankomat::Bankomat()
//Стандартный конструктор для класса Bankomat
//Создает объект
Bankomat::Bankomat() {
	id_number = nullptr;
	current_amount = 0;
	lastOp = nullptr;
}

//Bankomat::Bankomat(const char* id, int _curr_amount)
//Конструктор для класса Bankomat
//Создает объект
//args:
// - const char* id - id банкомата, int _curr_amount - кол-во денег в банкомате
Bankomat::Bankomat(const char* id, int _curr_amount) { //Конструктор с параметром
	try{
		if (id == NULL || _curr_amount == 0) throw 1;
		int len = strlen(id);
		id_number = new char[len + 1];
		strcpy(id_number, id);
		current_amount = _curr_amount;
		lastOp = NULL;
	}
	catch (int a){
		//cout << "Invalid number of parameters" << endl;
	}
}

Bankomat::Bankomat(const Bankomat& bank) {

	if (bank.id_number) {
		id_number = new char[strlen(bank.id_number) + 1];
		strcpy(id_number, bank.id_number);
	}
	else id_number = (char*)"11111111";
	lastOp = bank.lastOp;
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
	try{
		int len = strlen(id);
		if(len >= 10) throw 1;
		id_number = new char[len + 1];
		strcpy(id_number, id);
	}
	catch (int a){
		cout << "Number of characters exceeded" << endl;
	}
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
	try{
		if (_current_amount < MIN_AMOUNT || _current_amount > MAX_AMOUNT) throw 1;
		current_amount = _current_amount; 
	}
	catch (int a){
		cout << "Invalid value" << endl;
	}
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
	try{
		if (money < MIN_AMOUNT) throw 1;
		current_amount += money;
		delete[] lastOp;
		setLastOp(money);
	}
	catch (int a){
		cout << "You can't deposit less than the"
			<< " minimum amount of 100 rubeles." << endl;
	}
}

//void Bankomat::TakeMoney(int money) { 
//Взятие денег с банкомата
//args:
// - int money - деньги, которые нужно снять с банкомата
void Bankomat::takeMoney(int money) {
	try {
		if (money < MIN_AMOUNT || money > MAX_AMOUNT) throw 1;
		current_amount -= money;
		delete[] lastOp;
		money *= -1;
		setLastOp(money);
	}
	catch (int a) {
		cout << "You can't take this amount of money" << endl;
	}
}

//void Bankomat::toString() { 
//Строковое предствление
//return - информация о id-номере банкомата и кол-ве денег в нём
char* Bankomat::toString() {
	try{
		int N = 32;
		char* str = new char[N];
		int sizeId = strlen(id_number);
		int sizeAmount = strlen(intToCharArr(current_amount));
		int sizeMaxAmount = strlen(intToCharArr(MAX_AMOUNT));
		memcpy(str, id_number, sizeId);
		memcpy(str + sizeId, intToCharArr(current_amount), sizeAmount);
		memcpy(str + sizeId + sizeAmount, intToCharArr(MAX_AMOUNT), sizeMaxAmount);
		str[sizeId + sizeAmount + sizeMaxAmount] = '\0';
		return str;
	}
	catch (int a){
		cout << "Cannot be represented in a string representation" << endl;
	}
}

//void Bankomat::setLastOp(int money)
//Последняя операция
void Bankomat::setLastOp(int money) {
	int N = 32;
	this->lastOp = new char[N];
	int sizeId = strlen(id_number);
	int sizeAmount = strlen(intToChar(money));
	memcpy(this->lastOp, id_number, sizeId);
	if (money >= 0) {
		memcpy(this->lastOp + sizeId, intToChar(money), sizeAmount);
		this->lastOp[sizeId + sizeAmount] = '\0';
	}
	else {
		memcpy(this->lastOp + sizeId, "-", 1); 
		memcpy(this->lastOp + sizeId + 1, intToChar(abs(money)), sizeAmount);
		this->lastOp[sizeId + sizeAmount + 1] = '\0';
	}
}

//void Bankomat::operator -=(int amount)
//Перегрузка оператора -=
//args: 
// - int value - деньги

void Bankomat::operator -= (int value) {
	takeMoney(value);
}

//void Bankomat::operator +=(int amount)
//Перегрузка оператора += 
//args: 
// - int value - деньги

void Bankomat::operator += (int value) {
	loadMoney(value);
}

//bool operator > (Bankomat& bank, int value)
//Перегрузка оператора >
//args: 
//-Bankomat * test_bank - указатель на объект класса Bankomat
// - int value - деньги
// return разницу между текущей суммой и сравниваемой суммой

bool operator > (Bankomat& bank, int value) {

	if (bank.current_amount > value) {
		std::cout << "The ATM has more money than they ask for, the difference is:  " << diff(bank.current_amount, value) << std::endl;
		return true;
	}
	else {
		std::cout << "The ATM has less money than they ask for, the difference is:  " << diff(bank.current_amount, value) << std::endl;
		return false;
	}

}

//void Bankomat::operator <(int value)
//Перегрузка оператора < 
//args: 
// - int value - деньги
//return разницу между текущей суммой и сравниваемой суммой

bool Bankomat::operator < (int value) {

	if (this->current_amount < value) {
		std::cout << "The ATM has less money than they ask for, the difference is: " << diff(this->current_amount, value) << std::endl;
		return true;
	}
	else {
		std::cout << "The ATM has more money than they ask for, the difference is:  " << diff(this->current_amount, value) << std::endl;
		return false;
	}
}

//void Bankomat::operator >= (int value)
//Перегрузка оператора >=
//args: 
// - int value - деньги
// вводит разницу между текущей суммой и сравниваемой суммой или вводит сообщение о том, что обе равны

bool Bankomat::operator >= (int value) {
	if (this->current_amount == value) {

		std::cout << "ATM has: " << this->current_amount << std::endl;
		return true;
	}

	else return *this > (value);
}

//bool Bankomat::operator <= (int value)
//Перегрузка оператора <= 
//args: 
// - int value - деньги
// вводит разницу между текущей суммой и сравниваемой суммой или вводит сообщение о том, что обе равны
bool Bankomat::operator <= (int value) {

	if (this->current_amount == value) {

		std::cout << "ATM has: " << this->current_amount << std::endl;
		return true;
	}

	else return this->operator<(value);
}

// Bankomat& Bankomat::operator = (const Bankomat& bank)
//Перегрузка оператора =
//args: 
// - const Bankomat& bank - объект для оператора =
// returns копия объекта
Bankomat& Bankomat::operator = (const Bankomat& bank) {

	if (&bank == this) {
		return *this;
	}
	if (bank.id_number) {
		id_number = new char[strlen(bank.id_number) + 1];
		strcpy(id_number, bank.id_number);
	}
	else id_number = (char*)"1111111";
	current_amount = bank.current_amount;
	return *this;
}

//char* Bankomat::operator() ()
//Перегрузка оператора ()
//args: 
// returns последняя операция в формате: ID, деньги внесены или сняты
char* Bankomat::operator() () const {
	if (lastOp == NULL) {
		char* noLastOp = (char*)"No last operations found";
		return noLastOp;
	}
	else return lastOp;
}

// istream & operator >> (istream & is, Bankomat & bank)
//Перегрузка оператора >> 
// args:
// istream& is -- поток, Bankomat& bank -- банк
//returns stream
istream& operator >> (istream& is, Bankomat& bank) {

	if (bank.id_number != NULL) {
		delete[] bank.id_number;
	}

	bank.id_number = new char[16];
	is >> bank.id_number >> bank.current_amount; // MAX_AMOUNT is const, can`t be written
	return is;
}
//istream& operator << (istream& os, Bankomat& bank)
//Перегрузка оператора  << operator
// args:
// istream& os -- поток, Bankomat& bank -- банк
//return поток
ostream& operator << (ostream& os, Bankomat& bank) {
	os << bank.id_number << " " << bank.current_amount << " " << bank.MAX_AMOUNT;
	return os;
}
//void Bankomat::toTxt(ofstream& out)
//ввод информации в txt
// args:
// oftream& out -- txt
void Bankomat::toTxt(ofstream& out) {
	out << *this << '\n';
}

//void Bankomat::toBin(fstream& out)
//ввод информации в bin
// args:
// fstream& out -- bin файл
void Bankomat::toBin(fstream& out) {
	int lenId = strlen(id_number);
	out.write((char*)&lenId, sizeof(lenId));
	out.write(id_number, strlen(id_number));
	out.write((char*)&current_amount, sizeof(current_amount));
	out.write((char*)&MAX_AMOUNT, sizeof(MAX_AMOUNT));
}

//Bankomat* Bankomat::outTxt(ifstream& in)
//вывод информации из txt
// args:
// iftream& in -- txt
//return банковский массив со всеми данными из txt
Bankomat* Bankomat::outTxt(ifstream& in) {
	Bankomat* bank = new Bankomat;
	int N = lineAmount(in);
	bank = new Bankomat[N];
	for (int i = 0; i < N; i++) {
		in >> bank[i];
		in.seekg(sizeof(bank->getMax()) + 2, ios::cur);
	}
	return bank;
}

//Bankomat* Bankomat::outBin(fstream& in)
//вывод информации из bim
//args:
// fstream& in -- bin
//returns банковский массив со всеми данными из bin
Bankomat* Bankomat::outBin(fstream& in) {
	char* lenId = new char[2];
	int lenIDArr = 2;
	lenId[1] = '\0';
	int fileSz = fileSize(in) / (sizeof(Bankomat) + lenIDArr * sizeof(char*));
	Bankomat* bank = new Bankomat[fileSz];
	for (int i = 0; i < fileSz; ++i) {
		in.read(lenId, sizeof(lenId));
		int strSize = lenId[0] - '0';
		char* memblock = new char[strSize];
		in.read(memblock, strSize);
		memblock[strSize] = '\0';
		in.read((char*)&bank[i].current_amount, sizeof(current_amount));
		in.seekg(sizeof(MAX_AMOUNT), ios::cur);
		bank[i].id_number = memblock;
	}
	return bank;
}