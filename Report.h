#pragma once
#include "Bankomat.h"
#include "AdressName.h"

class Report: public AdressName{
public:
	Report();
	Report(time_t now, const char* date, const char* name, const char* adress, const char* id, int _curr_amount);
	~Report();
	void setDate();
	char* getDate();
	char* generateReport(int money);
private:
	time_t now;
	char* date;
};