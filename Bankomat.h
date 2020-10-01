#pragma once

class Bankomat { //�����
public:
	Bankomat(); //����������� ��-���������	
	Bankomat(const char* id, int _curr_amount); //����������� � ����������
	Bankomat(const Bankomat& bank);
	~Bankomat(); //���������� 

	void setID(const char* id); //������ Id
	char* getID(); //�������� ID
	const int getMax(); //�������� Max
	const int getMin(); //�������� Min
	void setCurAmoun(int _current_amount); //������ ���-�� ����� � ��������
	int getCurAmoun(); //������ ���-�� ����� � ���������
	void loadMoney(int money); //�������� �����
	void takeMoney(int money); //������
	char* strObj(); //��������� ������������� �������

private:
	char* id_number; //�����
	int current_amount; //������� ����� ����� � ���������
	static const int MAX_AMOUNT; //������������ �����, ������� ����� ����� ������
	static const int MIN_AMOUNT; //����������� �����, ������� ����� ����� � ������
};