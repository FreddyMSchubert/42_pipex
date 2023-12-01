# Project: pipex

NAME = ./pipex
BONUS_NAME = ./pipex_bonus

SRC = $(shell find ./src -name "*.c")
OBJ = $(SRC:.c=.o)

BONUS_SRC = $(shell find ./src ./src_bonus -name "*.c" ! -name "pipex.c")
BONUS_OBJ = $(BONUS_SRC:.c=.o)

LIBFT_DIR   := ./submodules/42_libft
FTPRINTF_DIR:= ./submodules/42_ft_printf
FTGNL_DIR   := ./submodules/42_get_next_line

CFLAGS		:= -Wall -Werror -Wextra \
				#-Wunreachable-code -Ofast #-g #-fsanitize=address
HEADER		:= -I../include/
LIBS :=		-L$(LIBFT_DIR) -lft \
			-L$(FTPRINTF_DIR) -lftprintf \
			-L$(FTGNL_DIR) -lftgnl

$(NAME): $(OBJ)
	@cc $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
$(BONUS_NAME): $(BONUS_OBJ)
	@cc $(CFLAGS) $(BONUS_OBJ) $(LIBS) -o $(BONUS_NAME)
%.o: %.c
	@cc -c $< $(CFLAGS) $(HEADER) -o $@

libft:
	make -C $(LIBFT_DIR)
ftprintf:
	make -C $(FTPRINTF_DIR)
ftgnl:
	make -C $(FTGNL_DIR)

all: libft ftprintf ftgnl $(NAME)
bonus: libft ftprintf ftgnl $(BONUS_NAME)
re: fclean all bonus

comp:
	@make all
	@make clean
	@clear
fcomp:
	@cd ./ && git submodule update --init --recursive
	@cd ./submodules && norminette
	@cd ./include && norminette
	@cd ./src && norminette
	@cd ./src_bonus && norminette
	@make re
	@make clean
	@clear

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(FTPRINTF_DIR) clean
	make -C $(FTGNL_DIR) clean
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(FTPRINTF_DIR) fclean
	make -C $(FTGNL_DIR) fclean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

.PHONY: all clean fclean re comp fcomp libft ftprintf ftgnl bonus
