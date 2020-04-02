/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:13:38 by cacharle          #+#    #+#             */
/*   Updated: 2020/04/02 20:31:04 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "header.h"

#define BUF_SIZE (1 << 16)

int		pipefd[2];
int		saved_stdout = -1;
char	buf[BUF_SIZE + 1] = {0};

void test_setup(void)
{
	origin_buf = NULL;
	user_buf = NULL;
	if (saved_stdout != -1)
		test_tear_down();
	saved_stdout = dup(STDOUT_FILENO);
	if (pipe(pipefd) != 0)
		exit(EXIT_FAILURE);
	dup2(pipefd[1], STDOUT_FILENO);
	long flags = fcntl(pipefd[0], F_GETFL);
   	flags |= O_NONBLOCK;
   	fcntl(pipefd[0], F_SETFL, flags);
}

void test_tear_down(void)
{
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);
	saved_stdout = -1;
	close(pipefd[0]);
	close(pipefd[1]);
}

char *read_stdout_buf(void)
{
	fflush(stdout);
	bzero(buf, BUF_SIZE + 1);
	int ret = read(pipefd[0], buf, BUF_SIZE);
	if (ret != -1)
		buf[ret] = '\0';
	return (buf);
}

void print_buf_ko(char *msg)
{
	printf("FAIL/OUTPUT<>ARGS:%s", msg);
	fflush(stdout);
	printf("<>EXPECTED:\"");
	fflush(stdout);
	ft_putstr_non_printable(origin_buf);
	printf("\"<>ACTUAL:\"");
	fflush(stdout);
	ft_putstr_non_printable(user_buf);
	printf("\"\n");
	fflush(stdout);
}

void print_ret_ko(char *msg)
{
	printf("FAIL/RETURN<>ARGS:%s<>EXPECTED:%d<>ACTUAL%d\n", msg, origin_ret, user_ret);
	fflush(stdout);
}

void print_signaled_ko(char *msg)
{
	printf("FAIL/SEGFAULT<>ARGS:%s<>EXPECTED:<>ACTUAL:\n", msg);
	fflush(stdout);
}

void print_timeouted(char *msg)
{
	printf("FAIL/TIMEOUT<>ARGS:%s<>EXPECTED:<>ACTUAL:\n", msg);
	fflush(stdout);
}

inline void print_ok(void) {  printf("OK\n"); fflush(stdout); }

void ft_putstr_non_printable(char *str)
{
	unsigned char	tmp;
	unsigned char	*cursor;
	char			*hex_symbols;

	hex_symbols = "0123456789abcdef";
	cursor = (unsigned char*)str;
	while (*cursor != '\0')
	{
		if (*cursor >= ' ' && *cursor <= '~')
			write(1, cursor, 1);
		else if (*cursor == '\n')
			printf("\\n");
		else if (*cursor == '\r')
			printf("\\r");
		else if (*cursor == '\t')
			printf("\\t");
		else if (*cursor == '\v')
			printf("\\v");
		else if (*cursor == '\0')
			printf("\\0");
		else
		{
			putchar('\\');
			tmp = *cursor / 16;
			putchar(hex_symbols[tmp]);
			tmp = *cursor % 16;
			putchar(hex_symbols[tmp]);
		}
		cursor++;
	}
}
