/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:34:07 by oboualla          #+#    #+#             */
/*   Updated: 2019/08/04 20:19:36 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ft_plstdel(t_pinfo *lst)
{
	t_pinfo *ptr;
	t_pinfo *tmp;

	ptr = lst;
	while (ptr)
	{
		tmp = ptr->next;
		if (ptr->file)
		{
			ft_strdel(&ptr->file->file);
			ft_memdel((void**)&ptr->file);
		}
		ft_memdel((void**)&ptr);
		ptr = tmp;
	}
}

void	complet_job(t_pinfo *ptr, t_dfile **flst, t_option op)
{
	t_dfile *ptr2;

	if (ptr->ptype == IF_LINK && !ptr->file)
	{
		if_link(ptr);
		ptr->file->path = ptr;
	}
	if (op.l > op.o || op.g > op.o)
		affiche_detail(ptr, op);
	else
	{
		ptr2 = ft_lstfile(&*flst, ptr->path);
		ptr2->path = ptr;
	}
}

int		affich_no_dir(t_pinfo *lst, t_option op)
{
	t_dfile *flst;
	int		flag;

	flag = 0;
	flst = NULL;
	while (lst)
	{
		if (lst->ptype != IF_DIR && (lst->ptype != IF_LINK ||
			(op.l == 1 && op.l > op.o) || lst->file))
		{
			complet_job(lst, &flst, op);
			flag = 1;
		}
		lst = lst->next;
	}
	if (flst)
	{
		if (op.o == 0)
			affiche_simple(flst, op);
		else
			flag_one(flst, op);
		del(flst);
	}
	return (flag);
}

void	ft_ls(t_pinfo *lst, t_option op)
{
	t_pinfo *pt;
	int		flag;

	pt = lst;
	if ((flag = affich_no_dir(lst, op)) == 1 && (lst->ptype == IF_DIR ||
		(lst->ptype == IF_LINK && !pt->file)))
		ft_putchar('\n');
	while (pt)
	{
		if (pt->ptype == IF_DIR ||
			(pt->ptype == IF_LINK && !pt->file && op.l == 0))
		{
			if (lst->next)
			{
				ft_putstr(pt->path);
				ft_putendl(":");
			}
			if_directory(pt, op);
		}
		if ((pt = pt->next) && pt->ptype == IF_DIR)
			ft_putchar('\n');
	}
	ft_plstdel(lst);
	exit(0);
}
