#include <fstream>
#include <iostream>
#include "Functions.h"
using namespace std;
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