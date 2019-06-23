# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oboualla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/22 16:56:24 by oboualla          #+#    #+#              #
#    Updated: 2019/06/22 17:04:03 by oboualla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

src = src/*.c
exec = ft_ls
flag = gcc -Wall -Wextra -Werror
libft = libft/libft.a

all : $(exec)

$(exec) :
	make -C libft/
	$(flag) main.c $(src) $(libft) -o $(exec)

clean :
	rm $(exec)
	make clean -C libft/

fclean : clean
	make fclean -C libft/

re : fclean all

