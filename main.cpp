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
#include <stack>
#include <map>
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
	cout << bank_1->toString() << std::endl;
	cout << bank_2->toString() << std::endl;
	cout << bank_3->toString();
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
	bank_2->toString();
}

void testingHeirClass() {
	Test test;
	cout << "Test 1 " << test.test_setters() << "\n";
	cout << "Test 2 " << test.test_withdrawR_money_withdraws() << "\n";
	cout << "Test 3 " << test.test_withdrawR_arrays_incr() << "\n";
	cout << "\nSuccessful: " << test.success2 << "/3";
	cout << "\nFailed: " << test.fail2 << "\n";
}

void testingPolymorh() {
	Test test;
	cout << "Test 1 " << test.test_polymorh() << endl;
	cout << "Test 2 " << test.test_tree_create_test() << endl;
	cout << "Test 3 " << test.test_delete_node_with_children() << endl;
	cout << "Test 4 " << test.test_find_none_null() << endl;
	cout << "Test 5 " << test.test_find_null() << endl;
	cout << "Successful: " << test.success3 << "/" << "5" << endl;
	cout << "Failed: " << test.fail3 << endl;
}

void stackTest() { // Стек
	cout << "Stack input" << endl;
	stack<int> test;
	int size = 1000000;
	int i = 0;
	int before = clock();
	while (i != size) {
		test.push(size);
		size--;
	}
	cout << "Time:" << clock() - before << endl;
	cout << "Stack delete" << endl;
	before = clock();
	while (!test.empty()) {
		test.pop();
	}
	cout << "Time:" << clock() - before << endl;
	cout << "Stack Bank input" << endl;
	stack<Bankomat> testBank;
	int sizeBank = 1000000;
	int ii = 0;
	before = clock();
	while (ii != sizeBank) {
		testBank.push(Bankomat("1111111", sizeBank));
		sizeBank--;
	}
	cout << "Time:" << clock() - before << endl;
	cout << "Stack Bank delete" << endl;
	before = clock();
	while (!testBank.empty()) {
		testBank.pop();
	}
	cout << "Time:" << clock() - before << endl;
}

void multiMapTest() { //Словарь с дубликатами
	multimap<int, int> map;
	int before = clock();
	cout << "Multimap insert" << endl;
	std::multimap<int, int>::const_iterator itt = map.begin();
	for (int i = 0; i < 100000; i++)
	{
		map.insert(itt, pair<int, int>(i, rand()));
	}
	cout << "time: " << clock() - before << endl;
	cout << "Multimap find" << endl;
	int value = 1234;
	before = clock();
	std::multimap<int, int>::const_iterator found = map.find(value);
	cout << found->second << endl;
	cout << "Time " << clock() - before << endl;
	cout << "Multimap delete" << endl;
	before = clock();
	for (int i = 0; i < 100000; i++)
	{
		map.erase(i);
	}
	cout << "Time " << clock() - before << endl;
	multimap<int, Bankomat> mapBank;
	before = clock();
	
	cout << "Multimap Bank insert" << endl;
	std::multimap<int, Bankomat>::iterator it = mapBank.begin();
	for (int i = 0; i < 10000; i++)
	{
		Bankomat bank("111111111", rand());
		mapBank.insert(it, pair<int, Bankomat>(i, bank));
	}
	cout << "time: " << clock() - before << endl;
	
	cout << "MultimapBank find" << endl;
	value = 1234;
	before = clock();
	std::multimap<int, Bankomat>::iterator foundBank = mapBank.find(value);
	cout << foundBank->second << endl;
	cout << "Time " << clock() - before << endl;
	cout << "Multimap delete" << endl;
	before = clock();
	for (int i = 0; i < 100000; i++)
	{
		mapBank.erase(i);
	}
	cout << "Time " << clock() - before << endl;
}

void testingTemp() {
	cout << "\n\nStack" << endl;
	stackTest();
	cout << "MultiMap" << endl;
	multiMapTest();
	cout << "\n\nEnd";
}

int main() {
	//testingMainClass();
	//Info();
	//Exeptions();
	//testingHeirClass(); //Lab 4
	testingPolymorh(); //Lab 5
	//testingTemp(); //Lab 8
	cin.get();
}