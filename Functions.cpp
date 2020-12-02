#include <fstream>
#include <iostream>
#include "Functions.h"
using namespace std;
char* intToCharArr(int num) {

	int arrSize = 0;
	int numCpy = num;
	while (numCpy != 0) {
		numCpy /= 10;
		arrSize++;
	}
	int i = arrSize - 1;
	char* str = new char[arrSize + 1];
	str[arrSize] = '\0';
	while (num != 0) {
		str[i] = num % 10 + '0';
		num /= 10;
		i--;
	}
	return str;
}

int lineAmount(ifstream& in) {
	int i = 0;
	const int N = 1024;
	char* str = new char[N];
	while (!in.eof()) {
		in.getline(str, N, '\n');
		i++;
	}
	delete[] str;
	in.clear();
	in.seekg(0);
	return i - 1;
}
int fileSize(fstream& in) {
	in.seekg(0, ios::end);
	int N = in.tellg();
	in.clear();
	in.seekg(0);
	return N;
}
