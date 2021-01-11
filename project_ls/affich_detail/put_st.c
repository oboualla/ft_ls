/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_st.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:13:28 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/12 00:36:50 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static int	nbrlen(unsigned long int nbr)
{
	int len;

	len = 1;
	while (nbr >= 10)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

int			longone(t_dfile *flst, int flag)
{
	t_dfile *ptr;
	t_dfile *this;

	ptr = flst;
	this = flst;
	while (ptr)
	{
		if (flag == 1 && this->path->info.st_nlink < ptr->path->info.st_nlink)
			this = ptr;
		if (flag == 2)
			if (this->path->info.st_size < ptr->path->info.st_size)
				this = ptr;
		ptr = ptr->next;
	}
	if (flag == 1)
		return (nbrlen((int)this->path->info.st_nlink));
	if (flag == 2)
		return (nbrlen((int)this->path->info.st_size));
	return (0);
}

void		put_st(unsigned long int st, int longone)
{
	int len;

	len = 0;
	len = nbrlen(st);
	if (len <= longone)
		while (++len <= longone)
			ft_putchar(' ');
	ft_putlnbr(st);
}
