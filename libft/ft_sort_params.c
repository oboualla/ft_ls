/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 02:13:29 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/18 18:44:09 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_params(char **av)
{
	char	*tmp;
	int		i;
	int		cmp;

	cmp = 0;
	while (av[cmp])
	{
		i = 0;
		while (av[i])
		{
			if (ft_strcmp(av[cmp], av[i]) < 0)
			{
				tmp = av[cmp];
				av[cmp] = av[i];
				av[i] = tmp;
			}
			i++;
		}
		cmp++;
	}
}
