/*
Вариант №14 "Класс Bankomat"
Студент: Коновалов Константин, АВТ-943
*/
#ifdef _WIN32
#include "Bankomat.h"
#include "Test.h"
#include "AdressName.h"
#include "Report.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

void testingMainClass() { //Тестирование
	Bankomat bankTest1("00000KKK", 1000);
	Bankomat bankTest2("11111111", 900);
	Test test;
	FILE *file_text, *file_bin, *false_text, *false_bin;
	file_text = fopen("file.txt", "r+");
	file_bin = fopen("file.dat", "rb");
	false_text = fopen("false.tx", "rt");
	false_bin = fopen("false.da", "rb");
	cout << "First tests: " << "\n";
	cout << "Test 1: " << test.test_destruct() << "\n";
	cout << "Test 2: " << test.test_id(&bankTest1) << "\n";
	cout << "Test 3: " << test.test_get_max(&bankTest1) << "\n";
	cout << "Test 4: " << test.test_get_min(&bankTest1) << "\n";
	cout << "Test 5: " << test.test_cur_am(&bankTest1) << "\n";
	cout << "Test 6: " << test.test_load_money(&bankTest1) << "\n";
	cout << "Test 7: " << test.test_take_money(&bankTest1) << "\n";
	cout << "Test 8: " << test.test_str_obj(&bankTest1) << "\n\n";
	
	cout << "Second tests: " << "\n";
	cout << "Test 9 " << test.test_minus(&bankTest2) << "\n";
	cout << "Test 10 " << test.test_less(&bankTest2) << "\n";
	cout << "Test 11 " << test.test_plus(&bankTest2) << "\n";
	cout << "Test 12 " << test.test_more(&bankTest2) << "\n";
	cout << "Test 13 " << test.test_greater_and_equal(&bankTest2) << "\n";
	cout << "Test 14 " << test.test_less_and_equal(&bankTest2) << "\n";
	cout << "Test 15 " << test.test_assignment(&bankTest2) << "\n";
	cout << "Test 16 " << test.test_call_func(&bankTest2) << "\n";
	cout << "Test 17 " << test.test_noLastOperation() << "\n\n";

	cout << "Third tests: " << "\n";
	cout << "Test 18 " << test.test_text(file_text) << "\n";
	cout << "Test 19 " << test.test_bin(file_bin) << "\n";

	cout << "\nSuccessful: " << test.success << "/19";
	cout << "\nFailed: " << test.fail;

}

void Info() { //Строковое представление 
	Bankomat* bank_1 = new Bankomat("AAA111111", 10000);
	Bankomat* bank_2 = new Bankomat("BBB222222", 20000);
	Bankomat* bank_3 = new Bankomat("CCC333333", 30000);

	cout << "\nInfo:";
	cout << "\n\nid-number|money\n";
	cout << bank_1->strObj() << std::endl;
	cout << bank_2->strObj() << std::endl;
	cout << bank_3->strObj();
}

void Exeptions() {
	cout << "\n\nException handling: " << "\n";
	Bankomat bank;
	Bankomat* bank_2 = new Bankomat(NULL, 0);
	bank.setID("012345678901234567890");
	bank.setCurAmoun(bank.getMin() - 1);
	bank.setCurAmoun(bank.getMax() + 1);
	bank.loadMoney(42);
	bank.takeMoney(bank.getMin() - 1);
	bank.takeMoney(bank.getMax() + 1);
	bank_2->strObj();
}

void testingHeirClass() {
	AdressName bank("NSTU", "Lenina", "11111111", 10000);
	time_t now = time(0);
	char* date = ctime(&now);
	Report bank2(NULL, nullptr, "Qwerty", "Marksa", "IDDQD0451", 10000);
	Report bank3(NULL, nullptr, "SberBank", "Lenina", "OOOOO1234", 90000);
	Test test;
	cout << "Test 1: " << test.test_sec_destruct() << "\n";
	cout << "Test 2: " << test.test_adress(&bank) << "\n";
	cout << "Test 3: " << test.test_name(&bank) << "\n";
	cout << "Test 4: " << test.test_date(&bank2, date) << "\n";
	cout << "\nSuccessful: " << test.success2 << "/4";
	cout << "\nFailed: " << test.fail2 << "\n";
	cout << bank2.generateReport(100) << endl;
	Sleep(1000);
	cout << bank3.generateReport(1000) << endl;
}

int main() {
	//testingMainClass();
	//Info();
	//Exeptions();
	testingHeirClass();
	cin.get();
}