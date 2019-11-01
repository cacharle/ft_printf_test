#ifndef FT_PRINTF_TEST_HEADER_H
# define FT_PRINTF_TEST_HEADER_H

# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>

# define BUF_SIZE 2048

int pid;
bool signaled;
bool origin_signaled;
bool user_signaled;
int origin_ret;
int user_ret;
char *origin_buf;
char *user_buf;

int ft_printf(const char *format, ...);

void print_buf_ko(char *msg);
void print_ret_ko(char *msg);
void print_signaled_ko(char *msg);
void print_ok(void);
void print_ko(void);

/* moulitest functions */
void capture_close_saved_stdout(void);
void capture_stdout(void);
char *capture_stdout_get_buf(void);
void capture_stdout_destroy(void);

# define TEST_SEGFAULT(x) do {            \
	if ((pid = fork()) < 0)               \
	exit(EXIT_FAILURE);                   \
	if (pid == 0) {                       \
		do { x } while(0);                \
		exit(EXIT_SUCCESS);               \
	}                                     \
	wait(&pid);                           \
	signaled = WIFSIGNALED(pid);          \
} while(0);

# define TEST_PRINTF(...) do {                         \
	capture_stdout();                                  \
	TEST_SEGFAULT(                                     \
		origin_ret = printf(__VA_ARGS__);              \
		origin_buf = strdup(capture_stdout_get_buf()); \
	);                                                 \
	origin_signaled = signaled;                        \
	TEST_SEGFAULT(                                     \
		user_ret = ft_printf(__VA_ARGS__);             \
		user_buf = strdup(capture_stdout_get_buf());   \
	);                                                 \
	capture_stdout_destroy();                          \
	user_signaled = signaled;                          \
} while (0);

# define ASSERT_PRINTF(...) do {               \
	TEST_PRINTF(__VA_ARGS__);                  \
	if (!origin_signaled)                      \
		if (user_signaled)                     \
			print_signaled_ko(#__VA_ARGS__);   \
		else                                   \
			print_ok();                        \
	else {                                     \
		if (strcmp(origin_buf, user_buf) != 0) \
			print_buf_ko(#__VA_ARGS__);        \
		else if (origin_ret != user_ret)       \
			print_ret_ko(#__VA_ARGS__);        \
		else                                   \
			print_ko();                        \
	}                                          \
	free(origin_buf);                          \
	free(user_buf);                            \
} while (0);

#endif
