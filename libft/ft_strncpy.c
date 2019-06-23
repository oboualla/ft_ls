/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:41:56 by oboualla          #+#    #+#             */
/*   Updated: 2019/04/04 05:13:22 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *str, size_t n)
{
	size_t i;

	i = 0;
	while (str[i] != '\0' && i < n)
	{
		dest[i] = str[i];
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
