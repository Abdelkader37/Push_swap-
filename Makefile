NAME = push_swap
NAME_BONUS = checker
HDR = main.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c op.c op2.c sort.c func.c func2.c ft_split.c ft_atoi.c check_fun.c
Bonus_SRCS = checker.c op.c op2.c func.c func2.c ft_split.c ft_atoi.c check_fun.c get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
OBJS_bonus = $(Bonus_SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus : $(OBJS_bonus)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_bonus)

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	rm -f $(NAME) $(OBJS) $(NAME_BONUS) $(OBJS_bonus)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_bonus)

re: fclean all

.PHONY: all clean fclean re bonus
