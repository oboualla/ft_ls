/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   couleur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:52:49 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/20 23:20:21 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void	active_c(int couleur)
{
	if (couleur & BLUE)
		ft_putstr("\033[01;36m");
	else if (couleur & ROUGE)
		ft_putstr("\033[00;31m");
	else if (couleur & PURPLE)
		ft_putstr("\033[00;35m");
	else if (couleur & BAGRROUGE)
		ft_putstr("\033[0;41;30m");
	else if (couleur & BAGRJEUNE)
		ft_putstr("\033[0;34;43m");
	else if (couleur & BAGRBLUE)
		ft_putstr("\033[0;34;46m");
	else if (couleur & JEUNE)
		ft_putstr("\033[0;33m");
}

void		couleur(int ptype, int mode)
{
	if (ptype == IF_DIR)
		active_c(BLUE);
	else if (ptype == IF_REG)
	{
		if (mode & S_IXUSR || mode & S_IXGRP || mode & S_IXOTH)
		{
			if (mode & S_ISUID || mode & S_ISGID || mode & S_ISVTX)
				active_c(BAGRROUGE);
			else
				active_c(ROUGE);
		}
	}
	else if (ptype == IF_LINK)
		active_c(PURPLE);
	else if (ptype == IF_CHR)
		active_c(BAGRJEUNE);
	else if (ptype == IF_BLK)
		active_c(BAGRBLUE);
	else if (ptype == IF_IFO)
		active_c(JEUNE);
}
