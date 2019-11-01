#include <stdio.h>
#include "header.h"

void print_buf_ko(char *msg)
{
	print_ko();
	printf("ft_printf(%s) has wrong output\n", msg);
	printf("actual:   \"%s\"", origin_buf);
	printf("expected: \"%s\"", user_buf);
}

void print_ret_ko(char *msg)
{
	print_ko();
	printf("ft_printf(%s) has wrong return value\n", msg);
	printf("actual:   %d", origin_ret);
	printf("expected: %d", user_ret);
}

void print_signaled_ko(char *msg)
{
	print_ko();
	printf("ft_printf(\"%s\") has been signaled (segfault and friends)\n", msg);
}

inline void print_ok(void) { printf("\033[32m[OK]\033[0m\n"); }
inline void print_ko(void) { printf("\033[31m[KO]\033[0m "); }
