#include <stdio.h>
#include "header.h"
#include "tests/tests.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	test_pft_nacked();
	test_pft_percent();
	test_pft_string();
	test_pft_int_i();
	test_pft_int_d();
	test_ptf_uint();
	test_ptf_hex_low();
	test_ptf_hex_up();
	test_pft_ptr();
	test_pft_char();

	test_moulitest_00();
	test_moulitest_01();
	test_moulitest_02();
	test_moulitest_03();
	test_moulitest_04();
	test_moulitest_05();
	test_moulitest_06();
	test_moulitest_09();
	test_moulitest_12();
	test_moulitest_14();
	test_moulitest_15();
	test_moulitest_16();
	test_moulitest_18();
	test_moulitest_40();
	test_moulitest_41();
	test_moulitest_42();
	test_moulitest_43();
	test_moulitest_45();
	test_moulitest_50();
	test_moulitest_51();
	test_moulitest_52();
	test_moulitest_60();
	test_moulitest_61();
	test_moulitest_69();
	test_moulitest_70();
	test_moulitest_71();
	test_moulitest_72();
	test_moulitest_73();
	test_moulitest_74();
	test_moulitest_79();
	test_moulitest_90();
	test_moulitest_91();
	test_moulitest_wildcard_01();
	test_moulitest_wildcard_02();
	test_moulitest_wildcard_03();
	return 0;
}
