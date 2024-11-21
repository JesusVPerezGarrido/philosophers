NAME		:=	philo

CC			:=	cc
CFLAGS		:=	-Wall -Werror -Wextra -g

INCS		:=	-I inc

FILES		:=	create_forks.c \
				create_philos.c \
				create_settings.c \
				create_table.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_isdigit.c \
				philo.c \
				philo_manager.c \
				monitor_manager.c \
				time_utils.c \
				valid_args.c
SRCS		:=	$(addprefix src/, $(FILES))
OBJS		:=	$(addprefix obj/, $(FILES:.c=.o))

all: obj $(NAME)

obj:
	@mkdir -p obj

$(NAME): $(OBJS)
	@echo "Linking: $(NAME)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

obj/%.o: src/%.c inc/philo.h
	@echo "Compiling: $(notdir $<)"
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	@rm -rf obj && echo "Removing: $(NAME) intermediary files"

fclean: clean
	@echo "Removing: $(NAME)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, obj, libft
