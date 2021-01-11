/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 18:49:05 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/12 01:48:03 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	flag_one(t_dfile *lst, t_option op)
{
	while (lst)
	{
		if (op.gg == 1)
			couleur(lst->path->ptype, lst->path->info.st_mode);
		ft_putendl(lst->file);
		ft_putstr("\033[0m");
		lst = lst->next;
	}
}
