/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tests_tests.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:15:38 by cacharle          #+#    #+#             */
/*   Updated: 2020/02/06 19:05:45 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../header.h"


void test_printf_tests_test(void)
{

	ASSERT_PRINTF("Hallo heimur");

	ASSERT_PRINTF("%s",       "Hallo heimur");
	ASSERT_PRINTF("%d",       1024);
	ASSERT_PRINTF("%d",       -1024);
	ASSERT_PRINTF("%i",       1024);
	ASSERT_PRINTF("%i",       -1024);
	ASSERT_PRINTF("%u",       1024u);
	ASSERT_PRINTF("%u",       -1024u);
	/* TEST("777",             3, "%o",       0777u) */
	/* TEST("37777777001",    11, "%o",       -0777u) */
	ASSERT_PRINTF("%x",       0x1234abcdu);
	ASSERT_PRINTF("%x",       -0x1234abcdu);
	ASSERT_PRINTF("%X",       0x1234abcdu);
	ASSERT_PRINTF("%X",       -0x1234abcdu);
	ASSERT_PRINTF("%c",       'x');
	ASSERT_PRINTF("%%");

	ASSERT_PRINTF("%c",       '\0');

#ifdef FT_PRINTF_TEST_BONUS
//	ASSERT_PRINTF("%+s",      "Hallo heimur");
	ASSERT_PRINTF("%+d",      1024);
	ASSERT_PRINTF("%+d",      -1024);
	ASSERT_PRINTF("%+i",      1024);
	ASSERT_PRINTF("%+i",      -1024);
//	ASSERT_PRINTF("%+u",      1024u);
//	ASSERT_PRINTF("%+u",      -1024u);
//	ASSERT_PRINTF("%+x",      0x1234abcdu);
//	ASSERT_PRINTF("%+x",      -0x1234abcdu);
//	ASSERT_PRINTF("%+X",      0x1234abcdu);
//	ASSERT_PRINTF("%+X",      -0x1234abcdu);
//	ASSERT_PRINTF("%+c",      'x');

//	ASSERT_PRINTF("% s",      "Hallo heimur");
	ASSERT_PRINTF("% d",      1024);
	ASSERT_PRINTF("% d",      -1024);
	ASSERT_PRINTF("% i",      1024);
	ASSERT_PRINTF("% i",      -1024);
//	ASSERT_PRINTF("% u",      1024u);
//	ASSERT_PRINTF("% u",      -1024u);
	/* TEST("777",             3, "% o",      0777u) */
	/* TEST("37777777001",    11, "% o",      -0777u) */
//	ASSERT_PRINTF("% x",      0x1234abcdu);
//	ASSERT_PRINTF("% x",      -0x1234abcdu);
//	ASSERT_PRINTF("% X",      0x1234abcdu);
//	ASSERT_PRINTF("% X",      -0x1234abcdu);
//	ASSERT_PRINTF("% c",      'x');

//////	ASSERT_PRINTF("%+ s",      "Hallo heimur");
//	ASSERT_PRINTF("%+ d",      1024);
//	ASSERT_PRINTF("%+ d",      -1024);
//	ASSERT_PRINTF("%+ i",      1024);
//	ASSERT_PRINTF("%+ i",      -1024);
//////	ASSERT_PRINTF("%+ u",      1024u);
//////	ASSERT_PRINTF("%+ u",      -1024u);
	/* TEST("777",             3, "%+ o",      0777u) */
	/* TEST("37777777001",    11, "%+ o",      -0777u) */
//////	ASSERT_PRINTF("%+ x",      0x1234abcdu);
//////	ASSERT_PRINTF("%+ x",      -0x1234abcdu);
//////	ASSERT_PRINTF("%+ X",      0x1234abcdu);
//////	ASSERT_PRINTF("%+ X",      -0x1234abcdu);
//////	ASSERT_PRINTF("%+ c",      'x');

	/* TEST("0777",            4, "%#o",      0777u) */
	/* TEST("037777777001",   12, "%#o",      -0777u) */
	ASSERT_PRINTF("%#x",      0x1234abcdu);
	ASSERT_PRINTF("%#x",      -0x1234abcdu);
	ASSERT_PRINTF("%#X",      0x1234abcdu);
	ASSERT_PRINTF("%#X",      -0x1234abcdu);
	/* TEST("0",               1, "%#o",      0u) */
	ASSERT_PRINTF("%#x",      0u);
	ASSERT_PRINTF("%#X",      0u);
	ASSERT_PRINTF("%#20x",      0x1234abcdu);
	ASSERT_PRINTF("%#20x",      -0x1234abcdu);
	ASSERT_PRINTF("%#20X",      0x1234abcdu);
	ASSERT_PRINTF("%#20X",      -0x1234abcdu);
	ASSERT_PRINTF("%#020x",     0x1234abcdu);
	ASSERT_PRINTF("%#020x",     -0x1234abcdu);
	ASSERT_PRINTF("%#020X",     0x1234abcdu);
	ASSERT_PRINTF("%#020X",     -0x1234abcdu);


//////////	ASSERT_PRINTF("% -0+*.*s",    20,  5, "Hallo heimur");
////	ASSERT_PRINTF("% -0+*.*d",    20,  5,  1024);
////	ASSERT_PRINTF("% -0+*.*d",    20,  5,  -1024);
////	ASSERT_PRINTF("% -0+*.*i",    20,  5,  1024);
////	ASSERT_PRINTF("% 0-+*.*i",    20,  5,  -1024);
////////	ASSERT_PRINTF("% 0-+*.*u",    20,  5,  1024u);
////////	ASSERT_PRINTF("% 0-+*.*u",    20,  5,  -1024u);
////////	ASSERT_PRINTF("%+ -0*.*x",    20,  5,  0x1234abcdu);
////////	ASSERT_PRINTF("%+ -0*.*x",    20, 10,  -0x1234abcdu);
////////	ASSERT_PRINTF("% -+0*.*X",    20,  5,  0x1234abcdu);
////////	ASSERT_PRINTF("% -+0*.*X",    20, 10,  -0x1234abcdu);
#endif
	/* TEST("777",             3, "%+o",      0777u) */
	/* TEST("37777777001",    11, "%+o",      -0777u) */

	ASSERT_PRINTF("%1s",      "Hallo heimur");
	ASSERT_PRINTF("%1d",      1024);
	ASSERT_PRINTF("%1d",      -1024);
	ASSERT_PRINTF("%1i",      1024);
	ASSERT_PRINTF("%1i",      -1024);
	ASSERT_PRINTF("%1u",      1024u);
	ASSERT_PRINTF("%1u",      -1024u);
	/* TEST("777",             3, "%1o",      0777u) */
	/* TEST("37777777001",    11, "%1o",      -0777u) */
	ASSERT_PRINTF("%1x",      0x1234abcdu);
	ASSERT_PRINTF("%1x",      -0x1234abcdu);
	ASSERT_PRINTF("%1X",      0x1234abcdu);
	ASSERT_PRINTF("%1X",      -0x1234abcdu);
	ASSERT_PRINTF("%1c",      'x');

	ASSERT_PRINTF("%20s",      "Hallo");
	ASSERT_PRINTF("%20d",      1024);
	ASSERT_PRINTF("%20d",      -1024);
	ASSERT_PRINTF("%20i",      1024);
	ASSERT_PRINTF("%20i",      -1024);
	ASSERT_PRINTF("%20u",      1024u);
	ASSERT_PRINTF("%20u",      -1024u);
	/* TEST("                 777",  20, "%20o",      0777u) */
	/* TEST("         37777777001",  20, "%20o",      -0777u) */
	ASSERT_PRINTF("%20x",      0x1234abcdu);
	ASSERT_PRINTF("%20x",      -0x1234abcdu);
	ASSERT_PRINTF("%20X",      0x1234abcdu);
	ASSERT_PRINTF("%20X",      -0x1234abcdu);
	ASSERT_PRINTF("%20c",      'x');

	ASSERT_PRINTF("%-20d",      1024);
	ASSERT_PRINTF("%-20d",      -1024);
	ASSERT_PRINTF("%-20i",      1024);
	ASSERT_PRINTF("%-20i",      -1024);
	ASSERT_PRINTF("%-20u",      1024u);
	ASSERT_PRINTF("%-20u",      -1024u);
	/* TEST("777                 ",  20, "%-20o",      0777u) */
	/* TEST("37777777001         ",  20, "%-20o",      -0777u) */
	ASSERT_PRINTF("%-20x",      0x1234abcdu);
	ASSERT_PRINTF("%-20x",      -0x1234abcdu);
	ASSERT_PRINTF("%-20X",      0x1234abcdu);
	ASSERT_PRINTF("%-20X",      -0x1234abcdu);
	ASSERT_PRINTF("%-20c",      'x');

	ASSERT_PRINTF("%020d",      1024);
	ASSERT_PRINTF("%020d",      -1024);
	ASSERT_PRINTF("%020i",      1024);
	ASSERT_PRINTF("%020i",      -1024);
	ASSERT_PRINTF("%020u",      1024u);
	ASSERT_PRINTF("%020u",      -1024u);
	/* TEST("00000000000000000777",  20, "%020o",      0777u) */
	/* TEST("00000000037777777001",  20, "%020o",      -0777u) */
	ASSERT_PRINTF("%020x",      0x1234abcdu);
	ASSERT_PRINTF("%020x",      -0x1234abcdu);
	ASSERT_PRINTF("%020X",      0x1234abcdu);
	ASSERT_PRINTF("%020X",      -0x1234abcdu);

	/* TEST("                0777",  20, "%#20o",      0777u) */
	/* TEST("        037777777001",  20, "%#20o",      -0777u) */

	/* TEST("00000000000000000777",  20, "%#020o",     0777u) */
	/* TEST("00000000037777777001",  20, "%#020o",     -0777u) */
////	ASSERT_PRINTF("%0-20s",      "Hallo");
//	ASSERT_PRINTF("%0-20d",      1024);
//	ASSERT_PRINTF("%0-20d",      -1024);
//	ASSERT_PRINTF("%0-20i",      1024);
//	ASSERT_PRINTF("%0-20i",      -1024);
//	ASSERT_PRINTF("%0-20u",      1024u);
//	ASSERT_PRINTF("%0-20u",      -1024u);
	/* TEST("777                 ",  20, "%-020o",      0777u) */
	/* TEST("37777777001         ",  20, "%-020o",      -0777u) */
//	ASSERT_PRINTF("%-020x",      0x1234abcdu);
//	ASSERT_PRINTF("%-020x",      -0x1234abcdu);
//	ASSERT_PRINTF("%-020X",      0x1234abcdu);
//	ASSERT_PRINTF("%-020X",      -0x1234abcdu);
////	ASSERT_PRINTF("%-020c",      'x');

	ASSERT_PRINTF("%*s",      20, "Hallo");
	ASSERT_PRINTF("%*d",      20, 1024);
	ASSERT_PRINTF("%*d",      20, -1024);
	ASSERT_PRINTF("%*i",      20, 1024);
	ASSERT_PRINTF("%*i",      20, -1024);
	ASSERT_PRINTF("%*u",      20, 1024u);
	ASSERT_PRINTF("%*u",      20, -1024u);
	/* TEST("                 777",  20, "%*o",      20, 0777u) */
	/* TEST("         37777777001",  20, "%*o",      20, -0777u) */
	ASSERT_PRINTF("%*x",      20, 0x1234abcdu);
	ASSERT_PRINTF("%*x",      20, -0x1234abcdu);
	ASSERT_PRINTF("%*X",      20, 0x1234abcdu);
	ASSERT_PRINTF("%*X",      20, -0x1234abcdu);
	ASSERT_PRINTF("%*c",      20, 'x');

	ASSERT_PRINTF("%.20s",      "Hallo heimur");
	ASSERT_PRINTF("%.20d",      1024);
	ASSERT_PRINTF("%.20d",      -1024);
	ASSERT_PRINTF("%.20i",      1024);
	ASSERT_PRINTF("%.20i",      -1024);
	ASSERT_PRINTF("%.20u",      1024u);
	ASSERT_PRINTF("%.20u",      -1024u);
	/* TEST("00000000000000000777",   20, "%.20o",      0777u) */
	/* TEST("00000000037777777001",   20, "%.20o",      -0777u) */
	ASSERT_PRINTF("%.20x",      0x1234abcdu);
	ASSERT_PRINTF("%.20x",      -0x1234abcdu);
	ASSERT_PRINTF("%.20X",      0x1234abcdu);
	ASSERT_PRINTF("%.20X",      -0x1234abcdu);

	ASSERT_PRINTF("%20.5s",     "Hallo heimur");
	ASSERT_PRINTF("%20.5d",      1024);
	ASSERT_PRINTF("%20.5d",      -1024);
	ASSERT_PRINTF("%20.5i",      1024);
	ASSERT_PRINTF("%20.5i",      -1024);
	ASSERT_PRINTF("%20.5u",      1024u);
	ASSERT_PRINTF("%20.5u",      -1024u);
	/* TEST("               00777",   20, "%20.5o",      0777u) */
	/* TEST("         37777777001",   20, "%20.5o",      -0777u) */
	ASSERT_PRINTF("%20.5x",      0x1234abcdu);
	ASSERT_PRINTF("%20.10x",     -0x1234abcdu);
	ASSERT_PRINTF("%20.5X",      0x1234abcdu);
	ASSERT_PRINTF("%20.10X",     -0x1234abcdu);

//	ASSERT_PRINTF("%020.5s",    "Hallo heimur");
	ASSERT_PRINTF("%020.5d",     1024);
	ASSERT_PRINTF("%020.5d",     -1024);
	ASSERT_PRINTF("%020.5i",     1024);
	ASSERT_PRINTF("%020.5i",     -1024);
	ASSERT_PRINTF("%020.5u",     1024u);
	ASSERT_PRINTF("%020.5u",     -1024u);
	/* TEST("               00777",   20, "%020.5o",     0777u) */
	/* TEST("         37777777001",   20, "%020.5o",     -0777u) */
	ASSERT_PRINTF("%020.5x",     0x1234abcdu);
	ASSERT_PRINTF("%020.10x",    -0x1234abcdu);
	ASSERT_PRINTF("%020.5X",     0x1234abcdu);
	ASSERT_PRINTF("%020.10X",    -0x1234abcdu);

	ASSERT_PRINTF("%.0s",        "Hallo heimur");
	ASSERT_PRINTF("%20.0s",      "Hallo heimur");
	ASSERT_PRINTF("%.s",         "Hallo heimur");
	ASSERT_PRINTF("%20.s",       "Hallo heimur");
	ASSERT_PRINTF("%20.0d",      1024);
	ASSERT_PRINTF("%20.d",       -1024);
	ASSERT_PRINTF("%20.d",       0);
	ASSERT_PRINTF("%20.0i",      1024);
	ASSERT_PRINTF("%20.i",       -1024);
	ASSERT_PRINTF("%20.i",       0);
	ASSERT_PRINTF("%20.u",       1024u);
	ASSERT_PRINTF("%20.0u",      -1024u);
	ASSERT_PRINTF("%20.u",       0u);
	/* TEST("                 777",   20, "%20.o",       0777u) */
	/* TEST("         37777777001",   20, "%20.0o",      -0777u) */
	/* TEST("                    ",   20, "%20.o",       0u) */
	ASSERT_PRINTF("%20.x",       0x1234abcdu);
	ASSERT_PRINTF("%20.0x",      -0x1234abcdu);
	ASSERT_PRINTF("%20.x",       0u);
	ASSERT_PRINTF("%20.X",       0x1234abcdu);
	ASSERT_PRINTF("%20.0X",      -0x1234abcdu);
	ASSERT_PRINTF("%20.X",       0u);
}
