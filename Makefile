# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacharle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/06 18:13:15 by cacharle          #+#    #+#              #
#    Updated: 2020/04/02 20:50:47 by charles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_PRINTF_PATH = ../ft_printf

CC = gcc
CCFLAGS = -Wall -Wextra -Wno-trigraphs
LDFLAGS = -L$(FT_PRINTF_PATH) -lftprintf

NAME = ft_printf_test
CHECK_LEAKS_NAME = check_leaks
RM = rm -f
MAKE = make

PYTHON = python3
# ifeq ($(shell $(PYTHON) --version | cut -d ' ' -f 2 | cut -d '.' -f 1),2)
# PYTHON = python3
# $(error You must have python3 installed)
# endif

SRC = main.c helper.c tests/pft_tests.c tests/moulitest_tests.c tests/printf_tester_tests.c \
	  tests/printf_tests_tests.c saved_tests.c generated.c
OBJ = $(SRC:.c=.o)

run: all
	./$(NAME) | $(PYTHON) prettier.py

runbonus: allbonus run

verbose: all
	./$(NAME) | $(PYTHON) prettier.py --verbose

verbosebonus: allbonus verbose

quiet: all
	./$(NAME) | $(PYTHON) prettier.py --quiet

quietbonus: allbonus quiet

no_clear: all
	./$(NAME) | $(PYTHON) prettier.py --no-clear

no_clearbonus: allbonus no_clear

interactive: all
	./$(NAME) | $(PYTHON) prettier.py --interactive

interactivebonus: allbonus interactive

raw: all
	./$(NAME)

rawbonus: allbonus raw

generate:
	$(PYTHON) generate.py -n 100

generatebonus:
	$(PYTHON) generate.py -n 100 --bonus

.PHONY: check_leaks
check_leaks:
	$(CC) $(CCFLAGS) -g -o $(CHECK_LEAKS_NAME) check_leaks.c $(LDFLAGS)
	valgrind ./$(CHECK_LEAKS_NAME) > /dev/null

check_leaks_verbose:
	$(CC) $(CCFLAGS) -g -o $(CHECK_LEAKS_NAME) check_leaks.c $(LDFLAGS)
	valgrind --leak-check=full ./$(CHECK_LEAKS_NAME) > /dev/null


all: $(NAME)

allbonus: CCFLAGS += -D FT_PRINTF_TEST_BONUS
allbonus: ft_printf_all ft_printf_bonus $(NAME)

$(NAME): ft_printf_all $(OBJ)
	$(CC) $(CCFLAGS) -o $@ $(OBJ) $(LDFLAGS)

%.o: %.c header.h tests/tests.h
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(FT_PRINTF_PATH) fclean

re: fclean all

ft_printf_all:
	$(MAKE) -C $(FT_PRINTF_PATH) all

ft_printf_bonus:
	$(MAKE) -C $(FT_PRINTF_PATH) bonus
