#include "AdressName.h"
#include <cstring>

//AdressName::AdressName()
//����������� ����������� ��� ������ AdressName
//������� ������
AdressName::AdressName() {
	bank_adress = nullptr;
	bank_name = nullptr;
}

//AdressName::AdressName(const char* name, const char* adress, const char* id, int _curr_amount)
//����������� ��� ������ AdressName
//������� ������
//args:
// - const char* name - �������� ���������, const char* adress - ����� ������������ ���������, 
// - const char* id - id ���������, int _curr_amount - ���-�� ����� � ���������
AdressName::AdressName(const char* adress, const char* name,
	const char* id, int _curr_amount): Bankomat(id, _curr_amount) {
	try {
		if (name == NULL || adress == NULL) throw 1;
		int len_1 = strlen(name);
		int len_2 = strlen(adress);
		bank_name = new char[len_1 + 1];
		bank_adress = new char[len_2 + 1];
		strcpy(bank_name, name);
		strcpy(bank_adress, adress);
	}
	catch (int a) {
		//cout << "Invalid number of parameters" << endl;
	}
}

//AdressName::AdressName(const AdressName& bank, const Bankomat& bankOr)
//����������� ����������� ������ AdressName
//�������� �������
//args:
// - const AdressName& bank - ������ � �������� ��������� �����
// - const Bankomat& bankOr - ���� ����������
AdressName::AdressName(const AdressName& bank, const Bankomat& bankOr)
	:Bankomat(bankOr) {
	if (bank.bank_adress)
	{
		this->bank_adress = new char[strlen(bank.bank_adress) + 1];
		strcpy(this->bank_adress, bank.bank_adress);
	}
	else this->bank_adress = (char*)"Adress";
	if (bank.bank_name)
	{
		this->bank_name = new char[strlen(bank.bank_name) + 1];
		strcpy(this->bank_name, bank.bank_name);
	}
	else this->bank_name = (char*)"Name";
}

//AdressName::~AdressName()
//���������� ������ AdressName
//������� ������������ ������
AdressName::~AdressName() {
	delete[]  bank_adress;
	delete[] bank_name;
}

//char* AdressName::getAdress()
//�������� Adress �������
//return - Adress �������
char* AdressName::getAdress() {
	return bank_adress;
}

//char* AdressName::getName()
//�������� Name �������
//return - Name �������
char* AdressName::getName() {
	return bank_name;
}

//void AdressName::setAdress(const char* adress)
//������ ������� Adress
//args:
// - const char* adress - Adress, ������� ����� ������� �������
void AdressName::setAdress(const char* adress) {
	try {
		int len = strlen(adress);
		if (len >= 256) throw 1;
		bank_adress = new char[len + 1];
		strcpy(bank_adress, adress);
	}
	catch (int a) {
		cout << "Number of characters exceeded" << endl;
	}
}

//void AdressName::setName(const char* name)
//������ ������� Name
//args:
// - const char* name - Name, ������� ����� ������� �������
void AdressName::setName(const char* name) {
	try {
		int len = strlen(name);
		if (len >= 256) throw 1;
		bank_name = new char[len + 1];
		strcpy(bank_name, name);
	}
	catch (int a) {
		cout << "Number of characters exceeded" << endl;
	}
}

// istream & operator >> (istream & is, Bankomat & bank)
//���������� ��������� >> 
// args:
// istream& is -- �����, AdressName& bank -- ����
//returns stream
istream& operator >> (istream& is, AdressName& bank) {
	try{
		if (bank.bank_adress != NULL || bank.bank_name != NULL) throw 1;
		bank.bank_adress = new char[16];
		bank.bank_name = new char[16];
		is >> bank.bank_adress >> bank.bank_name;
		return is;
	}
	catch (const std::exception&){
		delete[] bank.bank_adress;
		delete[] bank.bank_name;
	}
}
//istream& operator << (istream& os, Bankomat& bank)
//���������� ���������  << operator
// args:
// istream& os -- �����, AdressName& bank -- ����
//return �����
ostream& operator << (ostream& os, AdressName& bank) {
	os << bank.bank_adress << " " << bank.bank_name;
	return os;
}

//char* AdressName::toString()
//��������� �������������
//return str - ������ � �����������
char* AdressName::toString() {
	char* str = new char[256];
	const char* bankAnounce = " Bank: ";
	const char* adrAnounce = " Location: ";
	char* bank_name = this->getName();
	char* bank_adress = this->getAdress();

	memcpy(str, bankAnounce, strlen(bankAnounce));
	int sum = strlen(bankAnounce);

	memcpy(str + sum, bank_name, strlen(bank_name));
	sum += strlen(bank_name);

	memcpy(str + sum, adrAnounce, strlen(adrAnounce));
	sum += strlen(adrAnounce);

	memcpy(str + sum, bank_adress, strlen(bank_adress));
	sum += strlen(bank_adress);

	char* buf = Bankomat::toString();
	memcpy(str + sum, buf, strlen(buf));
	sum += strlen(buf);
	str[sum] = '\0';
	return str;
}