# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 13:17:26 by mdoll             #+#    #+#              #
#    Updated: 2023/01/02 13:09:36 by mdoll            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c pchar.c pstr.c pperc.c pdecint.c pudec.c phex.c pvoidp.c

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

# path to main
MAIN = ./main.c

all: $(NAME)

# runs make in libft folder, copies .a, renames .a, compiles complete libary
$(NAME): $(OBJS)
	@make -C ./libft
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJS)
	
clean:
	cd libft && $(MAKE) clean
	rm -f *.o

fclean: clean
	cd libft && $(MAKE) fclean
	rm -f $(NAME)
	
re: fclean all

# compiles everything and creates executable
gcc: all clean
	@gcc $(CFLAGS) -o executable $(MAIN) libftprintf.a

# compiles everything and runs executable
gcco: all clean
	@gcc $(CFLAGS) -o executable $(MAIN) libftprintf.a
	@ ./executable

# deletes all objects, .a and executable	
call: fclean
	rm -f executable

.PHONY: all clean fclean re gcc call