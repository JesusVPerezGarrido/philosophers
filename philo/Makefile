NAME		:=	philo

CC			:=	cc
CFLAGS		:=	-Wall -Werror -Wextra -g

INCS		:=	-I inc \

FILES		:=	philo.c \
				validate_args.c \
				ft_atoi.c \
				isdigit.c
SRCS		:=	$(addprefix src/, $(FILES))
OBJS		:=	$(addprefix obj/, $(FILES:.c=.o))

all: obj $(NAME)

obj:
	@mkdir -p obj

$(NAME): $(OBJS)
	@echo "Linking: $(NAME)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

obj/%.o: src/%.c
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	@rm -rf obj && echo "Removing: $(NAME) intermediary files"

fclean: clean
	@echo "Removing: $(NAME)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, obj, libft
