#ifndef FT_PRINTF_TEST_HEADER_H
# define FT_PRINTF_TEST_HEADER_H

# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>

int pid;
bool signaled;
static bool origin_signaled = false;
static bool user_signaled = false;
int origin_ret;
int user_ret;
char *origin_buf;
char *user_buf;

void generated_test(void);
void saved_test(void);

int ft_printf(const char *format, ...);

void print_buf_ko(char *msg);
void print_ret_ko(char *msg);
void print_signaled_ko(char *msg);
void print_ok(void);
void print_ko(void);
void ft_putstr_non_printable(char *str);

void test_setup(void);
void test_tear_down(void);
char *read_stdout_buf(void);

// # define DEBUG

# define TEST_SEGFAULT(x) do { \
	if ((pid = fork()) < 0) \
	exit(EXIT_FAILURE); \
	if (pid == 0) { \
		do { x } while(0); \
		exit(EXIT_SUCCESS); \
	} else { \
		wait(&pid); \
		signaled = WIFSIGNALED(pid); \
	} \
} while(0);

# define TEST_PRINTF(...) do {                  \
	test_setup();                               \
	TEST_SEGFAULT(\
		origin_ret = printf(__VA_ARGS__);       \
	);\
	origin_buf = strdup(read_stdout_buf()); \
	origin_signaled = signaled;                 \
	TEST_SEGFAULT(\
		user_ret = ft_printf(__VA_ARGS__);      \
	);\
	user_buf = strdup(read_stdout_buf());   \
	user_signaled = signaled;                   \
	test_tear_down();                           \
} while (0)

# define ASSERT_PRINTF(...) do {                   \
	TEST_PRINTF(__VA_ARGS__);                      \
	if (!origin_signaled && user_signaled)         \
		print_signaled_ko(#__VA_ARGS__);           \
	else if (origin_signaled && user_signaled)     \
		print_ok(); \
	else if (!origin_signaled && !user_signaled) { \
		if (memcmp(origin_buf, user_buf,           \
			    strlen(origin_buf) + 1) != 0)      \
			print_buf_ko(#__VA_ARGS__);            \
		else if (origin_ret != user_ret)           \
			print_ret_ko(#__VA_ARGS__);            \
		else                                       \
		print_ok(); \
	} \
	if (!origin_signaled) free(origin_buf);        \
	if (!user_signaled) free(user_buf);            \
} while(0);

#endif
