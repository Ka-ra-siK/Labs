#pragma once
#ifndef _Bankomat_h
#define _CRT_SECURE_NO_WARNINGS
#define _Bankomat_h
#include <iostream>
using namespace std;
class Bankomat { 
public:
	Bankomat();
	Bankomat(const char* id, int _curr_amount);
	Bankomat(const Bankomat& bank);
	~Bankomat();  
	void setID(const char* id); 
	char* getID(); 
	const int getMax();
	const int getMin();
	void setCurAmoun(int _current_amount); 
	int getCurAmoun(); 
	void loadMoney(int money); 
	void takeMoney(int money); 
	char* strObj(); 
	void setLastOp(int money);
	void operator -=(int value);
	void operator +=(int value);
	bool operator >=(int value);
	bool operator <=(int value);
	bool operator <(int value);
	friend bool operator >(Bankomat& bank, int value);
	char* operator()() const;
	Bankomat& operator = (const Bankomat& bank);
	friend istream& operator >> (istream& in, Bankomat& bank);
	friend ostream& operator << (ostream& out, Bankomat& bank);
	void toTxt(ofstream& out);
	void toBin(fstream& out);
	Bankomat* outTxt(ifstream& in);
	Bankomat* outBin(fstream& in);
private:
	char* id_number;
	char* lastOp;
	int current_amount;
	static const int MAX_AMOUNT;
	static const int MIN_AMOUNT;
};
#endif