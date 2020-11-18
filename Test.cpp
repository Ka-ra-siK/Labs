#include "Test.h"
#include "Bankomat.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include "Functions.h"
using namespace std;

//Test::Test()
//Присваиваем значения 0 успехам и провалам
Test::Test() {
	success = 0;
	fail = 0;
}

//bool Test::test_destruct()
//Тестируем диструктор
//return - true or false
bool Test::test_destruct() {
	Bankomat* bank = new Bankomat("OOO00000", 10000);
	delete bank;
	try {
		if (bank->getID() == (char*)0xDDDDDDDD)
			throw 1;
		else {
			fail++;
			return false;
		}
	}
	catch (int a) {
		success++;
		return true;
	}
}

//bool Test::test_id(Bankomat* test_bank)
//Тестируем написания ID
//args:
// - Bankomat* test_bank - указатель на объект класса Bankomat
//return - true or false
bool Test::test_id(Bankomat* test_bank) {
	test_bank->setID("KKK11111");
	const char* expect = "KKK11111";
	const char* real;
	real = test_bank->getID();

	if (*expect == *real) {
		success++;
		return true;
	}
	else {
		cout << "Expected: " << expect << " Real: " << real << "\n";
		fail++;
		return false;
	}
}

//bool Test::test_get_max(Bankomat* test_bank)
//Тестируем получение max
//args:
// - Bankomat* test_bank - указатель на объект класса Bankomat
//return - true or false
bool Test::test_get_max(Bankomat* test_bank) {
	int expect = 10000;
	int real = test_bank->getMax();
	if (expect == real) {
		success++;
		return true;
	}
	else {
		cout << "Expected: " << expect << " Real: " << real << "\n";
		fail++;
		return false;
	}
}

//bool Test::test_get_min(Bankomat* test_bank) 
//Тестируем получение min
//args:
// - Bankomat* test_bank - указатель на объект класса Bankomat
//return - true or false
bool Test::test_get_min(Bankomat* test_bank) {
	int expect = 10;
	int real = test_bank->getMin();
	if (expect == real) {
		success++;
		return true;
	}
	else {
		cout << "Expected: " << expect << " Real: " << real << "\n";
		fail++;
		return false;
	}
}

//bool Test::test_cur_am(Bankomat* test_bank)
//Тестируем установки значения в банкомат
//args:
// - Bankomat* test_bank - указатель на объект класса Bankomat
//return - true or false
bool Test::test_cur_am(Bankomat* test_bank) {
	test_bank->setCurAmoun(1000);
	int expect = 1000;
	int real = test_bank->getCurAmoun();
	if (expect == real) {
		success++;
		return true;
	}
	else {
		cout << "Expected: " << expect << " Real: " << real << "\n";
		fail++;
		return false;
	}
}

//bool Test::test_load_money(Bankomat* test_bank) 
//Тестируем загрузки денег в автомат
//args:
// - Bankomat* test_bank - указатель на объект класса Bankomat
//return - true or false
bool Test::test_load_money(Bankomat* test_bank) {
	test_bank->setCurAmoun(1000);
	test_bank->loadMoney(234);
	int expect = 1234;
	int real = test_bank->getCurAmoun();
	if (expect == real) {
		success++;
		return true;
	}
	else {
		cout << "Expected: " << expect << " Real: " << real << "\n";
		fail++;
		return false;
	}
}

//bool Test::test_take_money(Bankomat* test_bank)
//Тестируем снятие денег из автомата
//args:
// - Bankomat* test_bank - указатель на объект класса Bankomat
//return - true or false
bool Test::test_take_money(Bankomat* test_bank) {
	test_bank->setCurAmoun(5000);
	test_bank->takeMoney(1000);
	int expect = 4000;
	int real = test_bank->getCurAmoun();
	if (expect == real) {
		success++;
		return true;
	}
	else {
		cout << "Expected: " << expect << " Real: " << real << "\n";
		fail++;
		return false;
	}
}

//bool Test::test_str_obj(Bankomat* test_bank)
//Тестируем строковое предлставление объекта 
//args:
// - Bankomat* test_bank - указатель на объект класса Bankomat
//return - true or false
bool Test::test_str_obj(Bankomat* test_bank) {
	test_bank->setID("KKK11111");
	test_bank->setCurAmoun(1000);
	const char* expect = "KKK11111 1000";
	const char* real;
	real = test_bank->strObj();

	if (*expect == *real) {
		success++;
		return true;
	}
	else {
		cout << "Expected: " << expect << " Real: " << real << "\n";
		fail++;
		return false;
	}
}

//bool Test::test_minus(Bankomat* bank)
//Тестируем перегрузку -= 
//args:
// - Bankomat* test_bank - указатель на объект класса Bankomat
//return - true or false
bool Test::test_minus(Bankomat* bank) {
	int x = 100;
	*bank -= x;
	int actual = bank->getCurAmoun();
	int expected = 800;
	if (actual == expected) {
		success++;
		return true;
	}
	else {
		cout << "Expected: " << expected << "Actual: " << actual << endl;
		fail++;
		return false;
	}
}
//bool Test::test_less(Bankomat* bank)
//Тестируем перегрузку <
//args:
// - Bankomat* test_bank - указатель на объект класса Bankomat
//return - true or false
bool Test::test_less(Bankomat* bank) {

	int x = 100000000;
	if (*bank < x) {
		success++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

//bool Test::test_plus(Bankomat* bank)
//Тестируем перегрузку +=
//args:
// - Bankomat* test_bank - указатель на объект класса Bankomat
//return - true or false
bool Test::test_plus(Bankomat* bank) {
	int x = 100;
	*bank += x;
	int actual = bank->getCurAmoun();
	int expected = 900;
	if (actual == expected) {
		success++;
		return true;
	}
	else {
		cout << "Expected: " << expected << "Actual: " << actual << endl;
		fail++;
		return false;
	}
}
//bool Test::test_more(Bankomat* bank)
//Тестируем перегрузку >
//args:
// - Bankomat* test_bank - указатель на объект класса Bankomat
//return - true or false
bool Test::test_more(Bankomat* bank) {

	int x = 100;
	if (*bank > x) {
		success++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

//bool Test::test_greater_and_equal(Bankomat* bank)
//Тестируем перегрузку >=
//args:
// - Bankomat* test_bank - указатель на объект класса Bankomat
//return - true or false
bool Test::test_greater_and_equal(Bankomat* bank) {
	int x = 900; 
	if (*bank >= x) {
		success++;
		return true;
	}
	else {
		fail++;
		return false;
	}

}
//bool Test::test_less_and_equal(Bankomat* bank)
//Тестируем перегрузку =<
//args:
// - Bankomat* test_bank - указатель на объект класса Bankomat
//return - true or false
bool Test::test_less_and_equal(Bankomat* bank) {
	int x = 900; // x = current amount of money. Tests case of equity

	if (*bank <= x) {
		success++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}
//bool Test::test_assignment(Bankomat* bank)
//Тестируем перегрузку =
//args:
// - Bankomat* test_bank - указатель на объект класса Bankomat
//return - true or false
bool Test::test_assignment(Bankomat* bank) {
	Bankomat* bank2 = new Bankomat("33333333", 20);
	*bank2 = *bank;
	if ((bank->getCurAmoun() == bank2->getCurAmoun() && bank->getMax() == bank2->getMax())
		&& (strcmp(bank->getID(), bank2->getID()) == 0)) {
		delete bank2;
		success++;
		return true;
	}
	else {
		cout << "Actual" << bank2->getID() << "Expected" << bank->getID() << endl;
		cout << "Actual" << bank2->getCurAmoun() << "Expected" << bank->getCurAmoun() << endl;
		cout << "Actual" << bank2->getCurAmoun() << "Expected" << bank->getCurAmoun() << endl;
		delete bank2;

		fail++;
		return false;
	}
}
//bool Test::test_call_func(Bankomat* bank)
//Тестируем перегрузку функции
//args:
// - Bankomat* test_bank - указатель на объект класса Bankomat
//return - true or false
bool Test::test_call_func(Bankomat* bank) {

	*bank += 4000;
	if (strcmp(bank->operator()(), "111111114000") == 0) {
		success++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

//bool Test::test_noLastOperation()
//Тестируем перегрузку noLastOperation
//args:
// - Bankomat* test_bank - указатель на объект класса Bankomat
//return - true or false
bool Test::test_noLastOperation(){
	Bankomat bank; // there is NULL lastOp in object bank
	if (strcmp(bank(), "No last operations found") == 0) {
		success++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

//bool Test::test_text()
//Тестируем input and output в Txt файле
//return - true or false
bool Test::test_text() {
	ofstream out("file.txt");
	try {
		if (!out) throw 1;
	}
	catch (int a) {
		cout << "Failed to open file" << endl;
		return false;
	}
	int N = rand() % 15 + 1;
	Bankomat* bankW = new Bankomat[N];
	for (int i = 0; i < N; ++i)
	{
		bankW[i] = Bankomat("1111111", rand());
		bankW[i].toTxt(out);
	}
	out.close();

	Bankomat* bankR = new Bankomat;
	ifstream in("file.txt");
	try {
		if (!in) throw 1;
	}
	catch (int a) {
		cout << "Failed to open file" << endl;
		return false;
	}
	bankR = bankR->outTxt(in);
	for (int i = 0; i < N; i++) {
		if (strcmp(bankW[i].getID(), bankR[i].getID()) != 0
			|| bankW[i].getCurAmoun() != bankR[i].getCurAmoun()) {
			cout << "Expected: " << bankW[i].getID() << " " << bankW[i].getCurAmoun() <<
				" Actual: " << bankR[i].getID() << " " << bankR[i].getCurAmoun() << endl;
			break;
			delete[] bankR;
			delete[] bankW;
			in.close();
			fail++;
			return false;
		}

	}
	in.close();
	delete[] bankR;
	delete[] bankW;
	success++;
	return true;
}

//bool Test::test_bin()
//Тестируем input and output в Bin файле
//return - true or false
bool Test::test_bin(){
	fstream out("file.dat", ios::binary | ios::out);
	try {
		if (!out) throw 1;
	}
	catch (int a) {
		cout << "Failed to open file" << endl;
		return false;
	}
	int N = rand() % 15 + 5;
	Bankomat* bankW = new Bankomat[N];
	for (int i = 0; i < N; ++i)
	{
		bankW[i] = Bankomat("11111118", rand());
		bankW[i].toBin(out);
	}
	out.close();
	Bankomat* bankR = new Bankomat;
	fstream in("file.dat", ios::binary | ios::in);
	try {
		if (!in) throw 1;
	}
	catch (int a) {
		cout << "Failed to open file" << endl;
		return false;
	}
	bankR = bankR->outBin(in);
	for (int i = 0; i < N; i++) {
		if (strcmp(bankW[i].getID(), bankR[i].getID()) != 0
			|| bankW[i].getCurAmoun() != bankR[i].getCurAmoun()) {
			cout << "Expected: " << bankW[i].getID() << " " << bankW[i].getCurAmoun() <<
				" Actual: " << bankR[i].getID() << " " << bankR[i].getCurAmoun() << endl;
			break;
			delete[] bankR;
			delete[] bankW;
			in.close();
			fail++;
			return false;
		}

	}
	in.close();
	success++;
	return true;
}