# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oboualla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/22 16:56:24 by oboualla          #+#    #+#              #
#    Updated: 2019/07/13 15:58:49 by oboualla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

src =	project_ls/src/affiche_simple.c project_ls/src/error.c project_ls/src/ft_addpath.c project_ls/src/ft_ls.c \
		project_ls/src/ft_lstfile.c project_ls/src/ft_lstpath.c \
		project_ls/src/ft_pathtypes.c project_ls/src/if_directory.c project_ls/src/if_link.c \
		project_ls/src/make_groups.c project_ls/src/sort_file.c \
		project_ls/affich_detail/add_pwgr.c  project_ls/affich_detail/affiche_detail.c \
		project_ls/affich_detail/print_chmod.c \
		project_ls/affich_detail/print_total.c project_ls/affich_detail/put_st.c \
		project_ls/affich_detail/put_uid_gid.c project_ls/affich_detail/puttime.c \
		project_ls/bonus_flags/couleur.c project_ls/bonus_flags/flag_d.c project_ls/bonus_flags/flag_one.c

exec = ft_ls
flag = gcc -Wall -Wextra -Werror
libft = libft/libft.a

all : $(exec)

$(exec) :
	@make -C libft/
	@$(flag) project_ls/main.c project_ls/sort_lst.c project_ls/addflag.c $(src) $(libft) -o $(exec)

clean :
	@make clean -C libft/

fclean : clean
	@make fclean -C libft/
	@rm $(exec)

re : fclean all

