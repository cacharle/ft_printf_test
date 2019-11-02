#include <stdio.h>
#include "header.h"

int main(int argc, char **argv)
{
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
	return 0;
}
