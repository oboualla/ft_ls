/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 14:25:56 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/18 18:45:45 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_unitialiser(t_option *op)
{
	op->l = 0;
	op->rr = 0;
	op->a = 0;
	op->r = 0;
	op->t = 0;
	op->u = 0;
	op->f = 0;
	op->g = 0;
	op->d = 0;
	op->o = 0;
	op->i = 0;
	op->gg = 0;
}

static t_option		option(int ac, char **av)
{
	t_option	op;
	int			i;
	int			j;

	j = 1;
	i = 1;
	while (j < ac && av[j][0] == '-' && av[j][1] != '\0')
		j++;
	ft_unitialiser(&op);
	while (i < j)
	{
		addflag(av[i], &op);
		i++;
	}
	if (op.f == 0)
		ft_sort_params(&av[j]);
	return (op);
}

int					main(int ac, char **av)
{
	t_pinfo		*lst;
	t_option	op;

	op = option(ac, av);
	if (!(lst = ft_lstpath(ac, av)))
		exit(EXIT_FAILURE);
	if (op.t == 1 && op.f == 0)
		sort_lsttime(lst, op);
	if (op.r == 1 && op.f == 0)
		rev_lst(lst);
	if (op.d == 0)
		ft_ls(lst, op);
	else
		flag_d(lst, op);
	return (0);
}
