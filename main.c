/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:13:45 by cacharle          #+#    #+#             */
/*   Updated: 2020/09/29 16:05:37 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"
#include "tests/tests.h"

int main(int argc, char **argv)
{
	timeout.tv_sec = 1;
	timeout.tv_usec = 0;
	if (pipe(timeout_pipe) == -1)
		return (1);

	(void)argc;
	(void)argv;

	timeout.tv_sec = 0;
	timeout.tv_usec = 100000;
	test_pft_nacked();
	test_pft_percent();
	test_pft_nocrash();
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
#ifdef FT_PRINTF_TEST_BONUS
	test_moulitest_40();
	test_moulitest_41();
	test_moulitest_42();
	test_moulitest_43();
	test_moulitest_45();
#endif
	test_moulitest_50();
	test_moulitest_51();
	test_moulitest_52();

#ifdef FT_PRINTF_TEST_BONUS
	test_moulitest_60();
	test_moulitest_61();
#endif
	test_moulitest_69();
	test_moulitest_70();
	test_moulitest_71();
	test_moulitest_72();
	test_moulitest_73();
	test_moulitest_74();
	test_moulitest_79();
#ifdef FT_PRINTF_TEST_BONUS
	test_moulitest_90();
#endif
	test_moulitest_91();
	test_moulitest_wildcard_01();
	test_moulitest_wildcard_02();
	test_moulitest_wildcard_03();

	test_printf_tester();

	test_printf_tests_test();

	generated_test();

	// added according to users
	ASSERT_PRINTF("%.p", NULL);
	ASSERT_PRINTF("%.d", 1);
	ASSERT_PRINTF("%.d", 0);
	ASSERT_PRINTF("%.u", 1);
	ASSERT_PRINTF("%.s", "aasf");
	ASSERT_PRINTF("%.p", NULL);
	ASSERT_PRINTF("%.c", 'a');
	ASSERT_PRINTF("%.x", 0xee);
	ASSERT_PRINTF("%.X", 0xee);
	ASSERT_PRINTF("%1.p", NULL);
	ASSERT_PRINTF("%1.d", 1);
	ASSERT_PRINTF("%1.u", 1);
	ASSERT_PRINTF("%1.s", "aasf");
	ASSERT_PRINTF("%1.p", NULL);
	ASSERT_PRINTF("%1.c", 'a');
	ASSERT_PRINTF("%1.x", 0xee);
	ASSERT_PRINTF("%1.X", 0xee);
	ASSERT_PRINTF("%5.p", NULL);
	ASSERT_PRINTF("%5.d", 1);
	ASSERT_PRINTF("%5.u", 1);
	ASSERT_PRINTF("%5.s", "aasf");
	ASSERT_PRINTF("%5.p", NULL);
	ASSERT_PRINTF("%5.c", 'a');
	ASSERT_PRINTF("%5.x", 0xee);
	ASSERT_PRINTF("%5.X", 0xee);

	ASSERT_PRINTF("-->|%-16.p|<-- ", NULL);
	ASSERT_PRINTF("-->|%-16p|<-- ",  (void*)0x1900);
	ASSERT_PRINTF("-->|%-16.p|<-- ", NULL);
	ASSERT_PRINTF("-->|%-16p|<-- ",  (void*)0x1900);

	/* ASSERT_PRINTF("%.0p", NULL); */
	/* ASSERT_PRINTF("%.2p", NULL); */
	/* ASSERT_PRINTF("%.3p", NULL); */
	/* ASSERT_PRINTF("%.4p", NULL); */
	/* ASSERT_PRINTF("%.5p", NULL); */
	/* ASSERT_PRINTF("%.6p", NULL); */
	/* ASSERT_PRINTF("%.7p", NULL); */

	return 0;
}
