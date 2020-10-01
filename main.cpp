/*
Вариант №14 "Класс Bankomat"
Студент: Коновалов Константин, АВТ-943
*/

#include "Bankomat.h"
#include "Test.h"
#include <iostream>

using std::cout;
using std::cin;

void Testing() { //Тестирование
	Bankomat* bank = new Bankomat("OOO00000", 10000);
	Test test;
	cout << "Test 1: " << test.test_destruct() << "\n";
	cout << "Test 2: " << test.test_id(bank) << "\n";
	cout << "Test 3: " << test.test_get_max(bank) << "\n";
	cout << "Test 4: " << test.test_get_min(bank) << "\n";
	cout << "Test 5: " << test.test_cur_am(bank) << "\n";
	cout << "Test 6: " << test.test_load_money(bank) << "\n";
	cout << "Test 7: " << test.test_take_money(bank) << "\n";
	cout << "Test 8: " << test.test_str_obj(bank) << "\n";
	cout << "\nSuccessful: " << test.success << "/8";
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

int main() {
	Testing();
	Info();
	cin.get();
}