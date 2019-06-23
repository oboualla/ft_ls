/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 14:25:56 by oboualla          #+#    #+#             */
/*   Updated: 2019/06/23 13:50:50 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_unitialiser(t_option *op)
{
	op->l = 0;
	op->R = 0;
	op->a = 0;
	op->r = 0;
	op->t = 0;
}

void	addflag(char *flag, t_option *op)
{
	int i;

	i = 0;
	while (flag[i] != '\0')
	{
		if (flag[i] == 'l')
			op->l = 1;
		if (flag[i] == 'R')
			op->R = 1;
		if (flag[i] == 'a')
			op->a = 1;
		if (flag[i] == 'r')
			op->r = 1;
		if (flag[i] == 't')
			op->t = 1;
		i++;
	}
}

t_option option(int ac, char **av)
{
	t_option op;
	int	i;
	int j;

	j = 1;
	i = 1;
	while (j < ac && av[j][0] == '-')
		j++;
	ft_unitialiser(&op);
	while (i < j)
	{
		addflag(av[i], &op);
		i++;
	}
	return (op);
}

int main(int ac, char **av)
{
	t_pinfo *lst;
	t_option op;

	op = option(ac, av);
	lst = ft_lstpath(ac, av);
	ft_pathtypes(lst);
	while (lst)
	{
		printf("path : %s || type : %d || mode : %lo\n",lst->path, lst->ptype, (long)lst->info.st_mode);
		lst = lst->next;
	}
	return 0;
}
