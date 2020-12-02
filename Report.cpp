#include "Report.h"
#include <iostream>
#include <ctime>
#include "Functions.h"
using std::cout;
using std::cin;

//History::History()
//Стандартный конструктор для класса History
//Создает объект
History::History() {
	hist = NULL;
	date = NULL;
}

//History::~History()
//Стандартный деструктор класса History
//Удаляет объект
History::~History() {
	delete[] date;
}

//Report::Report(const BankomatLoc& bank, const Bankomat& bankOr) : BankomatLoc(bank, bankOr)
//Конструктор Report. Содержит поля базового класса и его наследника 
Report::Report(const AdressName& bank, const Bankomat& bankOr) : AdressName(bank, bankOr) {
	History();
}
Report::Report(const AdressName& bank, const Bankomat& bankOr, int a, int b) : AdressName(bank, bankOr) {
	History();
	time_t now = time(0);
	char* date = ctime(&now);
	setHist(date, a);
	setHist(date, b);
}

//Report::Report()
//Стандартный конструктор для класса Report
//Создает объект
Report::Report() {
	History();
}

//Report::~Report()
//Стандартный деструктор для класса History
//Удаляет объект
Report::~Report() {}

//void Report::showHist()
//показывает массив
void Report::showHist() {
	for (unsigned short int i = 0; i < getHistRec(); i++) {
		cout << "Withdrawn: " << history[i].hist << endl;
		cout << " Date: " << history[i].date << endl;

	}
}
//void Report::setHist(Report& bank, char* date, int money)
//записывает дату и деньги в историю
//args
//Report& bank -- объект Report, char* date -- date, int money -- money
void Report::setHist(char* date, int money) {
	history[histRec].date = _strdup(date);
	history[histRec].hist = money;
	histRec++;
}
//void Report::withdrawR(Bankomat& bankOr, int money)
//вывод денег 
//args
//Bankomat& bankOr -- банк с которого снимают деньги, int деньги
void Report::withdrawR(Bankomat& bankOr, int money) {
	try {
		if (money <= bankOr.getMax() && bankOr.getCurAmoun() >= money) {
			bankOr.setCurAmoun(bankOr.getCurAmoun() - money);
			time_t now = time(0);
			char* date = ctime(&now);
			setHist(date, money);
		}
		else throw 1;
	}

	catch (int ex) {
		{
			cout << "It isn`t allowed to withdraw greater than " << bankOr.getMax() << " per once" << endl;
			cout << "Or you are trying to withdraw more than you have" << endl;
		}
	}
}

//int Report::getHistRec()
//returns число написанной даты
int Report::getHistRec() {
	return this->histRec;
}

//int Report::getHistAmout()
// returns размер массива с датой
int Report::getHistAmout() {
	return this->history_amount;
}

//char* Report::toString()
//Строковое представление
//return str - строку с информацией
char* Report::toString() {
	char* oldStr = AdressName::toString();
	char* hist;
	char* money;
	const char* newMoneyAnounce = "New Money Amount: ";
	int newMoney = getCurAmoun();
	char buf[1024];
	char* secBuf = NULL;
	char* str = new char[1024 + 1];
	const char* moneyAnounce = "Money withdrawn: ";
	if (getHistRec() != 0) {
		hist = new char[1024];
	}
	else return oldStr;
	for (int i = 0; i < getHistRec(); i++) {
		money = (intToCharArr(history[i].hist));
		hist = _strdup(history[i].date);
		newMoney -= history[i].hist;
		if (secBuf == NULL) {
			secBuf = new char[1024 + 1];
			sprintf(secBuf, "%s%s%s", hist, moneyAnounce, money);
		}
		else sprintf(secBuf, "%s\n%s%s %s", secBuf, hist, moneyAnounce, money);
	}
	sprintf(str, "%s\n%s", secBuf, oldStr);
	sprintf(str, "%s\n%s%s", str, newMoneyAnounce, intToCharArr(newMoney));
	return str;
}