NAME		:=	philo

CC			:=	cc
CFLAGS		:=	-Wall -Werror -Wextra -g

INCS		:=	-I inc \
				-I $(LIBFT_DIR)/inc

LIBFT_DIR	:=	lib/libft
LIBFT		:=	$(LIBFT_DIR)/libft.a

LIBS		:=	$(LIBFT)

FILES		:=	philo.c
SRCS		:=	$(addprefix src/, $(FILES))
OBJS		:=	$(addprefix obj/, $(FILES:.c=.o))

all: libft obj $(NAME)

libft:
	@echo "Creating libft needed by $(NAME)"
	@make -s -C $(LIBFT_DIR)

obj:
	@mkdir -p obj

$(NAME): $(OBJS)
	@echo "Compiling: $(NAME)"
	@$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)

obj/%.o: src/%.c
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	@rm -rf obj && echo "Removing: $(NAME) intermediary files"
	@make -s -C $(LIBFT_DIR) fclean

fclean: clean
	@echo "Removing: $(NAME)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, obj, libft
