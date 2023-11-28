NAME = ../pipex

SRC = $(shell find ../src -name "*.c")
OBJ = $(SRC:.c=.o)

CFLAGS		:= -Wall -Werror -Wextra \
				-Wunreachable-code -Ofast -g -fsanitize=address
HEADER		:= -I../include/
LIBS		:=	-L../submodules/42_ft_printf/ -lftprintf

$(NAME): $(OBJ)
	@cc $(CFLAGS) $(LIBS) $(OBJ) -o $(NAME)
%.o: %.c
	@cc -c $< $(CFLAGS) $(HEADER) -o $@

all: $(NAME)
clean:
	@rm -f $(OBJ) $(BOBJ)
fclean: clean
	@rm -f $(NAME)
re: fclean all
fcomp:
	@cd ../include && norminette
	@cd ../src && norminette
	@make re
	@make clean
	@clear
comp:
	@make all
	@make clean
	@clear

.PHONY: all clean fclean re comp
