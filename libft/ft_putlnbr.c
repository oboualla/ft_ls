/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 16:26:23 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/07 16:30:17 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlnbr(long int nbr)
{
	unsigned long int nb;

	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	nb = nbr;
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putlnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}
