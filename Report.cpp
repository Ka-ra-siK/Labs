#include "Report.h"

//Report::Report()
//Стандартный конструктор для класса Report
//Создает объект
Report::Report(){
	time_t now = NULL;
	date = nullptr;
}

//Report::Report(time_t now, const char* date, const char* name, 
//const char* adress, const char* id, int _curr_amount):AdressName(name, adress, id, _curr_amount)
//Конструктор для класса Report
//Создает объект
//args:
// - time_t now - вревенный тип данных, const char* date - дата
// - const char* name - название банкомата, const char* adress - адрес расположения банкомата, 
// - const char* id - id банкомата, int _curr_amount - кол-во денег в банкомате
Report::Report(time_t now, const char* date, const char* name, 
	const char* adress, const char* id, int _curr_amount):AdressName(name, adress, id, _curr_amount) {
	try{
		if (now == NULL || date == nullptr) throw 1;
		now = time(0);
		date = ctime(&now);
	}
		catch (int a) {
		cout << "Invalid number of parameters" << endl;
	}
}

//Report::~Report()
//Деструктор класса Report
//Удаляет динамические строки
Report::~Report(){
	delete[] date;
}

//void Report::setDate()
//Задать дату
void Report::setDate() {
	now = time(0);
	char* _date = ctime(&now);
	try {
		int len = strlen(_date);
		if (len >= 256) throw 1;
		date = new char[len + 1];
		strcpy(date, _date);
	}
	catch (int a) {
		cout << "Number of characters exceeded" << endl;
	}
}

//char* Report::getDate()
//Получить Дату
//return - Дату
char* Report::getDate() {
	return date;
}

//char* Report::generateReport(int money)
//Строковое предствление
//return - информацию о банкомате
char* Report::generateReport(int money) {
	try {
		char *adr, *name, *date;
		adr = getAdress();
		name = getName();
		time_t now = time(0);
		date = ctime(&now);
		takeMoney(money);
		char buf[16];
		if (adr == NULL || name == NULL || money <= 0) throw 1;
		sprintf(buf, "%d", money);
		const char* money = buf;
		int len = 32;
		char* string = new char[len + 1];
		sprintf(string, "%s %s %s %s %s", adr, name, Bankomat::strObj(), money, date);
		return string;
	}
	catch (int a) {
		cout << "Cannot be represented in a string representation" << endl;
	}
}