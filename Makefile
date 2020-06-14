##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## for 42sh
##

SRC	=	src/main.c \
		src/shell.c \
		src/shell_builtins.c \
		src/setenv.c \
		src/unsetenv.c \
		src/exec.c \
		src/cd.c \
		src/error.c \
		src/prep_cmd.c \
		src/redirections.c \
		src/exec_parts.c \
		src/pipe.c \
		src/path.c \
		src/pipe_builtin.c \
		src/seperators.c \
		src/which_where.c \
		src/alias.c \
		src/pipe_error.c \
		src/prompt.c \
		src/echo.c \
		src/echo_clean.c\
		src/echo_flags.c\
		src/alias_exec.c \
		src/shellvar_parser.c \
		src/set_unset.c \
		src/unset.c \
		src/count_to.c  \
		src/cut_to.c	\
		src/repeat.c \
		lib/my_str_to_special_array.c \
		lib/additive.c \
		lib/base_flag_functions.c \
		lib/flag_functions.c \
		lib/my_printf.c \
		lib/part.c \
		lib/simple_flags.c \
		lib/concat_params.c \
		lib/my_find_prime_sup.c \
		lib/my_putnbr_base.c \
		lib/my_showmem.c \
		lib/my_strcat.c \
		lib/my_str_isalpha.c \
		lib/my_strlen.c \
		lib/my_strstr.c \
		lib/my_getnbr.c \
		lib/my_put_nbr.c \
		lib/my_showstr.c \
		lib/my_strcat_char.c \
		lib/my_str_islower.c \
		lib/my_strlowcase.c \
		lib/my_str_to_word_array.c \
		lib/my_isneg.c \
		lib/my_putstr.c \
		lib/my_show_word_array.c \
		lib/my_strcmp.c \
		lib/my_str_isnum.c \
		lib/my_strncat.c \
		lib/my_strupcase.c \
		lib/my_compute_power_rec.c \
		lib/my_is_prime.c \
		lib/my_put_unsigned.c \
		lib/my_sort_int_array.c \
		lib/my_strcpy.c \
		lib/my_str_isprintable.c \
		lib/my_strncmp.c \
		lib/my_swap.c \
		lib/my_compute_square_root.c \
		lib/my_putchar.c \
		lib/my_revstr.c  \
		lib/my_strcapitalize.c \
		lib/my_strdup.c \
		lib/my_str_isupper.c \
		lib/my_strncpy.c

##CFLAGS  += -W -Wall -Wextra -Werror -g3

OBJ	=	$(SRC:.c=.o)

NAME	=	42sh

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		@echo -e "\033[3;34m"
		gcc -o $(NAME) $(OBJ) -g3 -lm

		@echo -e "\033[3;32m"
		@echo "| *|    *|  *******   ******* *|    *|  ******  *      *|      | "
		@echo "| *|    *|        *   *|      |*    *|  *       *      *|      | "
		@echo "| *******   ******|   ******| ****** |  ******  *      *|      | "
		@echo "|       *|  | *             | |*    *|  *       *      *|      | "
		@echo "|       *|  | ******  ******* |*    *|  ******  ****** ******  | "
		@echo -e "\033[0m"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
