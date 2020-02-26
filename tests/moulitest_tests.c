/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moulitest_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:15:03 by cacharle          #+#    #+#             */
/*   Updated: 2020/02/26 17:24:29 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../header.h"


void test_moulitest_00(void)
{
	ASSERT_PRINTF("This is a simple test.");
	ASSERT_PRINTF("This is a simple test.\nSecond sentence.\n");
	ASSERT_PRINTF("");
	ASSERT_PRINTF("\n");
}

void test_moulitest_01(void)
{
	ASSERT_PRINTF("%s", "abc");
	ASSERT_PRINTF("111%s333", "222");
	ASSERT_PRINTF("%s333", "222");
	ASSERT_PRINTF("111%s", "222");
//	ASSERT_PRINTF("{%s}", 0);
	ASSERT_PRINTF("{%s}", "");
}

void test_moulitest_02(void)
{
	ASSERT_PRINTF("111%s333%s555", "222", "444");
	ASSERT_PRINTF("111%s333%s555%saaa%sccc", "222", "444", "666", "bbb");
	ASSERT_PRINTF("%s%s%s%s%s", "1", "2", "3", "4", "5");
}

void test_moulitest_03(void)
{
	ASSERT_PRINTF("%d", 42);
	ASSERT_PRINTF("%d", -42);
	ASSERT_PRINTF("before %d after", 42);
	ASSERT_PRINTF("%d%d%d%d%d", 1, -2, 3, -4, 5);
	ASSERT_PRINTF("a%db%dc%dd", 1, -2, 3);
	ASSERT_PRINTF("%d", INT_MAX);
	ASSERT_PRINTF("%d", INT_MIN);
}

void test_moulitest_04(void)
{
	int i;
	unsigned long l;
	char *str;

	ASSERT_PRINTF("%p", &i);
	ASSERT_PRINTF("%p", &l);
	ASSERT_PRINTF("%p", &str);
	ASSERT_PRINTF("%p", &strlen);
//	ASSERT_PRINTF("%p", 0);
}

void test_moulitest_05(void)
{
	ASSERT_PRINTF("%%");
	ASSERT_PRINTF("aa%%bb");
	ASSERT_PRINTF("%%%%%%%%%%");
	ASSERT_PRINTF(".%%.%%.%%.%%.%%.%%.%%.%%.");
//	ASSERT_PRINTF("%");
#ifdef FT_PRINTF_TEST_BONUS
	ASSERT_PRINTF("{% %}");
#endif
}

void test_moulitest_06(void)
{
	ASSERT_PRINTF("s: %s, p: %p, d:%d", "a string", &test_moulitest_06, 42);
	ASSERT_PRINTF("%s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
}

void test_moulitest_09(void)
{
	ASSERT_PRINTF("%i", 42);
	ASSERT_PRINTF("%i", -42);
	ASSERT_PRINTF("before %i after", 42);
	ASSERT_PRINTF("%i%i%i%i%i", 1, -2, 3, -4, 5);
	ASSERT_PRINTF("a%ib%ic%id", 1, -2, 3);
}

void test_moulitest_12(void)
{
	ASSERT_PRINTF("%u", 42);
	ASSERT_PRINTF("before %u after", 42);
	ASSERT_PRINTF("%u%u%u%u%u", 1, 100, 999, 42, 999988888);
	ASSERT_PRINTF("a%ub%uc%ud", 0, 55555, 100000);
	ASSERT_PRINTF("%u", UINT_MAX);
}

void test_moulitest_14(void)
{
	ASSERT_PRINTF("%x", 42);
	ASSERT_PRINTF("before %x after", 42);
	ASSERT_PRINTF("%x%x%x%x%x", 1, 100, 999, 42, 999988888);
	ASSERT_PRINTF("a%xb%xc%xd", 0, 55555, 100000);
	ASSERT_PRINTF("%x, %x", 0, UINT_MAX);
}

void test_moulitest_15(void)
{
	ASSERT_PRINTF("%X", 42);
	ASSERT_PRINTF("before %X after", 42);
	ASSERT_PRINTF("%X%X%X%X%X", 1, 100, 999, 42, 999988888);
	ASSERT_PRINTF("a%Xb%Xc%Xd", 0, 55555, 100000);
	ASSERT_PRINTF("%X, %X", 0, UINT_MAX);
}

void test_moulitest_16(void)
{
	ASSERT_PRINTF("%c", 'c');
	ASSERT_PRINTF("%c%c", '4', '2');
	/* ASSERT_PRINTF("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \ */
	/* 	   	%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\ */
	/* 	   	%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", */
	/* 	   	' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', */
	/* 	   	'/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', */
	/* 	   	'>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', */
	/* 	   	'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', */
	/* 	   	']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', */
//			'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
	ASSERT_PRINTF("%c", 0);
}

void test_moulitest_18(void)
{
	/* char c; */
	ASSERT_PRINTF("%s %d %p %% %x", "bonjour ", 42, &free, 42);
	/* ASSERT_PRINTF("%s%d%p%%%i%o%u%x%X%c","bonjour", 42, &c, 42, 42, 42, 42, 42, 'c'); */
}

void test_moulitest_40(void)
{
	ASSERT_PRINTF("%ld%ld", 0l, 42l);
	ASSERT_PRINTF("%ld", (long)INT_MAX + 1);
	ASSERT_PRINTF("%ld", (long)INT_MIN - 1);
	ASSERT_PRINTF("%ld", LONG_MAX);
	ASSERT_PRINTF("%ld", LONG_MIN);
	ASSERT_PRINTF("%li%li", 0l, 42l);
	ASSERT_PRINTF("%li", (long)INT_MAX + 1);
	ASSERT_PRINTF("%li", (long)INT_MIN - 1);
	ASSERT_PRINTF("%li", LONG_MAX);
	ASSERT_PRINTF("%li", LONG_MIN);
	ASSERT_PRINTF("%lu, %lu", 0ul, ULONG_MAX);
	ASSERT_PRINTF("%lx, %lx", 0ul, ULONG_MAX);
	ASSERT_PRINTF("%lX, %lX", 0ul, ULONG_MAX);
	/* ASSERT_PRINTF("%lc, %lc", L'暖', L'ح'); */
}

void test_moulitest_41(void)
{
	ASSERT_PRINTF("%lld%lld", 0ll, 42ll);
	ASSERT_PRINTF("%lld", LLONG_MAX);
	ASSERT_PRINTF("%lld", LLONG_MIN);
	ASSERT_PRINTF("%lli%lli", 0ll, 42ll);
	ASSERT_PRINTF("%lli", LLONG_MAX);
	ASSERT_PRINTF("%lli", LLONG_MIN);
	ASSERT_PRINTF("%llu, %llu", 0llu, ULLONG_MAX);
	ASSERT_PRINTF("%llx, %llx", 0llu, ULLONG_MAX);
	ASSERT_PRINTF("%llX, %llX", 0llu, ULLONG_MAX);
}

void test_moulitest_42(void)
{
	ASSERT_PRINTF("%hd%hd", (short int)0, (short int)42);
//	ASSERT_PRINTF("%hd", SHRT_MAX);
//	ASSERT_PRINTF("%hd", SHRT_MIN);
////	ASSERT_PRINTF("%hi%hi", 0, 42);
//	ASSERT_PRINTF("%hi", SHRT_MAX);
//	ASSERT_PRINTF("%hi", SHRT_MIN);
////	ASSERT_PRINTF("%hu, %hu", 0, USHRT_MAX);
////	ASSERT_PRINTF("%hx, %hx", 0, USHRT_MAX);
////	ASSERT_PRINTF("%hX, %hX", 0, USHRT_MAX);
}

void test_moulitest_43(void)
{
////	ASSERT_PRINTF("%hhd%hhd", 1, 42);
//	ASSERT_PRINTF("%hhd", CHAR_MAX);
//	ASSERT_PRINTF("%hhd", CHAR_MAX + 42);
//	ASSERT_PRINTF("%hhd", CHAR_MIN);
//	ASSERT_PRINTF("%hhd", CHAR_MIN - 42);
////	ASSERT_PRINTF("%hhi%hhi", 0, 42);
//	ASSERT_PRINTF("%hhd", CHAR_MAX);
//	ASSERT_PRINTF("%hhd", CHAR_MAX + 42);
//	ASSERT_PRINTF("%hhi", CHAR_MIN);
//	ASSERT_PRINTF("%hhi", CHAR_MIN - 42);
////	ASSERT_PRINTF("%hhu, %hhu", 0, UCHAR_MAX);
////	ASSERT_PRINTF("%hhx, %hhx", 0, UCHAR_MAX);
////	ASSERT_PRINTF("%hhX, %hhX", 0, UCHAR_MAX);
////	ASSERT_PRINTF("%hhu, %hhu", 0, UCHAR_MAX + 42);
////	ASSERT_PRINTF("%hhx, %hhx", 0, UCHAR_MAX + 42);
////	ASSERT_PRINTF("%hhX, %hhX", 0, UCHAR_MAX + 42);
}

void test_moulitest_45(void)
{
////	ASSERT_PRINTF("%lp", 42);
}

void test_moulitest_50(void)
{
	ASSERT_PRINTF("{%10d}", 42);
	ASSERT_PRINTF("{%4d}", 10000);
	ASSERT_PRINTF("{%30d}", 10000);
	ASSERT_PRINTF("{%10d}", -42);
	ASSERT_PRINTF("{%3c}", 0);
//	ASSERT_PRINTF("{%5p}", 0);
//	ASSERT_PRINTF("{%-15p}", 0);
	ASSERT_PRINTF("{%-13p}", &strlen);
	ASSERT_PRINTF("{%-12p}", &strlen);
}

void test_moulitest_51(void)
{
	ASSERT_PRINTF("{%-10d}", 42);
	ASSERT_PRINTF("{%-4d}", 10000);
	ASSERT_PRINTF("{%-30d}", 10000);
}

void test_moulitest_52(void)
{
	ASSERT_PRINTF("{%010d}", -42);
	ASSERT_PRINTF("{%04d}", 10000);
	ASSERT_PRINTF("{%030d}", 10000);
	ASSERT_PRINTF("{%030x}", 0xFFFF);
	ASSERT_PRINTF("{%030X}", 0xFFFF);
}

void test_moulitest_60(void)
{
	ASSERT_PRINTF("%#x", 42);
	ASSERT_PRINTF("%#x", 0);
	ASSERT_PRINTF("%#x", INT_MAX);
	ASSERT_PRINTF("%#X", 42);
	ASSERT_PRINTF("%#X", 0);
	ASSERT_PRINTF("%#X", INT_MAX);
//	ASSERT_PRINTF("%#c", 0);
}

void test_moulitest_61(void)
{
	ASSERT_PRINTF("%+d", 42);
	ASSERT_PRINTF("%+d", -42);
	ASSERT_PRINTF("%+i", 42);
	ASSERT_PRINTF("%+i", -42);
	ASSERT_PRINTF("% d", 9999);
	ASSERT_PRINTF("% d", -9999);
	ASSERT_PRINTF("% i", 9999);
	ASSERT_PRINTF("% i", -9999);
}

void test_moulitest_69(void)
{
#ifdef FT_PRINTF_TEST_BONUS
//	ASSERT_PRINTF("{% +d}", 42);
//	ASSERT_PRINTF("{%+ d}", 42);
	ASSERT_PRINTF("{%+03d}", 0);
	ASSERT_PRINTF("{% 03d}", 0);
	ASSERT_PRINTF("{%+03d}", 12);
	ASSERT_PRINTF("{%+03d}", 123456);
#endif
//	ASSERT_PRINTF("{%0-3d}", 0);
	ASSERT_PRINTF("{%03.2d}", 0);
}

void test_moulitest_70(void)
{
	ASSERT_PRINTF("%.4d", 42);
	ASSERT_PRINTF("%.4d", 424242);
	ASSERT_PRINTF("%.4d", -424242);
	ASSERT_PRINTF("%15.4d", 42);
	ASSERT_PRINTF("%15.4d", 424242);
	ASSERT_PRINTF("%8.4d", 424242424);
	ASSERT_PRINTF("%15.4d", -42);
	ASSERT_PRINTF("%15.4d", -424242);
	ASSERT_PRINTF("%8.4d", -424242424);
	ASSERT_PRINTF("%4.15d", 42);
	ASSERT_PRINTF("%4.15d", 424242);
	ASSERT_PRINTF("%4.8d", 424242424);
	ASSERT_PRINTF("%4.15d", -42);
	ASSERT_PRINTF("%4.15d", -424242);
	ASSERT_PRINTF("%4.8d", -424242424);
	ASSERT_PRINTF("%.d, %.0d", 0, 0);
	ASSERT_PRINTF("%.10d", -42);
	ASSERT_PRINTF("%.4i", 42);
	ASSERT_PRINTF("%15.4i", 42);
	ASSERT_PRINTF("%4.15i", 42);
	ASSERT_PRINTF("%.i, %.0i", 0, 0);
	ASSERT_PRINTF("%.4u", 42);
	ASSERT_PRINTF("%.4u", 424242);
	ASSERT_PRINTF("%15.4u", 42);
	ASSERT_PRINTF("%15.4u", 424242);
	ASSERT_PRINTF("%8.4u", 424242424);
	ASSERT_PRINTF("%4.15u", 42);
	ASSERT_PRINTF("%4.15u", 424242);
	ASSERT_PRINTF("%4.8u", 424242424);
	ASSERT_PRINTF("%.u, %.0u", 0, 0);
}

void test_moulitest_71(void)
{
	ASSERT_PRINTF("%.4x", 42);
	ASSERT_PRINTF("%.4x", 424242);
	ASSERT_PRINTF("%15.4x", 42);
	ASSERT_PRINTF("%15.4x", 424242);
	ASSERT_PRINTF("%8.4x", 424242424);
	ASSERT_PRINTF("%4.15x", 42);
	ASSERT_PRINTF("%4.15x", 42424242);
	ASSERT_PRINTF("%4.8x", 424242424);
	ASSERT_PRINTF("%.x, %.0x", 0, 0);
	ASSERT_PRINTF("%.4X", 42);
	ASSERT_PRINTF("%.4X", 424242);
	ASSERT_PRINTF("%15.4X", 42);
	ASSERT_PRINTF("%15.4X", 424242);
	ASSERT_PRINTF("%8.4X", 424242424);
	ASSERT_PRINTF("%4.15X", 42);
	ASSERT_PRINTF("%4.15X", 424242);
	ASSERT_PRINTF("%4.8X", 424242424);
	ASSERT_PRINTF("%.X, %.0X", 0, 0);
}

void test_moulitest_72(void)
{
	ASSERT_PRINTF("%.4s", "42");
	ASSERT_PRINTF("%.4s", "42 is the answer");
	ASSERT_PRINTF("%15.4s", "42");
	ASSERT_PRINTF("%15.4s", "I am 42");
	ASSERT_PRINTF("%15.4s", "42 is the answer");
	ASSERT_PRINTF("%4.15s", "42");
	ASSERT_PRINTF("%4.15s", "I am 42");
	ASSERT_PRINTF("%4.15s", "42 is the answer");
	ASSERT_PRINTF("%4.s", "42");
}

void test_moulitest_73(void)
{
	ASSERT_PRINTF("%.c", 0);
//	ASSERT_PRINTF("%.5c", 0);
//	ASSERT_PRINTF("%.5c", 42);
}

void test_moulitest_74(void)
{
//////	ASSERT_PRINTF("%.0p, %.p", 0, 0);
////	ASSERT_PRINTF("%.5p", 0);
////	ASSERT_PRINTF("%9.2p", 1234);
////	ASSERT_PRINTF("%9.2p", 1234567);
////	ASSERT_PRINTF("%2.9p", 1234);
////	ASSERT_PRINTF("%2.9p", 1234567);
}

void test_moulitest_79(void)
{
#ifdef FT_PRINTF_TEST_BONUS
	ASSERT_PRINTF("%#.x, %#.0x", 0, 0);
	ASSERT_PRINTF("{%#.5x}", 1);
#endif
//////	ASSERT_PRINTF("%.p, %.0p", 0, 0);
}

void test_moulitest_90(void)
{
#ifdef FT_PRINTF_TEST_BONUS
////	ASSERT_PRINTF("%hhd - %hhd", SHRT_MAX - 42,  SHRT_MAX - 4200);
#endif
}

void test_moulitest_91(void)
{
	ASSERT_PRINTF("%u", -42);
	ASSERT_PRINTF("%u", UINT_MAX + 1);
	ASSERT_PRINTF("%c", 200);
//	ASSERT_PRINTF("%hhu / %hhu", SHRT_MAX - 42,  SHRT_MAX - 4200);
}

void test_moulitest_wildcard_01(void)
{
	ASSERT_PRINTF("%*d", 5, 42);
	ASSERT_PRINTF("{%*d}", -5, 42);
	ASSERT_PRINTF("{%*d}", 0, 42);
	ASSERT_PRINTF("{%*c}", 0, 0);
	ASSERT_PRINTF("{%*c}", -15, 0);
	ASSERT_PRINTF("{%.*d}", 5, 42);
	ASSERT_PRINTF("{%.*d}", -5, 42);
	ASSERT_PRINTF("{%.*d}", 0, 42);
	ASSERT_PRINTF("{%.*s}", 5, "42");
	ASSERT_PRINTF("{%.*s}", -5, "42");
	ASSERT_PRINTF("{%.*s}", 0, "42");
//	ASSERT_PRINTF("{%*s}", 5, 0);
//	ASSERT_PRINTF("{%*p}", 10, 0);
}

void test_moulitest_wildcard_02(void)
{
	ASSERT_PRINTF("%*.*d", 0, 3, 0);
}

void test_moulitest_wildcard_03(void)
{
////	ASSERT_PRINTF("{%*3d}", 5, 0);
	ASSERT_PRINTF("{%05.*d}", -15, 42);
}
