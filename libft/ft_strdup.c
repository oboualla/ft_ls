/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:22:45 by oboualla          #+#    #+#             */
/*   Updated: 2019/04/19 14:04:39 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char		*st;
	int			i;

	i = 0;
	if (!(st = malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	while (str[i])
	{
		st[i] = str[i];
		i++;
	}
	st[i] = '\0';
	return (st);
}
