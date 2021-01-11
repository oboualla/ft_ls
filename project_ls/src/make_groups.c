/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_groups.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 02:44:58 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/12 03:02:39 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static int			ft_lstlen(t_dfile *lst)
{
	t_dfile *ptr;
	int		lstlen;

	lstlen = 0;
	if (lst)
	{
		ptr = lst;
		while (ptr)
		{
			lstlen++;
			ptr = ptr->next;
		}
		return (lstlen);
	}
	return (0);
}

static t_affichage	calc_howmany(unsigned int lstlen, unsigned int longf)
{
	t_affichage		affich;
	unsigned int	lfto;
	struct winsize	w;

	affich.howmany = 1;
	affich.combien = 0;
	lfto = longf;
	ioctl(0, TIOCGWINSZ, &w);
	while ((longf += lfto) < w.ws_col)
		affich.howmany++;
	if (affich.howmany > lstlen)
		affich.howmany = lstlen;
	else
	{
		affich.combien = lstlen / affich.howmany;
		while ((affich.combien * affich.howmany) < lstlen)
			affich.combien++;
	}
	if (affich.combien == 0)
		affich.combien = 1;
	return (affich);
}

t_dfile				**make_groups(t_dfile *flst, unsigned int longone)
{
	t_dfile			**groups;
	t_affichage		affich;
	unsigned int	var;
	int				i;

	i = 0;
	affich = calc_howmany(ft_lstlen(flst), longone);
	if (!(groups = (t_dfile**)
				ft_memalloc(sizeof(t_dfile*) * (affich.howmany + 1))))
		exit(EXIT_FAILURE);
	var = affich.combien;
	while (flst)
	{
		if (var == affich.combien)
		{
			groups[i++] = flst;
			var = 0;
		}
		var++;
		flst = flst->next;
	}
	return (groups);
}
