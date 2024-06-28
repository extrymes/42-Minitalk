NAME = libft.a

SRCS = ft_atoi.c

PRINTF_DIR = ft_printf
PRINTF_FILES = ft_printf.c srcs/ft_putchar.c srcs/ft_putstr.c \
	srcs/ft_puthexa.c srcs/ft_putptr.c srcs/ft_putint.c srcs/ft_putuint.c

SRCS += $(addprefix $(PRINTF_DIR)/,$(PRINTF_FILES))

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = cc $(CFLAGS) -g

GRAY = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
RESET = \033[0m

%.o: %.c
	@$(CC) $(CFLAGS) -g -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
