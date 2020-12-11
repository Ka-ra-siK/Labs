#include "Test.h"
#include "Bankomat.h"
#include "AdressName.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include "Functions.h"
#include "Tree.h"
#include "TemplClass.h"
using namespace std;

//Test::Test()
//Присваиваем значения 0 успехам и провалам
Test::Test() {
	success = 0;
	success2 = 0;
	success3 = 0;
	fail = 0;
	fail2 = 0;
	fail3 = 0;
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
	int expect = 100;
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
	real = test_bank->toString();

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
bool Test::test_text(FILE *file) {
	ofstream out(file);
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
bool Test::test_bin(FILE* file){
	fstream out(file);//, ios::binary | ios::out);
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

//bool Test::test_setters()
//Тестируем сеттеры в child классе
//return - true or false
bool Test::test_setters() {
	const char* newBankName = "ALPHA";
	const char* newAdr = "Nemirovicha-Danchenko";
	AdressName bankTest("MARX-20", "SBER", "11111111", 120);
	bankTest.setName(newBankName);
	bankTest.setAdress(newAdr);
	if (strcmp(bankTest.getAdress(), newAdr) == 0 && strcmp(bankTest.getName(), newBankName) == 0) {
		success2++;
		return true;
	}
	else {
		cout << "Expected: " << newAdr << " " << newBankName << endl;
		cout << "Actual: " << bankTest.getAdress() << bankTest.getName() << endl;
		fail++;
		return false;
	}
}

//bool Test::test_withdrawR_money_withdraws()
//Тестирование снятия денег
//return - true or false
bool Test::test_withdrawR_money_withdraws() {
	Bankomat bankTest("1111111", 400);
	AdressName bankLocTest("Pushkina-36", "Tinkoff", "11111111", 400);
	Report recTest(bankLocTest, bankTest);
	int expected = 300;
	recTest.withdrawR(bankTest, 100);
	if (expected == bankTest.getCurAmoun()) {
		success2++;
		return true;
	}
	else {
		fail++;
		return false;
	}
}

//bool Test::test_withdrawR_arrays_incr()
//Тестирование увеличения размера массива с датой
//return - true or false
bool Test::test_withdrawR_arrays_incr() {
	Bankomat bankTest("1111111", 4000);
	AdressName bankLocTest("Pushkina-36", "Tinkoff", "11111111", 4000);
	Report recTest(bankLocTest, bankTest);
	for (int i = 200; i <= 210; i++) {
		recTest.withdrawR(bankTest, i);
	}
	if (recTest.getHistRec() > 2) {
		cout << "Recipe made successfully" << endl;
		cout << "Info: " << endl;
		recTest.showHist();
		success2++;
		return true;
	}
	else {
		cout << recTest.getHistRec() << endl;
		cout << recTest.getHistAmout() << endl;
		cout << "Recipe error " << endl;
		cout << "Total size of arrays: " << recTest.getHistAmout() << endl;
		cout << "Dates written: " << recTest.getHistRec() << endl;
		recTest.showHist();
		fail++;
		return false;
	}
}

/*Lab 5*/

//bool Test::test_polymorh()
//Тестирование полиморфизма
//return - true or false
bool Test::test_polymorh() {
	Bankomat* objects[4];
	AdressName bankTemp("MARX-20 ", "SBER ", "BBBBBBBB", 200);
	Bankomat bankTemp2("DDDDDDDD", 999);
	objects[0] = new Bankomat("AAAAAAAA", 100);
	objects[1] = new AdressName("MARX-20 ", "SBER ", "CCCCCCCCC", 400);
	objects[2] = new Bankomat(*objects[0]);
	objects[3] = new AdressName(bankTemp, bankTemp2);
	int count = 4;
	const char* expected[4];
	expected[0] = "ID:AAAAAAAA Money:100 Max:10000";
	expected[1] = " Bank: SBER  Location: MARX-20 ID:CCCCCCCCC Money:400 Max:10000";
	expected[2] = "ID:AAAAAAAA Money:100 Max:10000";
	expected[3] = " Bank: SBER  Location: MARX-20 ID:DDDDDDDD Money:999 Max:10000";
	for (int i = 0; i < 4; i++) {
		if (strcmp(objects[i]->toString(), expected[i]) != 0)
		{
			cout << "---------Expected------------" << endl;
			cout << expected[i] << endl;
			cout << "-------------Actual:---------" << endl;
			cout << objects[i]->toString() << endl;
			cout << "----------------------------" << endl;
			count++;
		}
		count--;
	}
	if (count == 0) {
		success3++;
		return true;
	}

	else {
		fail3++;
		return false;
	}
}

//bool Test::test_tree_create_test()
//Тестирование создание дерева
//return - true or false
bool Test::test_tree_create_test() {
	const int N = 5;
	Bankomat* objects[N];
	AdressName bankTemp("MARX-20 ", "SBER ", "BBBBBBBB", 200);
	Bankomat bankTemp2("DDDDDDDD", 999);
	objects[0] = new Bankomat("AAAAAAAA", 100);
	objects[1] = new AdressName("MARX-20 ", "SBER ", "CCCCCCCCC", 400);
	objects[2] = new Bankomat(*objects[0]);
	objects[3] = new Report(bankTemp, bankTemp2, 10, 20);
	objects[4] = new AdressName(bankTemp, bankTemp2);
	BinTree t;
	for (int i = 0; i < N; i++) {
		t.addBank(objects[i]);
	}
	if (t.getRoot() == nullptr) {
		cout << endl;
		fail3++;
		return false;
	}
	else {
		success3++;
		return true;
	}
}

//bool Test::test_delete_node_with_children()
//Тестирование удаления узла с дочерними элементами
//return - true or false
bool Test::test_delete_node_with_children() {
	const int N = 5;
	Bankomat* objects[N];
	AdressName bankTemp("MARX-20 ", "SBER ", "BBBBBBBB", 200);
	Bankomat bankTemp2("DDDDDDDD", 999);
	objects[0] = new Bankomat("AAAAAAAA", 323);
	objects[1] = new AdressName("MARX-20 ", "SBER ", "CCCCCCCCC", 400);
	objects[2] = new Bankomat("7654321L", 100);
	objects[3] = new Report(bankTemp, bankTemp2, 10, 20);
	objects[4] = new Bankomat("1234567L", 100);
	BinTree t;
	for (int i = 0; i < N; i++) {
		t.addBank(objects[i]);
	}
	node* d = t.removeBank(objects[1]);
	BinTree tt = BinTree(d);
	if (tt.findBank(objects[1]) != nullptr) {
		cout << "Found object that must be deleted" << endl;
		fail3++;
		return false;
	}
	else {
		success3++;
		return true;

	}
}

//bool Test::test_find_none_null()
//Тестирование поиск
//return - true or false
bool Test::test_find_none_null() {
	const int N = 5;
	Bankomat* objects[N];
	AdressName bankTemp("Lenina ", "SberBank ", "BBBBBBBB", 200);
	Bankomat bankTemp2("DDDDDDDD", 999);
	objects[0] = new Bankomat("AAAAAAAA", 323);
	objects[1] = new AdressName("Lenina ", "SberBank ", "CCCCCCCCC", 400);
	objects[2] = new Bankomat("7654321L", 100);
	objects[3] = new Report(bankTemp, bankTemp2, 10, 20);
	objects[4] = new Bankomat("1234567L", 100);
	BinTree t;
	for (int i = 0; i < N; i++) {
		t.addBank(objects[i]);
	}
	node* d = t.findBank(objects[1]);
	const char* expected = " Bank: SberBank  Location: Lenina ID:CCCCCCCCC Money:400 Max:10000";
	if (strcmp(d->bank->toString(), expected) == 0) {
		cout << "Found: " << endl << d->bank->toString() << endl;
		success3++;
		return true;
	}
	else {
		cout << "Found: " << d->bank->toString() << endl;
		cout << "But not" << expected << endl;
		fail3++;
		return false;
	}

}

//bool Test::test_find_null()
//Тестирование поиск
//return - true or false
bool Test::test_find_null(){
	const int N = 5;
	Bankomat* objects[N];
	AdressName bankTemp("MARX-20 ", "SBER ", "BBBBBBBB", 200);
	Bankomat bankTemp2("DDDDDDDD", 999);
	objects[0] = new Bankomat("AAAAAAAA", 323);
	objects[1] = new AdressName("MARX-20 ", "SBER ", "CCCCCCCCC", 400);
	objects[2] = new Bankomat("7654321L", 100);
	objects[3] = new Report(bankTemp, bankTemp2, 10, 20);
	objects[4] = new Bankomat("1234567L", 100);
	Bankomat* failedObj = new Bankomat("12345678", 777);
	BinTree t;
	for (int i = 0; i < N; i++) {
		t.addBank(objects[i]);
	}
	node* d = t.findBank(failedObj);
	if (d == nullptr) {
		cout << "Not found like it had to be" << endl;
		success3++;
		return true;
	}
	else {
		fail3++;
		return false;
	}
}

//Lab_7

//bool Test::test_template_tree_create_test()
//Тестирование создание дерева
//return - true or false
bool Test::test_template_tree_create_test() {
	const int N = 5;
	Bankomat* objects[N];
	AdressName bankTemp("MARX-20 ", "SBER ", "BBBBBBBB", 200);
	Bankomat bankTemp2("DDDDDDDD", 999);
	objects[0] = new Bankomat("AAAAAAAA", 100);
	objects[1] = new AdressName("MARX-20 ", "SBER ", "CCCCCCCCC", 400);
	objects[2] = new Bankomat(*objects[0]);
	objects[3] = new Report(bankTemp, bankTemp2, 10, 20);
	objects[4] = new AdressName(bankTemp, bankTemp2);
	BinaryTree<Bankomat*> t;
	for (int i = 0; i < N; i++) {
		t.add(objects[i]);
		if (t.lookup(objects[i]) == false) {
			cout << endl;
			fail3++;
			return false;
		}
	}
	success3++;
	return true;
}

//bool Test::test_template_find()
//Тестирование поиск
//return - true or false
bool Test::test_template_find() {
	const int N = 5;
	Bankomat* objects[N];
	AdressName bankTemp("MARX-20 ", "SBER ", "BBBBBBBB", 200);
	Bankomat bankTemp2("DDDDDDDD", 999);
	objects[0] = new Bankomat("AAAAAAAA", 100);
	objects[1] = new AdressName("MARX-20 ", "SBER ", "CCCCCCCCC", 400);
	objects[2] = new Bankomat(*objects[0]);
	objects[3] = new Report(bankTemp, bankTemp2, 10, 20);
	objects[4] = new AdressName(bankTemp, bankTemp2);
	BinaryTree<Bankomat*> t;
	for (int i = 0; i < N; i++) {
		t.add(objects[i]);
		if (t.lookup(objects[i]) == false) {
			cout << endl;
			fail3++;
			return false;
		}
	}
	success3++;
	return true;
}

//bool Test::test_template_delete_node_with_children()
//Тестирование удаление node
//return - true or false
bool Test::test_template_delete_node_with_children() {
	const int N = 5;
	Bankomat* objects[N];
	AdressName bankTemp("MARX-20 ", "SBER ", "BBBBBBBB", 200);
	Bankomat bankTemp2("DDDDDDDD", 999);
	objects[0] = new Bankomat("AAAAAAAA", 100);
	objects[1] = new Bankomat("AAAAAAAA", 100);
	objects[2] = new Bankomat(*objects[0]);
	objects[3] = new Report(bankTemp, bankTemp2, 10, 20);
	objects[4] = new AdressName(bankTemp, bankTemp2);
	BinaryTree<Bankomat*> t;
	for (int i = 0; i < N; i++) {
		t.add(objects[i]);
	}
	t.deleteNodeTree(objects[0]);
	if ((int)(t.getT()) == 0xDDDDDDDD) {
		success3++;
		return true;
	}
	else {
		fail3++;
		return false;
	}
}

//bool Test::test_template_delete_tree()
//Тестирование удаления дерева
//return - true or false
bool Test::test_template_delete_tree() {
	const int N = 5;
	Bankomat* objects[N];
	AdressName bankTemp("MARX-20 ", "SBER ", "BBBBBBBB", 200);
	Bankomat bankTemp2("DDDDDDDD", 999);
	objects[0] = new Bankomat("AAAAAAAA", 100);
	objects[1] = new Bankomat("AAAAAAAA", 100);
	objects[2] = new Bankomat(*objects[0]);
	objects[3] = new Report(bankTemp, bankTemp2, 10, 20);
	objects[4] = new AdressName(bankTemp, bankTemp2);
	BinaryTree<Bankomat*> t;
	for (int i = 0; i < N; i++) {
		t.add(objects[i]);
	}
	t.deleteTree();
	if ((int)(t.getT()) == 0xDDDDDDDD) {
		success3++;
		return true;
	}
	else {
		fail3++;
		return false;
	}
}