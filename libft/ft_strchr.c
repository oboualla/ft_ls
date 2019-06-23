/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:43:44 by oboualla          #+#    #+#             */
/*   Updated: 2019/04/20 11:51:09 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *str, int c)
{
	int						i;
	unsigned char			*st;

	i = 0;
	st = (unsigned char *)str;
	while (st[i] != (unsigned char)c)
	{
		if (st[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char*)st + i);
}
