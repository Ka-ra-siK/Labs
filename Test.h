#pragma once
#include "Bankomat.h"

struct Test { //Структура
	int success; //Кол-во успешных тестов
	int fail; //Кол-в проваленных тестов
	Test();
	bool test_destruct();
	bool test_id(Bankomat* test_bank);
	bool test_get_max(Bankomat* test_bank);
	bool test_get_min(Bankomat* test_bank);
	bool test_cur_am(Bankomat* test_bank);
	bool test_load_money(Bankomat* test_bank);
	bool test_take_money(Bankomat* test_bank);
	bool test_str_obj(Bankomat* test_bank);
};