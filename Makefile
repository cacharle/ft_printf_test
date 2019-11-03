FT_PRINTF_PATH = ../ft_printf

CC = gcc
CCFLAGS = -Wall -Wextra -Wno-format
LDFLAGS = -L$(FT_PRINTF_PATH) -lftprintf

NAME = ft_printf_test
PYTHON = python3
RM = rm -f
MAKE = make -j4

SRC = main.c helper.c tests/pft_tests.c tests/moulitest_tests.c
OBJ = $(SRC:.c=.o)

run: all
	./$(NAME) | $(PYTHON) prettier.py

verbose: all
	./$(NAME) | $(PYTHON) prettier.py --verbose

quiet: all
	./$(NAME) | $(PYTHON) prettier.py --quiet

no_clear: all
	./$(NAME) | $(PYTHON) prettier.py --no-clear

raw: all
	./$(NAME)

all: $(NAME)

$(NAME): ft_printf_all clean $(OBJ)
	$(CC) $(LDFLAGS) $(CCFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
	$(MAKE) -C $(FT_PRINTF_PATH) re

ft_printf_all:
	$(MAKE) -C $(FT_PRINTF_PATH) all
