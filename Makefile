FT_PRINTF_PATH = ../ft_printf

CC = gcc
CCFLAGS = -Wall -Wextra -Wno-trigraphs
LDFLAGS = -L$(FT_PRINTF_PATH) -lftprintf

NAME = ft_printf_test
CHECK_LEAKS_NAME = check_leaks
PYTHON = python3
RM = rm -f
MAKE = make -j4

SRC = main.c helper.c tests/pft_tests.c tests/moulitest_tests.c tests/printf_tester_tests.c \
	  tests/printf_tests_tests.c generated.c saved_tests.c
OBJ = $(SRC:.c=.o)

run: all
	./$(NAME) | $(PYTHON) prettier.py

verbose: all
	./$(NAME) | $(PYTHON) prettier.py --verbose

quiet: all
	./$(NAME) | $(PYTHON) prettier.py --quiet

no_clear: all
	./$(NAME) | $(PYTHON) prettier.py --no-clear

interactive: all
	./$(NAME) | $(PYTHON) prettier.py --interactive

raw: all
	./$(NAME)

generate:
	$(PYTHON) generate.py -n 100

.PHONY: check_leaks
check_leaks:
	$(CC) $(LDFLAGS) $(CCFLAGS) -g -o $(CHECK_LEAKS_NAME) check_leaks.c
	valgrind ./$(CHECK_LEAKS_NAME) > /dev/null

check_leaks_verbose:
	$(CC) $(LDFLAGS) $(CCFLAGS) -g -o $(CHECK_LEAKS_NAME) check_leaks.c
	valgrind --leak-check=full ./$(CHECK_LEAKS_NAME) > /dev/null


all: $(NAME)

$(NAME): ft_printf_all $(OBJ) header.h tests/tests.h
	$(CC) $(LDFLAGS) $(CCFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(FT_PRINTF_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(FT_PRINTF_PATH) fclean

re: fclean all
	$(MAKE) -C $(FT_PRINTF_PATH) re

ft_printf_all:
	$(MAKE) -C $(FT_PRINTF_PATH) all
