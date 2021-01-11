/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:18:47 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/18 22:15:08 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		swap_node(t_pinfo *nod1, t_pinfo *nod2)
{
	char		*ptr;
	struct stat swap;
	int			snb;

	if (nod1 && nod2)
	{
		ptr = nod1->path;
		nod1->path = nod2->path;
		nod2->path = ptr;
		swap = nod1->info;
		nod1->info = nod2->info;
		nod2->info = swap;
		snb = nod1->ptype;
		nod1->ptype = nod2->ptype;
		nod2->ptype = snb;
	}
}

void			rev_lst(t_pinfo *lst)
{
	t_pinfo *ptr;
	t_pinfo *last;

	if (lst)
	{
		last = lst;
		ptr = lst;
		while (last->next)
			last = last->next;
		while (ptr != last)
		{
			swap_node(ptr, last);
			if ((ptr = ptr->next) == last)
				break ;
			last = last->back;
		}
	}
}

static void		ordre_lexographi(t_pinfo *lst, t_option op)
{
	t_pinfo *cmp;
	t_pinfo *ptr;

	cmp = lst;
	while (cmp)
	{
		ptr = lst;
		while (ptr)
		{
			if (op.u == 0 && cmp->info.st_mtime == ptr->info.st_mtime)
				if (ft_strcmp(cmp->path, ptr->path) < 0)
					swap_node(cmp, ptr);
			if (op.u == 1 && cmp->info.st_atime == ptr->info.st_atime)
				if (ft_strcmp(cmp->path, ptr->path) < 0)
					swap_node(cmp, ptr);
			ptr = ptr->next;
		}
		cmp = cmp->next;
	}
}

void			sort_lsttime(t_pinfo *lst, t_option op)
{
	t_pinfo *ptr;
	t_pinfo *cmp;

	if (lst)
	{
		ptr = lst;
		cmp = lst;
		while (cmp)
		{
			ptr = lst;
			while (ptr)
			{
				if (op.u == 0 && cmp->info.st_mtime > ptr->info.st_mtime)
					swap_node(cmp, ptr);
				if (op.u == 1 && cmp->info.st_atime > ptr->info.st_atime)
					swap_node(cmp, ptr);
				ptr = ptr->next;
			}
			cmp = cmp->next;
		}
		ordre_lexographi(lst, op);
	}
}
