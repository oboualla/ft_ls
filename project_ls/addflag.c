/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addflag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 21:05:50 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/12 01:03:30 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	detectdeff(char c)
{
	if (c != 'l' && c != 'R' && c != 'a' && c != 'r' && c != 't' && c != 'G' &&
			c != 'u' && c != 'f' && c != 'g' && c != 'd' && c != '1')
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(c, 2);
		ft_putchar_fd('\n', 2);
		ft_putendl_fd("usage : ./ft_ls [-Ralrtufgd1G] [file ...]", 2);
		exit(EXIT_FAILURE);
	}
}

static void	bonusflag(char c, t_option *op)
{
	if (c == 'u')
		op->u = 1;
	if (c == 'f')
	{
		op->a = 1;
		op->f = 1;
	}
	if (c == 'g')
		op->g = 1 + op->o;
	if (c == 'd')
		op->d = 1;
	if (c == '1')
		op->o = 1 + op->l + op->g;
	if (c == 'G')
		op->gg = 1;
}

void		addflag(char *flag, t_option *op)
{
	int i;

	i = 1;
	while (flag[i] != '\0')
	{
		detectdeff(flag[i]);
		if (flag[i] == 'l')
			op->l = 1 + op->o;
		if (flag[i] == 'R')
			op->rr = 1;
		if (flag[i] == 'a')
			op->a = 1;
		if (flag[i] == 'r')
			op->r = 1;
		if (flag[i] == 't')
			op->t = 1;
		bonusflag(flag[i], op);
		i++;
	}
}
