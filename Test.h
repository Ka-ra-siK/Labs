#pragma once
#include "Bankomat.h"
#include "AdressName.h"
#include "Report.h"
using namespace std;
struct Test {
	int success;
	int success2;
	int fail; 
	int fail2;
	Test();
	bool test_destruct();
	bool test_id(Bankomat* test_bank);
	bool test_get_max(Bankomat* test_bank);
	bool test_get_min(Bankomat* test_bank);
	bool test_cur_am(Bankomat* test_bank);
	bool test_load_money(Bankomat* test_bank);
	bool test_take_money(Bankomat* test_bank);
	bool test_str_obj(Bankomat* test_bank);

	bool test_minus(Bankomat* bank);
	bool test_less(Bankomat* bank);
	bool test_plus(Bankomat* bank);
	bool test_more(Bankomat* bank);
	bool test_greater_and_equal(Bankomat* bank);
	bool test_less_and_equal(Bankomat* bank);
	bool test_assignment(Bankomat* bank);
	bool test_call_func(Bankomat* bank);
	bool test_noLastOperation();

	bool test_text(FILE *file);
	bool test_bin(FILE *file);

	bool test_adress(AdressName* test_bank);
	bool test_name(AdressName* test_bank);
	bool test_date(Report* test_bank, const char* date);
	bool test_sec_destruct();
};