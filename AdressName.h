#pragma once
#include "Bankomat.h"

class AdressName: public Bankomat {
public:
	AdressName();
	AdressName(const char* name, const char* adress, const char* id, int _curr_amount);
	~AdressName();
	void setName(const char* name);
	void setAdress(const char* adress);
	char* getName();
	char* getAdress();
	friend istream& operator >> (istream& in, AdressName& bank);
	friend ostream& operator << (ostream& out, AdressName& bank);
private:
	char* bank_name;
	char* bank_adress;
};