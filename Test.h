#pragma once
#include "Bankomat.h"

struct Test { //���������
	int success; //���-�� �������� ������
	int fail; //���-� ����������� ������
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