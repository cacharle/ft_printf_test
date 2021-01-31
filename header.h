/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:13:32 by cacharle          #+#    #+#             */
/*   Updated: 2021/01/31 03:03:38 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TEST_HEADER_H
# define FT_PRINTF_TEST_HEADER_H

# include <sys/select.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <signal.h>

extern int  pid;
extern int  pid2;
extern bool signaled;
extern bool origin_signaled ;
extern bool user_signaled ;
extern int  origin_ret;
extern int  user_ret;
extern char *origin_buf;
extern char *user_buf;

extern struct timeval timeout;
extern fd_set input_set;
extern int    timeout_pipe[2];
extern int    fd_read_num;

#define PIPE_WRITE 1
#define PIPE_READ 0

// #define PRINTF_NULL_STR "(nil)"

// int printf_wrapper(const char *format, ...);

void generated_test(void);
void saved_test(void);

int ft_printf(const char *format, ...);

void print_buf_ko(char *msg);
void print_ret_ko(char *msg);
void print_signaled_ko(char *msg);
void print_timeouted(char *msg);
void print_ok(void);
void print_ko(void);
void ft_putstr_non_printable(char *str);

void test_setup(void);
void test_tear_down(void);
char *read_stdout_buf(void);

extern char fd_buf[10];

# define TEST_TIMEOUT(x) do {                                           \
	if ((pid2 = fork()) == -1)                                          \
		exit(EXIT_FAILURE);                                             \
	if (pid2 == 0) {                                                    \
		do { x; } while (0);                                            \
		write(timeout_pipe[PIPE_WRITE], "a", 1);                        \
		exit(EXIT_SUCCESS);                                             \
	}                                                                   \
	FD_ZERO(&input_set);                                                \
	FD_SET(timeout_pipe[PIPE_READ], &input_set);                        \
	fd_read_num = select(FD_SETSIZE, &input_set, NULL, NULL, &timeout); \
	if (fd_read_num == -1)                                              \
		exit(EXIT_FAILURE);                                             \
	if (fd_read_num == 0)                                               \
		kill(pid2, 9);                                                  \
	else {                                                              \
		wait(&pid2);                                                    \
		read(timeout_pipe[PIPE_READ], fd_buf, 1);                       \
	}                                                                   \
} while (0);

# define TEST_SEGFAULT(x) do {   \
	if ((pid = fork()) < 0)      \
		exit(EXIT_FAILURE);      \
	if (pid == 0) {              \
		do { x } while(0);       \
		exit(EXIT_SUCCESS);      \
	}                            \
	wait(&pid);                  \
	signaled = WIFSIGNALED(pid); \
} while(0);

# define TEST_PRINTF(...) do {                            \
	test_setup();                                         \
	TEST_SEGFAULT(                                        \
		origin_ret = printf(__VA_ARGS__);                 \
	);                                                    \
	origin_buf = strdup(read_stdout_buf());               \
	origin_signaled = signaled;                           \
	fd_read_num = 1;                                      \
	TEST_SEGFAULT(                                        \
		TEST_TIMEOUT(user_ret = ft_printf(__VA_ARGS__));  \
	);                                                    \
	user_buf = strdup(read_stdout_buf());                 \
	user_signaled = signaled;                             \
	test_tear_down();                                     \
} while (0)

# define ASSERT_PRINTF(...) do {                       \
	TEST_PRINTF(__VA_ARGS__);                          \
	if (fd_read_num == 0)                              \
		print_timeouted(#__VA_ARGS__);                 \
	else                                               \
	{                                                  \
		if (!origin_signaled && user_signaled)         \
			print_signaled_ko(#__VA_ARGS__);           \
		else if (origin_signaled && user_signaled)     \
			print_ok();                                \
		else if (!origin_signaled && !user_signaled) { \
			if (memcmp(origin_buf, user_buf,           \
					strlen(origin_buf) + 1) != 0)      \
				print_buf_ko(#__VA_ARGS__);            \
			else if (origin_ret != user_ret)           \
				print_ret_ko(#__VA_ARGS__);            \
			else                                       \
			print_ok();                                \
		}                                              \
	}                                                  \
	free(origin_buf);                                  \
	free(user_buf);                                    \
} while(0);

#endif
