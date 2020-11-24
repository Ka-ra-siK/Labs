#include "Report.h"

//Report::Report()
//����������� ����������� ��� ������ Report
//������� ������
Report::Report(){
	time_t now = NULL;
	date = nullptr;
}

//Report::Report(time_t now, const char* date, const char* name, 
//const char* adress, const char* id, int _curr_amount):AdressName(name, adress, id, _curr_amount)
//����������� ��� ������ Report
//������� ������
//args:
// - time_t now - ��������� ��� ������, const char* date - ����
// - const char* name - �������� ���������, const char* adress - ����� ������������ ���������, 
// - const char* id - id ���������, int _curr_amount - ���-�� ����� � ���������
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
//���������� ������ Report
//������� ������������ ������
Report::~Report(){
	delete[] date;
}

//void Report::setDate()
//������ ����
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
//�������� ����
//return - ����
char* Report::getDate() {
	return date;
}

//char* Report::generateReport(int money)
//��������� ������������
//return - ���������� � ���������
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