/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tester_tests.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:15:31 by cacharle          #+#    #+#             */
/*   Updated: 2020/02/28 15:36:08 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../header.h"

void test_printf_tester(void)
{
	int t = 50;
//	char c = 'a';

#ifdef FT_PRINTF_TEST_BONUS
//	ASSERT_PRINTF("p0 % .3s\n", "cccc");
#endif
	ASSERT_PRINTF("pp %.50d\n", 10000);
	ASSERT_PRINTF("p1 %.4s\n", "cccc");
	ASSERT_PRINTF("p2 %.10s\n", "cccc");
	ASSERT_PRINTF("p3 %.4s\n", NULL);
	ASSERT_PRINTF("p4 %.5s\n", "aaaaa");
	ASSERT_PRINTF("p5 %.3d\n", 100);
	ASSERT_PRINTF("p6 %.0d\n", 100);
	ASSERT_PRINTF("p7 %.4d\n", 100);
	ASSERT_PRINTF("p8 %.10d\n", 100);
	ASSERT_PRINTF("p9 %.50d\n", 100);
	ASSERT_PRINTF("p10 %.1d\n", 100);
	ASSERT_PRINTF("p11 %.3d\n", 100);
	ASSERT_PRINTF("p12 %.0d\n", 0);
	ASSERT_PRINTF("p13 %.3i\n", 100);
	ASSERT_PRINTF("p14 %.0i\n", 100);
	ASSERT_PRINTF("p15 %.4i\n", 100);
	ASSERT_PRINTF("p16 %.10i\n", 100);
	ASSERT_PRINTF("p17 %.50i\n", 100);
	ASSERT_PRINTF("p18 %.1i\n", 100);
	ASSERT_PRINTF("p19 %.3x\n", 100);
	ASSERT_PRINTF("p20 %.0x\n", 0);
	ASSERT_PRINTF("p21 %.3x\n", 100);
	ASSERT_PRINTF("p22 %.0x\n", 100);
	ASSERT_PRINTF("p23 %.4x\n", 100);
	ASSERT_PRINTF("p24 %.10x\n", 100);
	ASSERT_PRINTF("p25 %.50x\n", 100);
	ASSERT_PRINTF("p26 %.1x\n", 100);
	ASSERT_PRINTF("p27 %.3x\n", 100);
	ASSERT_PRINTF("p28 %.0x\n", 0);
	ASSERT_PRINTF("p29 %.3u\n", 100);
	ASSERT_PRINTF("p30 %.0u\n", 100);
	ASSERT_PRINTF("p31 %.4u\n", 100);
	ASSERT_PRINTF("p32 %.10u\n", 100);
	ASSERT_PRINTF("p33 %.50u\n", 100);
	ASSERT_PRINTF("p34 %.1u\n", 100);
	ASSERT_PRINTF("p35 %.3u\n", 100);
	ASSERT_PRINTF("p36 %.0u\n", 0);
	ASSERT_PRINTF("%%\n");
	ASSERT_PRINTF("Hello 42 school! %s", NULL);
	ASSERT_PRINTF("%010%");
//	ASSERT_PRINTF("%u", 4294967295);
	ASSERT_PRINTF("%d\n", 2147483647);
//	ASSERT_PRINTF("%d\n", -2147483648);
	ASSERT_PRINTF("%x\n", 2147483647);
//	ASSERT_PRINTF("%x\n", -2147483648);
	ASSERT_PRINTF("%X\n", 2147483647);
//	ASSERT_PRINTF("%X\n", -2147483648);
	ASSERT_PRINTF("%x\n", 0);
	ASSERT_PRINTF("%010x\n", 0);
	ASSERT_PRINTF("%010x\n", 20);
	ASSERT_PRINTF("%010x\n", -20);
	ASSERT_PRINTF("%10x\n", 20);
	ASSERT_PRINTF("%10.2x\n", -20);
	ASSERT_PRINTF("%-10x\n", 50);
	ASSERT_PRINTF("%-15x\n", 0);
	ASSERT_PRINTF("%.1x\n", 500);
	ASSERT_PRINTF("%*.*x\n", 50, 10, 2);
	ASSERT_PRINTF("%x\n", -1);
//	ASSERT_PRINTF("%");
	ASSERT_PRINTF("%40.50d\n", 50);
	ASSERT_PRINTF("%d\n", -589);
	ASSERT_PRINTF("%-4d\n", -2464);
	ASSERT_PRINTF("%.5d\n", -2372);
	ASSERT_PRINTF("%p\n", NULL);
//	ASSERT_PRINTF("%015p\n", NULL);
	ASSERT_PRINTF("%15p\n", NULL);
	ASSERT_PRINTF("%-15p\n", NULL);
	/* ASSERT_PRINTF("ret = %d\n", printf("%%p::[%010d]\n", -8473)); */
	/* ASSERT_PRINTF("ret = %d\n", printf("%%p::[%10d]\n", -8473)); */
	/* ASSERT_PRINTF("ret = %d\n", printf("%%p::[%.5d]\n", -8473)); */
	/* ASSERT_PRINTF("ret = %d\n", printf("%%p::[%01.1d]\n", -8473)); */
	/* ASSERT_PRINTF("ret = %d\n", printf("%%p::[%010.1d]\n", -8473)); */
	/* ASSERT_PRINTF("ret = %d\n", printf("%%p::[%01.50d]\n", -8473)); */
	/* ASSERT_PRINTF("ret = %d\n", printf("%%p::[%1.50d]\n", -8473)); */
	/* ASSERT_PRINTF("ret = %d\n", printf("%%p::[%0100.50d]\n", -8473)); */
	/* ASSERT_PRINTF("ret = %d\n", printf("%%p::[%010d]\n", 8473)); */
	/* ASSERT_PRINTF("ret = %d\n", printf("%%p::[%10d]\n", 8473)); */
	/* ASSERT_PRINTF("ret = %d\n", printf("%%p::[%.5d]\n", 8473)); */
	/* ASSERT_PRINTF("ret = %d\n", printf("%%p::[%01.1d]\n", 8473)); */
	/* ASSERT_PRINTF("ret = %d\n", printf("%%p::[%010.1d]\n", 8473)); */
	/* ASSERT_PRINTF("ret = %d\n", printf("%%p::[%01.50d]\n", 8473)); */
	/* ASSERT_PRINTF("ret = %d\n", printf("%%p::[%1.50d]\n", 8473)); */
	/* ASSERT_PRINTF("ret = %d\n", printf("%%p::[%0100.50d]\n", 8473)); */
	ASSERT_PRINTF("%c", 'a');
	ASSERT_PRINTF("%10c", 't');
	ASSERT_PRINTF("%1c", 'y');
//	ASSERT_PRINTF("%010c", 't');
	ASSERT_PRINTF("%50.2s", "Coucou");
	ASSERT_PRINTF("%50.2s", NULL);
	ASSERT_PRINTF("%5.0s", "Hello");
	ASSERT_PRINTF("%.1s", "Test");
	ASSERT_PRINTF("%10s", NULL);
	ASSERT_PRINTF("%10s", "Ok");
	/* ASSERT_PRINTF("%d\n", printf("Les bornes :  %d, %d\n", -2147483648, 2147483647)); */
	/* ASSERT_PRINTF("%d\n", printf("Les bornes :  %u, %u\n", 0, 4294967295)); */
	/* ASSERT_PRINTF("%d\n", printf("Les bornes :  %x, %x\n", 0, 4294967295)); */
	/* ASSERT_PRINTF("%d\n", printf("1chiffre 1 %d chiffre 2 %d\n", 42, -42)); */
	/* ASSERT_PRINTF("%d\n", printf("2chiffre 1 %   d chiffre 2 % d\n", 42, -42)); */
	/* ASSERT_PRINTF("%d\n\n", printf("4chiffre 1 %-12d chiffre 2 %-12d\n\n", 42, -42)); */
#ifdef FT_PRINTF_TEST_BONUS
	ASSERT_PRINTF("%    i\n", -60);
	ASSERT_PRINTF("%   i\n", -60);
#endif
	ASSERT_PRINTF("%1p\n", &t);
	ASSERT_PRINTF("%1p\n", &t);
	ASSERT_PRINTF("t1 %050d\n", 10);
	ASSERT_PRINTF("t2 %-50d\n", 10);
	ASSERT_PRINTF("t3 %50.0d\n", 10);
	ASSERT_PRINTF("t4 %50.50d\n", 10);
	ASSERT_PRINTF("t5 %50.10d\n", 10);
	ASSERT_PRINTF("t6 %*.*d\n", 50,  5, 10);
	ASSERT_PRINTF("t7 %1.50d\n", -10);
	ASSERT_PRINTF("t8 %1.50d\n", 10);
	ASSERT_PRINTF("t9 %2.2d\n", 10);
	ASSERT_PRINTF("t10 %2.2d\n", -10);
	ASSERT_PRINTF("t12 %.0d\n", 0);
	ASSERT_PRINTF("t13 %01d\n", -20);
	ASSERT_PRINTF("t14 %10d\n", 1000);
	/* ASSERT_PRINTF("%d\n\n", printf("5chiffre 1 %0d chiffre 2 %0d\n\n", 42, -42)); */
	/* ASSERT_PRINTF("%d\n\n", printf("6chiffre 1 %012d chiffre 2 %012d\n\n", 42, -42)); */
	/* ASSERT_PRINTF("%d\n\n", printf("8chiffre 1 %*d chiffre 2 %*d\n\n", 42, 6, 6, 6)); */
	/* ASSERT_PRINTF("%d\n\n", printf("15chiffre 1 %.d chiffre 2 %.d\n\n", 42, -42)); */
	/* ASSERT_PRINTF("%d\n\n", printf("4caractere 1 %12c caractere 2 %12c\n\n", 'a', 'c')); */
	ASSERT_PRINTF("1caractere 1 %c caractere 2 %c\n\n", 'a', 'c');
#ifdef FT_PRINTF_TEST_BONUS
////	ASSERT_PRINTF("3caractere 1 %   c caractere 2 % c\n\n", 'a', 'c');
#endif
	/* ASSERT_PRINTF("%d\n\n", printf("1hexa-maj 1 %X hexa-maj 2 %X\n\n", 42, -42)); */
	/* ASSERT_PRINTF("%d\n\n", printf("3hexa-maj 1 %   X hexa-maj 2 % X\n\n", 42, -42)); */
	/* ASSERT_PRINTF("%d\n\n", printf("4hexa-maj 1 %12X hexa-maj 2 %int12X\n\n", 42, -42)); */
	/* ASSERT_PRINTF("%d\n\n", printf("4hexa-maj 1 %-12X hexa-maj 2 %-12X\n\n", 42, -42)); */
	/* ASSERT_PRINTF("%d\n\n", printf("5hexa-maj 1 %0X hexa-maj 2 %0X\n\n", 42, -42)); */
	/* ASSERT_PRINTF("%d\n\n", printf("6hexa-maj 1 %012X hexa-maj 2 %012X\n\n", 42, -42)); */
	/* ASSERT_PRINTF("%d\n\n", printf("8hexa-maj 1 %*X hexa-maj 2 %*X\n\n", 42, 6, 6, 6)); */
	/* ASSERT_PRINTF("%d\n\n", printf("1pointeur 1 %p pointeur 2 %p\n\n", &c, &c)); */
	/* ASSERT_PRINTF("%d\n\n", printf("3pointeur 1 %   p pointeur 2 % p\n\n", &c, &c)); */
	/* ASSERT_PRINTF("%d\n\n", printf("4pointeur 1 %12p pointeur 2 %12p\n\n", &c, &c)); */
	/* ASSERT_PRINTF("%d\n\n", printf("4pointeur 1 %-12p pointeur 2 %-12p\n\n", &c, &c)); */
	/* ASSERT_PRINTF("%d\n\n", printf("5pointeur 1 %0p pointeur 2 %0p\n\n", &c, &c)); */
	/* ASSERT_PRINTF("%d\n\n", printf("6pointeur 1 %012p pointeur 2 %012p\n\n", &c, &c)); */
	/* ASSERT_PRINTF("%d\n\n", printf("1unsigned 1 %u unsigned 2 %u\n\n", 42, -42)); */
	/* ASSERT_PRINTF("%d\n\n", printf("3unsigned 1 %   u unsigned 2 % u\n\n", 42, -42)); */
	/* ASSERT_PRINTF("%d\n\n", printf("4unsigned 1 %12u unsigned 2 %12u\n\n", 42, -42)); */
	/* ASSERT_PRINTF("%d\n\n", printf("4unsigned 1 %-12u unsigned 2 %-12u\n\n", 42, -42)); */
	/* ASSERT_PRINTF("%d\n\n", printf("5unsigned 1 %0u unsigned 2 %0u\n\n", 42, -42)); */
	/* ASSERT_PRINTF("%d\n\n", printf("6unsigned 1 %012u unsigned 2 %012u\n\n", 42, -42)); */
	/* ASSERT_PRINTF("%d\n\n", printf("8unsigned 1 %*u unsigned 2 %*u\n\n", 42, 6, 6, 6)); */
	/* ASSERT_PRINTF("%d\n\n", printf("15unsigned 1 %.u unsigned 2 %.u\n\n", 42, -42)); */
	/* ASSERT_PRINTF("%d\n\n", printf("%s", 0)); */
	/* ASSERT_PRINTF("%d\n\n", printf("%%\n"));  */
	/* ASSERT_PRINTF("%d\n\n", printf("%-.12u\n", -20000000)); */
	/* ASSERT_PRINTF("%d\n\n", printf("%-.12i\n", -20000000)); */
	/* ASSERT_PRINTF("%d\n", printf("truc")); */
	/* ASSERT_PRINTF("%d\n", printf("bonjour !\n", 42, -42)); */
	ASSERT_PRINTF("04 Test de chiffre sans h : %d, et %d\n", 432767, -432767);
	/* ASSERT_PRINTF("%d\n", printf("03 This is a float : %f\n\n", 45.236)); */
	/* ASSERT_PRINTF("%d\n", printf("02 This is a float : %.3f\n\n", 45.236)); */
	/* ASSERT_PRINTF("%d\n", printf("01 This is a float : %3f\n\n", 45.236)); */
	/* ASSERT_PRINTF("%d\n", printf("000 This is a float : %f\n\n", -45.236)); */
	/* ASSERT_PRINTF("%d\n", printf("0 This is a float : %.3f\n\n", -45.236)); */
	/* ASSERT_PRINTF("%d\n", printf("00 This is a float : %3f\n\n", -45.236)); */
	/* ASSERT_PRINTF("1 This is a float : %f\n\n", 0.00025); */
	/* ASSERT_PRINTF("2 This is a float : %.3f\n\n", 0.00025); */
	/* ASSERT_PRINTF("3 This is a float : %3f\n\n", 0.00025); */
	/* ASSERT_PRINTF("4 This is a float : %f\n\n", -0.00025); */
	/* ASSERT_PRINTF("5 This is a float : %f\n\n", -0.00025); */
	/* ASSERT_PRINTF("6 This is a float : %.3f\n\n", -0.00025); */
	/* ASSERT_PRINTF("7 This is a float : %3f\n\n", -0.00025); */
	/* ASSERT_PRINTF("8 This is a float : %3f\n\n", 1.0 / 0.0); */
	/* ASSERT_PRINTF("9 This is a float : %3f\n\n", -1.0 / 0.0); */
	/* ASSERT_PRINTF("10 This is a float : %3f\n\n", 0.0 / 0.0); */
	/* ASSERT_PRINTF("11 This is a float : %3f\n\n", -0.0 / 0.0); */
	/* ASSERT_PRINTF("12 This is a float : %.0f\n\n", 2.5); */
	/* ASSERT_PRINTF("13 This is a float : %.0f\n\n", 3.5); */
	/* ASSERT_PRINTF("14 This is a float : %.0f\n\n", -2.5); */
	/* ASSERT_PRINTF("15 This is a float : %.0f\n\n", -3.5); */
	/* ASSERT_PRINTF("16 This is a float : %.0f\n\n", 2.51); */
	/* ASSERT_PRINTF("17 This is a float : %.0f\n\n", 3.51); */
	/* ASSERT_PRINTF("18 This is a float : %10.0f\n\n", -2.51); */
	/* ASSERT_PRINTF("19 This is a float : %10.0f\n\n", -3.51); */
	/* ASSERT_PRINTF("20 This is a float : %10.5f\n\n", -2.51); */
	/* ASSERT_PRINTF("21 This is a float : %10.5f\n\n", -3.51); */
	/* ASSERT_PRINTF("22 This is a float : %10.5f\n\n", 2.51); */
	/* ASSERT_PRINTF("23 This is a float : %10.5f\n\n", 3.51); */
	/* ASSERT_PRINTF("24 This is a float : %10.0f\n\n", 2.51); */
	/* ASSERT_PRINTF("25 This is a float : %10.0f\n\n", 3.51); */
	/* ASSERT_PRINTF("26 This is a float : %010f\n\n", 2.51); */
	/* ASSERT_PRINTF("27 This is a float : %-10f\n\n", 3.51); */
	/* ASSERT_PRINTF("28 This is a float : %015f\n\n", 2.51); */
	/* ASSERT_PRINTF("29 This is a float : %15f\n\n", 3.51); */
	/* ASSERT_PRINTF("30 This is a float : %.0f\n\n", 0.0); */
	ASSERT_PRINTF("31 This is an int : %.0d\n\n", 0);
	ASSERT_PRINTF("32 This is an int : %0d\n\n", 0);
	ASSERT_PRINTF("percent 1 %012%");
	ASSERT_PRINTF("percent 2 %12%");
	ASSERT_PRINTF("percent 3 %-12%");
	ASSERT_PRINTF("percent 4 %0%");
#ifdef FT_PRINTF_TEST_BONUS
	ASSERT_PRINTF("percent 5 % %");
	ASSERT_PRINTF("percent 6 % 15%");
	ASSERT_PRINTF("percent 7 % 12%");
	ASSERT_PRINTF("percent 8 %  *%", 13);
	ASSERT_PRINTF("%n", &t);
	ASSERT_PRINTF("test %n", &t);
	ASSERT_PRINTF("%s %n", "hello world", &t);
#endif
	ASSERT_PRINTF("%d\n", t);
//	ASSERT_PRINTF("%n", NULL);
	ASSERT_PRINTF("%d\n", t);
	ASSERT_PRINTF("%d\n", t);
	ASSERT_PRINTF("%d\n", t);
#ifdef FT_PRINTF_TEST_BONUS
//	ASSERT_PRINTF("% .1s %n", "hey", &t);
	ASSERT_PRINTF("%40s %n", "co", &t);
	ASSERT_PRINTF("%050d%n", 500, &t);
#endif
	ASSERT_PRINTF("%d\n", t);
	ASSERT_PRINTF("%d\n", t);
	ASSERT_PRINTF("%d\n", t);
	/* ASSERT_PRINTF("%d\n\n", printf("1string 1 %s string 2 %s\n\n", "toto", "bonjour")); */
	/* ASSERT_PRINTF("%d\n\n", printf("3string 1 %   s string 2 % s\n\n", "toto", "bonjour")); */
	/* ASSERT_PRINTF("%d\n\n", printf("4string 1 %12s string 2 %12s\n\n", "toto", "bonjour")); */
	/* ASSERT_PRINTF("%d\n\n", printf("4string 1 %-12s string 2 %-12s\n\n", "toto", "bonjour")); */
	/* ASSERT_PRINTF("%d\n\n", printf("5string 1 %0s string 2 %0s\n\n", "toto", "bonjour")); */
	/* ASSERT_PRINTF("%d\n\n", printf("6string 1 %012s string 2 %012s\n\n", "toto", "bonjour")); */
	/* ASSERT_PRINTF("%d\n\n", printf("7string 1 %-012s string 2 %012s\n\n", "toto", "bonjour")); */
	ASSERT_PRINTF("st1 %*.*d\n", 10, 10, 50);
	ASSERT_PRINTF("st2 %*.*d\n", 1, 50, 50);
	ASSERT_PRINTF("st3 %*.*d\n", 0, 0, 50);
	ASSERT_PRINTF("st4 %*.*d\n", 0, 50, 50);
	ASSERT_PRINTF("st5 %*.*d\n", 10, 0, 50);
	ASSERT_PRINTF("st6 %*.*d\n", 10, 10, 50);
	ASSERT_PRINTF("st12 %*d\n", 10, 50);
	ASSERT_PRINTF("st13 %*d\n", 0, 0);
	ASSERT_PRINTF("st14 %.*d\n", 0, 0);
	ASSERT_PRINTF("st15 %*d\n", 50, 5);
	ASSERT_PRINTF("st16 %0.*d\n", 50, 5);
	ASSERT_PRINTF("st17 %0.*d\n", 0, 0);
	ASSERT_PRINTF("st7 %*.*s\n", 1, 50, "hey");
	ASSERT_PRINTF("st8 %*.*s\n", 0, 0, "coucou");
	ASSERT_PRINTF("st9 %*.*s\n", 0, 50, "hey");
	ASSERT_PRINTF("st10 %*.*s\n", 10, 0, "dsa");
	ASSERT_PRINTF("st11 %*.*s\n", 10, 10, "hello");
//	ASSERT_PRINTF("st7 %0.*s\n", 50, "hey");
	ASSERT_PRINTF("st8 %.*s\n", 0, "coucou");
	ASSERT_PRINTF("st9 %*s\n", 0, "hey");
	ASSERT_PRINTF("st10 %*s\n", 10, "dsa");
	ASSERT_PRINTF("st118 %*s\n", 100, "hello");
	ASSERT_PRINTF("st119 %*s\n", 1000, "hello");
	ASSERT_PRINTF("st120 %*s\n", 10000, "hello");
	/* ASSERT_PRINTF("st121 %*s\n", 100000, "hello"); */ // can't read so much for now
	ASSERT_PRINTF("st118 %*d\n", 100, 0);
	ASSERT_PRINTF("st119 %*d\n", 1000, 10);
	ASSERT_PRINTF("st120 %*d\n", 10000, 467);
	/* ASSERT_PRINTF("st121 %*d\n", 100000, -589); */
	ASSERT_PRINTF("ultimate1 %*d        %*i\n", 500, 0, 10, 10);
	ASSERT_PRINTF("ultimate2 %*d %*s %*x %*X %*i %*u\n", 1, 5000, 1, "hey", 10, 54700, 1, 300, 10000, -55, 1, -60);
	ASSERT_PRINTF("ultimate3 %*.*d %*.*s\n", 1, 50, 5000, 1, 0, "hey");
	ASSERT_PRINTF("ultimate4 %*.*x %*.*X\n", 1, 50, 5000, 1, 0, 10);
	ASSERT_PRINTF("ultimate5 %*.*u\n", 1, 50, 5000);
	ASSERT_PRINTF("neg1 %*s\n", -9, "coucou");
	ASSERT_PRINTF("neg2 %*.*s\n", -9, 4, "coucou");
	ASSERT_PRINTF("neg3 %*s\n", -9, NULL);
	ASSERT_PRINTF("neg4 %*.*s\n", 0, 0, "coucou");
	ASSERT_PRINTF("neg5 %*s\n", -100, "coucou");
	ASSERT_PRINTF("neg6 %*s\n", -156, "coucou");
	ASSERT_PRINTF("neg7 %*.*s\n", -1586, 15, "coucou");
	ASSERT_PRINTF("neg8 %*.*s\n", -1586, 15, "coucou");
	ASSERT_PRINTF("neg9 %*.*s\n", 15856, 155, "coucou");
	ASSERT_PRINTF("neg10 %*.*s\n", -15586, 15, "coucou");
	ASSERT_PRINTF("neg11 %*.*s\n", -15586, 15, "coucou");
	ASSERT_PRINTF("neg1 %*d\n", -9, 150);
	ASSERT_PRINTF("neg2 %*.*d\n", -9, 4, 1555);
	ASSERT_PRINTF("neg3 %*d\n", -9, -255);
	ASSERT_PRINTF("neg4 %*.*d\n", 0, 0, -30);
	ASSERT_PRINTF("neg5 %*d\n", -100, -589);
	ASSERT_PRINTF("neg6 %*d\n", -156, 15555);
	ASSERT_PRINTF("neg7 %*.*d\n", -1586, 15, 0);
	ASSERT_PRINTF("neg8 %*.*d\n", -1586, 15, 300);
	ASSERT_PRINTF("neg9 %*.*d\n", 15856, 155, -3000);
	ASSERT_PRINTF("neg10 %*.*d\n", -15586, 15, 150);
	ASSERT_PRINTF("neg11 %*.*d\n", -15586, 15, 0);
	ASSERT_PRINTF("***************%*s%*d**************%*u*************", 10, "coucou", 10, 10, -50, 20);
	ASSERT_PRINTF("taaa %100s\n", "hello");
}
