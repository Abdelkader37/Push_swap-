NAME = push_swap
NAME_BONUS = checker
HDR = main.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c op.c op2.c sort.c func.c func2.c ft_split.c ft_atoi.c check_fun.c sort_2.c
Bonus_SRCS = checker.c op_bonus.c op2_bonus.c func_bonus.c func2_bonus.c ft_split_bonus.c ft_atoi_bonus.c check_fun_bonus.c get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
OBJS_bonus = $(Bonus_SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_bonus)
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
