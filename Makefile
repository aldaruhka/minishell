NAME = minishell
SRC = minishell.c \
	echo.c
OBJ = $(SRC:.c=.o)
HEADER = minishell.h

LIBFT = libft.a
LIBFT_DIR = libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: compile_libft $(NAME)

compile_libft:
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT_DIR)/$(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) -lreadline $(OBJ) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

bonus:

PHONY: all $(NAME) clean fclean re bonus