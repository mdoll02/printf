# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 13:17:26 by mdoll             #+#    #+#              #
#    Updated: 2022/12/30 15:01:38 by mdoll            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c pchar.c pstr.c pperc.c pdecint.c

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

# LIBS = -L./libft -lft

all: $(NAME)

$(NAME): $(OBJS)
# make -C ./libft
# gcc $(CFLAGS) -c $(SRC)  && ar -rcs $(NAME) $(OBJS) ./libft/libft.a
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

gcc: all clean
	@gcc $(CFLAGS) -o executable main.c libftprintf.a

gcco: all clean
	@gcc $(CFLAGS) -o executable main.c libftprintf.a
	@ ./executable
	
call: fclean
	rm -f executable

.PHONY: all clean fclean re gcc call