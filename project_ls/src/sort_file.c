/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 14:02:05 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/12 03:05:45 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static int	swap_struct(t_dfile *ptr1, t_dfile *ptr2)
{
	t_pinfo *swp;
	char	*ptr3;

	if (ptr1 && ptr2)
	{
		ptr3 = ptr1->file;
		ptr1->file = ptr2->file;
		ptr2->file = ptr3;
		swp = ptr1->path;
		ptr1->path = ptr2->path;
		ptr2->path = swp;
	}
	return (1);
}

static void	ordre_lexographical(t_dfile *lst, t_option op)
{
	t_dfile *cmp;
	t_dfile *ptr;

	cmp = lst;
	while (cmp)
	{
		ptr = lst;
		while (ptr)
		{
			if (op.u == 0 &&
					cmp->path->info.st_mtime == ptr->path->info.st_mtime)
				if (ft_strcmp(cmp->file, ptr->file) < 0)
					swap_struct(cmp, ptr);
			if (op.u == 1 &&
					cmp->path->info.st_atime == ptr->path->info.st_atime)
				if (ft_strcmp(cmp->file, ptr->file) < 0)
					swap_struct(cmp, ptr);
			ptr = ptr->next;
		}
		cmp = cmp->next;
	}
}

void		ordre_ascii(t_dfile *list)
{
	t_dfile *ptr;
	t_dfile *tmp;

	if (list)
	{
		tmp = list;
		while (tmp)
		{
			ptr = list;
			while (ptr)
			{
				if (ft_strcmp(tmp->file, ptr->file) < 0)
					swap_struct(tmp, ptr);
				ptr = ptr->next;
			}
			tmp = tmp->next;
		}
	}
}

void		ordre_rev(t_dfile *lst)
{
	t_dfile *ptr;
	t_dfile *tmp;

	if (lst)
	{
		tmp = lst;
		ptr = lst;
		while (tmp->next)
			tmp = tmp->next;
		while (ptr && tmp && ptr != tmp)
		{
			swap_struct(ptr, tmp);
			if ((ptr = ptr->next) == tmp)
				break ;
			tmp = tmp->back;
		}
	}
}

void		ordre_time(t_dfile *lst, t_option op)
{
	t_dfile *ptr;
	t_dfile *cmp;

	cmp = lst;
	while (cmp)
	{
		ptr = lst;
		while (ptr)
		{
			if (op.u == 0 &&
					cmp->path->info.st_mtime > ptr->path->info.st_mtime)
				swap_struct(cmp, ptr);
			else if (op.u == 1 &&
					cmp->path->info.st_atime > ptr->path->info.st_atime)
				swap_struct(cmp, ptr);
			ptr = ptr->next;
		}
		cmp = cmp->next;
	}
	ordre_lexographical(lst, op);
}
