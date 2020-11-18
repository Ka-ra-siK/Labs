#define _CRT_SECURE_NO_WARNINGS
#include "Bankomat.h"
#include "Functions.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <sstream> 
using namespace std;
//Ïðèñâàèâàåì ñòàòèñòè÷åñêîé êîíñòàíòå ìàêñèìàëüíîå çíà÷åíèå äåíåã
//êîòîðîå ìîæíî ñíÿòü çà ðàç
const int Bankomat::MAX_AMOUNT = 10000;

//Ïðèñâàèâàåì ñòàòèñòè÷åñêîé êîíñòàíòå ìèíèìàëüíîå çíà÷åíèå äåíåã
//êîòîðîå ìîæíî ñíÿòü çà ðàç
const int Bankomat::MIN_AMOUNT = 10;

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
//Ñòàíäàðòíûé êîíñòðóêòîð äëÿ êëàññà Bankomat
//Ñîçäàåò îáúåêò
Bankomat::Bankomat() {
	id_number = nullptr;
	current_amount = 0;
	lastOp = nullptr;
}

//Bankomat::Bankomat(const char* id, int _curr_amount)
//Êîíñòðóêòîð äëÿ êëàññà Bankomat
//Ñîçäàåò îáúåêò
//args:
// - const char* id - id áàíêîìàòà, int _curr_amount - êîë-âî äåíåã â áàíêîìàòå
Bankomat::Bankomat(const char* id, int _curr_amount) { //Êîíñòðóêòîð ñ ïàðàìåòðîì
	int len = strlen(id);
	id_number = new char[len + 1];
	strcpy(id_number, id);
	current_amount = _curr_amount;
	lastOp = NULL;
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

//Bankomat::Bankomat(const Bankomat& bank)
//Êîíñòðóêòîð êîïèðîâàíèÿ êëàññà Bankomat
//Êîïèðóåò îáúåêòû
//args:
// - const Bankomat& bank - îáúåêò ñ êîòîðîãî ñíèìàåòñÿ êîïèÿ
/*Bankomat::Bankomat(const Bankomat& bank) {
	if (bank.id_number) {
		id_number = new char[strlen(bank.id_number) + 1];
		strcpy(id_number, bank.id_number);
	}
	else id_number = (char*)"OOO000000";

	current_amount = bank.current_amount;
}*/

//Bankomat::~Bankomat()
//Äåñòðóêòîð êëàññà Bankomat
//Óäàëÿåò äèíàìè÷åñêóþ ñòðîêó
Bankomat::~Bankomat() {
	delete[] id_number;
}

//void Bankomat::SetID(const char* id)
//Çàäàòü ñòîðîêó ID
//args:
// - const char* id - ID, êîòîðûé íóæíî âïèñàòü îáúåêòó
void Bankomat::setID(const char* id) {
	int len = strlen(id);
	id_number = new char[len + 1];
	strcpy(id_number, id);
}

//char* Bankomat::GetID()
//Ïîëó÷èòü ID îáúåêòà
//return - id íîìåð îáúåêòà
char* Bankomat::getID() {
	return id_number;
}

//const int Bankomat::GetMax()
//Ïîëó÷èòü Ìàêñèìàëüíîå êîë-âî äåíåã äëÿ ñíÿòèÿ
//return - ìàêñèìàëüíî êîëè÷åñòâî äåíåã äëÿ ñíÿòèÿ
const int Bankomat::getMax() {
	return MAX_AMOUNT;
}

//const int Bankomat::GetMin()
//Ïîëó÷èòü Ìèíèìàëüíîå êîë-âî äåíåã äëÿ ñíÿòèÿ
//return - ìèíèìàëüíîå êîëè÷åñòâî äåíåã äëÿ ñíÿòèÿ
const int Bankomat::getMin() { //Ïîëó÷èòü ìèíèìàëüíî êîëè÷åñòâî äåíåã äëÿ ñíÿòèÿ èëè âëîæåíèÿ
	return MIN_AMOUNT;
}

//void Bankomat::SetCurAmoun(int _current_amount)
//Çàäàòü êîë-âî äåíåã â áàíêîìàòå
//args:
// - int _current_amount - êîëè÷åñòâî äåíåã, êîòîðûå íóæíî ïðèñâîèòü áàíêîìàòó
void Bankomat::setCurAmoun(int _current_amount) {
	current_amount = _current_amount;
}

//int Bankomat::GetCurAmoun()
//Óçíàòü êîë-âî äåíåã â áàíêîìàòå
//return - êîëè÷åñòâî äåíåã â áàíêîìàòå
int Bankomat::getCurAmoun() {
	return current_amount;
}

//void Bankomat::LoadMoney(int money) { 
//Çàãðóçêà äåíåã â áàíêîìàò
//args:
// - int money - Äåíüãè, êîòîðûå íóæíî âíåñòè â áàíêîìàò
void Bankomat::loadMoney(int money) {
	if (money < MIN_AMOUNT)
		std::cout << "\nYou can't deposit less than the"
		<< " minimum amount of 100 rubeles.\n";
	else {
		current_amount += money;
		delete[] lastOp;
		setLastOp(money);
	}
}

//void Bankomat::TakeMoney(int money) { 
//Âçÿòèå äåíåã ñ áàíêîìàòà
//args:
// - int money - äåíüãè, êîòîðûå íóæíî ñíÿòü ñ áàíêîìàòà
void Bankomat::takeMoney(int money) {
	if (money < MIN_AMOUNT)
		std::cout << "\nYou can't deposit less than the"
		<< " minimum amount of 10 rubeles.\n";
	else if (money > MAX_AMOUNT)
		std::cout << "\nThe maximum amount(" << MAX_AMOUNT << ") of money has been exceeded.\n";
	else {
		current_amount -= money;
		delete[] lastOp;
		money *= -1;
		setLastOp(money);
	}
}

//void Bankomat::StrObj() { 
//Ñòðîêîâîå ïðåäñòâëåíèå
//return - èíôîðìàöèÿ î id-íîìåðå áàíêîìàòà è êîë-âå äåíåã â í¸ì
char* Bankomat::strObj() {
	char* id;
	id = getID();

	char buf[16];
	int i = getCurAmoun();
	sprintf(buf, "%d", i);
	const char* money = buf;

	int len = 32;
	char* string = new char[len + 1];
	sprintf(string, "%s %s", id, money);

	return string;
}

//void Bankomat::setLastOp(int money)
//Ïîñëåäíÿÿ îïåðàöèÿ
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
//Ïåðåãðóçêà îïåðàòîðà -=
//args: 
// - int value - äåíüãè

void Bankomat::operator -= (int value) {

	takeMoney(value);
}

//void Bankomat::operator +=(int amount)
//Ïåðåãðóçêà îïåðàòîðà += 
//args: 
// - int value - äåíüãè

void Bankomat::operator += (int value) {

	loadMoney(value);
}

//bool operator > (Bankomat& bank, int value)
//Ïåðåãðóçêà îïåðàòîðà >
//args: 
//-Bankomat * test_bank - óêàçàòåëü íà îáúåêò êëàññà Bankomat
// - int value - äåíüãè
// return ðàçíèöó ìåæäó òåêóùåé ñóììîé è ñðàâíèâàåìîé ñóììîé

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
//Ïåðåãðóçêà îïåðàòîðà < 
//args: 
// - int value - äåíüãè
//return ðàçíèöó ìåæäó òåêóùåé ñóììîé è ñðàâíèâàåìîé ñóììîé

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
//Ïåðåãðóçêà îïåðàòîðà >=
//args: 
// - int value - äåíüãè
// ââîäèò ðàçíèöó ìåæäó òåêóùåé ñóììîé è ñðàâíèâàåìîé ñóììîé èëè ââîäèò ñîîáùåíèå î òîì, ÷òî îáå ðàâíû

bool Bankomat::operator >= (int value) {
	if (this->current_amount == value) {

		std::cout << "ATM has: " << this->current_amount << std::endl;
		return true;
	}

	else return *this > (value);
}

//bool Bankomat::operator <= (int value)
//Ïåðåãðóçêà îïåðàòîðà <= 
//args: 
// - int value - äåíüãè
// ââîäèò ðàçíèöó ìåæäó òåêóùåé ñóììîé è ñðàâíèâàåìîé ñóììîé èëè ââîäèò ñîîáùåíèå î òîì, ÷òî îáå ðàâíû
bool Bankomat::operator <= (int value) {

	if (this->current_amount == value) {

		std::cout << "ATM has: " << this->current_amount << std::endl;
		return true;
	}

	else return this->operator<(value);
}


// Bankomat& Bankomat::operator = (const Bankomat& bank)
//Ïåðåãðóçêà îïåðàòîðà =
//args: 
// - const Bankomat& bank - îáúåêò äëÿ îïåðàòîðà =
// returns êîïèÿ îáúåêòà
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
//Ïåðåãðóçêà îïåðàòîðà ()
//args: 
// returns ïîñëåäíÿÿ îïåðàöèÿ â ôîðìàòå: ID, äåíüãè âíåñåíû èëè ñíÿòû
char* Bankomat::operator() () const {
	if (lastOp == NULL) {
		char* noLastOp = (char*)"No last operations found";
		return noLastOp;
	}
	else return lastOp;
}

// istream & operator >> (istream & is, Bankomat & bank)
//Ïåðåãðóçêà îïåðàòîðà >> 
// args:
// istream& is -- ïîòîê, Bankomat& bank -- áàíê
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
//Ïåðåãðóçêà îïåðàòîðà  << operator
// args:
// istream& os -- ïîòîê, Bankomat& bank -- áàíê
//return ïîòîê
ostream& operator << (ostream& os, Bankomat& bank) {
	os << bank.id_number << " " << bank.current_amount << " " << bank.MAX_AMOUNT;
	return os;
}
//void Bankomat::toTxt(ofstream& out)
//ââîä èíôîðìàöèè â txt
// args:
// oftream& out -- txt
void Bankomat::toTxt(ofstream& out) {
	out << *this << '\n';
}

//void Bankomat::toBin(fstream& out)
//ââîä èíôîðìàöèè â bin
// args:
// fstream& out -- bin ôàéë
void Bankomat::toBin(fstream& out) {
	int lenId = strlen(id_number);
	out.write((char*)&lenId, sizeof(lenId));
	out.write(id_number, strlen(id_number));
	out.write((char*)&current_amount, sizeof(current_amount));
	out.write((char*)&MAX_AMOUNT, sizeof(MAX_AMOUNT));
}

//Bankomat* Bankomat::outTxt(ifstream& in)
//âûâîä èíôîðìàöèè èç txt
// args:
// iftream& in -- txt
//return áàíêîâñêèé ìàññèâ ñî âñåìè äàííûìè èç txt
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
//âûâîä èíôîðìàöèè èç bim
//args:
// fstream& in -- bin
//returns áàíêîâñêèé ìàññèâ ñî âñåìè äàííûìè èç bin
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
