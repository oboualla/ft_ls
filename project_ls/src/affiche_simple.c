/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 08:30:18 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/12 03:00:46 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"
#include "../affich_detail/mini.h"

static int	find_longf(t_dfile *lst)
{
	t_dfile *ptr;
	t_dfile *this;

	if (lst)
	{
		ptr = lst;
		this = ptr;
		while (ptr)
		{
			if (ft_strlen(ptr->file) > ft_strlen(this->file))
				this = ptr;
			ptr = ptr->next;
		}
		return (ft_strlen(this->file) + 1);
	}
	return (0);
}

static void	pointer_materiel(t_dfile ***groups, t_dfile *flst,
		t_dfile ***g_cmp, unsigned int *longone)
{
	*longone = find_longf(flst);
	*groups = make_groups(flst, *longone);
	*g_cmp = make_groups(flst, *longone);
}

static void	affiche_groups(t_dfile *groups, t_option op,
		unsigned int longone)
{
	int src;

	src = 0;
	if (op.gg == 1)
		couleur(groups->path->ptype, groups->path->info.st_mode);
	ft_putstr(groups->file);
	ft_putstr("\033[0m");
	if ((src = ft_strlen(groups->file)) < (int)longone)
		while (++src <= (int)longone)
			ft_putchar(' ');
}

int			affiche_simple(t_dfile *flst, t_option op)
{
	t_dfile			**groups;
	t_dfile			**g_cmp;
	int				i;
	unsigned int	longone;

	if (flst)
	{
		pointer_materiel(&groups, flst, &g_cmp, &longone);
		while (groups[0] != g_cmp[1])
		{
			i = -1;
			while (groups[++i])
			{
				if (groups[i])
				{
					affiche_groups(groups[i], op, longone);
					groups[i] = groups[i]->next;
				}
			}
			ft_putchar('\n');
		}
		free(groups);
		free(g_cmp);
	}
	return (1);
}
