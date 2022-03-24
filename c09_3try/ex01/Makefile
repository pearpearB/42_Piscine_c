NAME = libft.a

CC = gcc

INC = includes

CFLAGS = -Wall -Wextra -Werror

SRCS = 	srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c srcs/ft_swap.c

OBJS = $(SRCS:.c=.o)

.PHONY: all
all : $(NAME)

%.o : %.c
		$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(NAME) : $(OBJS)
		ar -rcs $@ $(OBJS)

.PHONY: clean
clean :
		rm -f $(OBJS)

.PHONY: fclean
fclean : clean
		rm -f $(NAME)

.PHONY: re
re : fclean all
		make all
			
