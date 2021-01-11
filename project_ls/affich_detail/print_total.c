/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_total.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 16:21:33 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/12 00:16:00 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	print_total(t_dfile *lst)
{
	long long int total;

	total = 0;
	while (lst)
	{
		total += lst->path->info.st_blocks;
		lst = lst->next;
	}
	ft_putstr("total ");
	ft_putlnbr((long int)total);
	ft_putchar('\n');
}
