NAME = push_swap

BNAME = checker

CSRC = ./src/ft_check_error.c \
		./src/oper_push_rotate.c  ./src/oper_rev_rotate.c \
		./src/oper_swap.c ./src/ft_parsing.c \
		./src/ft_free_error.c  ./src/lst_util.c  ./src/ft_split.c \
		./src/ft_checksorted.c ./src/ft_small_sort.c \
		./src/ft_big_sort.c ./src/ft_algo.c \

MAIN = ./src/push_swap.c

OMAIN = $(MAIN:.c=.o)

OBJECT = $(CSRC:.c=.o)

BSRC = ./bonus/checker.c \
		./bonus/get_next_line.c \
		./bonus/get_next_line_utils.c \

BOBJECT = $(BSRC:.c=.o)

CC = cc 

CFLAGS = -Wall -Wextra -Werror 

Include_src = ./src/push_swap.h
Include_bonus = ./bonus/get_next_line.h

%.o: %.c $(Include_src) $(Include_bonus)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECT) $(OMAIN)
	$(CC) $(CFLAGS) $(OBJECT) $(OMAIN) -o $(NAME)

all: $(NAME)

$(BNAME): $(BOBJECT) $(OBJECT)
	$(CC) $(CFLAGS) $(OBJECT) $(BOBJECT) -o $(BNAME)

bonus: $(BNAME)

clean:
	rm -f $(OBJECT) $(BOBJECT) $(OMAIN)

fclean: clean
	rm -rf $(NAME) $(BNAME)

re: fclean all

re_bonus: fclean bonus
