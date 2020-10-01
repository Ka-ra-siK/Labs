#pragma once

class Bankomat { //класс
public:
	Bankomat(); //Конструктор по-умолчанию	
	Bankomat(const char* id, int _curr_amount); //Конструктор с параметром
	Bankomat(const Bankomat& bank);
	~Bankomat(); //Деструктор 

	void setID(const char* id); //Задать Id
	char* getID(); //Получить ID
	const int getMax(); //Получить Max
	const int getMin(); //Получить Min
	void setCurAmoun(int _current_amount); //Задать кол-во денег в банкомат
	int getCurAmoun(); //Узнать кол-во денег в банкомате
	void loadMoney(int money); //Загрузка денег
	void takeMoney(int money); //Взятие
	char* strObj(); //Строковое представление объекта

private:
	char* id_number; //Номер
	int current_amount; //Текущая сумма денег в банкомате
	static const int MAX_AMOUNT; //Максимальная сумма, которую можно снять разово
	static const int MIN_AMOUNT; //Минимальная сумма, которую можно снять и внести
};