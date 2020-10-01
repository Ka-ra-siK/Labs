#include "Bankomat.h"
#include "Test.h"
#include <iostream>

using std::cout;

//Test::Test()
//����������� �������� 0 ������� � ��������
Test::Test(){
	success = 0;
	fail = 0;
}

//bool Test::test_destruct()
//��������� ����������
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
//��������� ��������� ID
//args:
// - Bankomat* test_bank - ��������� �� ������ ������ Bankomat
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
		cout << "Expected: " << expect << " Real: " << real <<"\n";
		fail++;
		return false;
	}
}

//bool Test::test_get_max(Bankomat* test_bank)
//��������� ��������� max
//args:
// - Bankomat* test_bank - ��������� �� ������ ������ Bankomat
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
//��������� ��������� min
//args:
// - Bankomat* test_bank - ��������� �� ������ ������ Bankomat
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
//��������� ��������� �������� � ��������
//args:
// - Bankomat* test_bank - ��������� �� ������ ������ Bankomat
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
//��������� �������� ����� � �������
//args:
// - Bankomat* test_bank - ��������� �� ������ ������ Bankomat
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
//��������� ������ ����� �� ��������
//args:
// - Bankomat* test_bank - ��������� �� ������ ������ Bankomat
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
//��������� ��������� �������������� ������� 
//args:
// - Bankomat* test_bank - ��������� �� ������ ������ Bankomat
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