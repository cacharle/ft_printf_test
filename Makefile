FT_PRINTF_PATH = ../ft_printf

CC = gcc
CCFLAGS = -Wall -Wextra
LDFLAGS = -L$(FT_PRINTF_PATH) -lftprintf
MAKE = make -j4

NAME = ft_printf_test
RM = rm -f

SRC = main.c helper.c moulitest_read_stdout.c
OBJ = $(SRC:.c=.o)

run: all
	./$(NAME)

all: $(NAME)

$(NAME): ft_printf_all $(OBJ)
	$(CC) $(LDFLAGS) $(CCFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

ft_printf_all:
	$(MAKE) -C $(FT_PRINTF_PATH) all
