/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:31:14 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/12 03:30:33 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void		del(t_dfile *lst)
{
	t_dfile *ptr;
	t_dfile *tmp;

	ptr = lst;
	while (ptr)
	{
		tmp = ptr->next;
		ft_strdel(&ptr->file);
		ft_memdel((void*)&ptr);
		ptr = tmp;
	}
}

static void	if_detail(t_pinfo *ptr, t_option op)
{
	t_dfile *flst;

	if (ptr->ptype == IF_DIR)
	{
		flst = ft_lstfile(&ptr->file, ptr->path);
		flst->path = ptr;
	}
	affiche_detail(ptr, op);
}

static void	find_method_aff(t_dfile *flst, t_option op)
{
	if (op.l == 0 && op.g == 0 && op.o == 0)
		affiche_simple(flst, op);
	if (op.o > op.l && op.o > op.g)
		flag_one(flst, op);
	del(flst);
}

void		flag_d(t_pinfo *lst, t_option op)
{
	t_dfile *flst;
	t_pinfo *head;
	t_dfile *ptr;

	flst = NULL;
	head = lst;
	while (lst)
	{
		if ((op.l == 0 && op.g == 0) || (op.o > op.l && op.o > op.g))
		{
			ptr = ft_lstfile(&flst, lst->path);
			ptr->path = lst;
		}
		else
			if_detail(lst, op);
		lst = lst->next;
	}
	if (flst)
		find_method_aff(flst, op);
	ft_plstdel(head);
	exit(0);
}
