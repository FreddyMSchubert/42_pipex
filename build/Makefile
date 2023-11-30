NAME = ../pipex

SRC = $(shell find ../src -name "*.c")
OBJ = $(SRC:.c=.o)

LIBFT_DIR   := ../submodules/42_libft
FTPRINTF_DIR:= ../submodules/42_ft_printf
FTGNL_DIR   := ../submodules/42_get_next_line

CFLAGS		:= -Wall -Werror -Wextra \
				-Wunreachable-code -Ofast #-g #-fsanitize=address
HEADER		:= -I../include/
LIBS :=		-L$(LIBFT_DIR) -lft \
			-L$(FTPRINTF_DIR) -lftprintf \
			-L$(FTGNL_DIR) -lftgnl

$(NAME): $(OBJ)
	@cc $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
%.o: %.c
	@cc -c $< $(CFLAGS) $(HEADER) -o $@

libft:
	make -C $(LIBFT_DIR)
ftprintf:
	make -C $(FTPRINTF_DIR)
ftgnl:
	make -C $(FTGNL_DIR)

all: libft ftprintf ftgnl $(NAME)
clean:
	make -C $(LIBFT_DIR) clean
	make -C $(FTPRINTF_DIR) clean
	make -C $(FTGNL_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(FTPRINTF_DIR) fclean
	make -C $(FTGNL_DIR) fclean
	rm -f $(NAME)
re: fclean all

comp:
	@make all
	@make clean
	@clear
fcomp:
	@cd ../ && git submodule update --init --recursive
	@cd ../submodules && norminette
	@cd ../include && norminette
	@cd ../src && norminette
	@make re
	@make clean
	@clear

.PHONY: all clean fclean re comp fcomp libft ftprintf ftgnl
