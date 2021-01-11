/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_detail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 08:46:59 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/15 22:53:30 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"
#include "mini.h"

static void	put_major_minor(dev_t rdev)
{
	unsigned int major;
	unsigned int minor;

	major = major(rdev);
	minor = minor(rdev);
	put_st((unsigned long int)major, 2);
	ft_putstr(", ");
	put_st((unsigned long int)minor, 3);
}

static void	print_iflink(t_dfile *ptr)
{
	if (ft_strcmp(ptr->file, ptr->path->file->file))
	{
		ft_putstr(ptr->file);
		ft_putstr("\033[0m");
		ft_putstr(" -> ");
		ft_putstr(ptr->path->file->file);
	}
	else
	{
		ft_putstr(ptr->path->path);
		ft_putstr("\033[0m");
		ft_putstr(" -> ");
		ft_putstr(ptr->file);
	}
}

static void	detail(t_dfile *ptr, t_pwgr **this,
		unsigned int *long1, t_option op)
{
	print_chmod((int)ptr->path->info.st_mode, ptr->path->ptype);
	affich_acl(ptr->path->path);
	ft_putchar(' ');
	put_st((unsigned long int)ptr->path->info.st_nlink, long1[0]);
	ft_putchar(' ');
	put_uid_gid(ptr, this, op);
	if (ptr->path->ptype != IF_CHR && ptr->path->ptype != IF_BLK)
		put_st((unsigned long int)ptr->path->info.st_size, long1[1]);
	else
	{
		if (long1[1] < 7)
			long1[1] = 7;
		put_major_minor(ptr->path->info.st_rdev);
	}
	ft_putchar(' ');
	if (op.u == 0)
		puttime(ptr->path->info.st_mtime);
	else
		puttime(ptr->path->info.st_atime);
}

static void	pointer_materiel(unsigned int long1[2], t_pwgr ***this,
		t_dfile **ptr, t_pinfo *lst)
{
	long1[0] = longone(lst->file, 1);
	long1[1] = longone(lst->file, 2);
	*this = plein_pwgr(lst->file);
	*ptr = lst->file;
}

void		affiche_detail(t_pinfo *lst, t_option op)
{
	t_dfile			*ptr;
	unsigned int	long1[2];
	t_pwgr			**this;

	if (lst->file)
	{
		pointer_materiel(long1, &this, &ptr, lst);
		if (lst->ptype == IF_DIR && op.d == 0)
			print_total(lst->file);
		while (ptr)
		{
			detail(ptr, this, long1, op);
			if (op.gg == 1)
				couleur(ptr->path->ptype, ptr->path->info.st_mode);
			if (ptr->path->ptype == IF_LINK)
				print_iflink(ptr);
			else
				ft_putstr(ptr->file);
			ft_putstr("\033[0m");
			ft_putchar('\n');
			ptr = ptr->next;
		}
		free(this);
	}
}
