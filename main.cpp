/*
Вариант №14 "Класс Bankomat"
Студент: Коновалов Константин, АВТ-943
*/

#include "Bankomat.h"
#include "Test.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void Testing() { //Тестирование
	Bankomat bankTest1("00000KKK", 1000);
	Bankomat bankTest2("11111111", 900);
	Test test;
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
	cout << "Test 18 " << test.test_text() << "\n";
	cout << "Test 19 " << test.test_bin() << "\n";
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

int main() {
	Testing();
	Info();
	cin.get();
}