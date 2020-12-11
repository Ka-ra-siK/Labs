#pragma once
#include "Bankomat.h"
#include "AdressName.h"

class History {
public:
	friend class Report;
	History();
	~History();
private:
	int hist;
	char* date = new char;
};

class Report: public AdressName{
public:
	Report();
	Report(const AdressName& bank, const Bankomat& bankOr);
	Report(const AdressName& bank, const Bankomat& bankOr, int a, int b);
	void setHist(char* date, int money);
	void showHist();
	~Report();
	void withdrawR(Bankomat& bankOr, int money);
	int getHistRec();
	int getHistAmout();
	char* toString() override;
private:
	time_t now;
	int history_amount = 2;
	int histRec = 0;
	History* history = new History[history_amount];
};