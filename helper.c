#include <stdio.h>
#include <unistd.h>
#include "header.h"

#define BUF_SIZE (1 << 10)

int		pipefd[2];
int		saved_stdout = -1;
char	buf[BUF_SIZE + 1] = {0};

void test_setup(void)
{
	if (saved_stdout != -1)
	{
		dup2(saved_stdout, STDOUT_FILENO);
		close(saved_stdout);
		saved_stdout = -1;
		close(pipefd[0]);
		close(pipefd[1]);
	}
	if (pipe(pipefd) != 0)
		exit(EXIT_FAILURE);
	saved_stdout = dup(STDOUT_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
}

void test_tear_down(void)
{
	if (saved_stdout != -1)
	{
		dup2(saved_stdout, STDOUT_FILENO);
		close(saved_stdout);
		saved_stdout = -1;
		close(pipefd[0]);
		close(pipefd[1]);
	}
	fflush(stdout);
}

#include <fcntl.h>
char *read_stdout_buf(void)
{
	fflush(stdout);
	long flags = fcntl(pipefd[0], F_GETFL);
   	flags |= O_NONBLOCK;
   	fcntl(pipefd[0], F_SETFL, flags);
	int ret = read(pipefd[0], buf, BUF_SIZE);
	buf[ret] = '\0';
	fflush(stdout);
	return (buf);
}

void print_buf_ko(char *msg)
{
	print_ko();
	printf("ft_printf(%s) has wrong output\n", msg);
	printf("actual:   \"%s\"\n", user_buf);
	printf("expected: \"%s\"\n", origin_buf);
	fflush(stdout);
}

void print_ret_ko(char *msg)
{
	print_ko();
	printf("ft_printf(%s) has wrong return value\n", msg);
	printf("actual:   %d\n", user_ret);
	printf("expected: %d\n", origin_ret);
	fflush(stdout);
}

void print_signaled_ko(char *msg)
{
	print_ko();
	printf("ft_printf(\"%s\") has been signaled (segfault and friends)\n", msg);
	fflush(stdout);
}

inline void print_ok(void) {  printf("[OK]\n"); fflush(stdout); }
inline void print_ko(void) {  printf("[KO] ");  fflush(stdout);}
