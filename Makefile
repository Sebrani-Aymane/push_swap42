CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c parsing.c stack_tools.c stack_inits.c set_target.c \
		push_cmds.c  \
		rev_rotate_cmmds.c rotate_cmmds.c\
		small_sort.c split.c \
		swap_cmmds.c main.c mooore.c joiner.c

OBJS = $(SRCS:.c=.o)
NAME = push_swap


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all