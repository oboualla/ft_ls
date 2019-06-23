/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 07:53:32 by oboualla          #+#    #+#             */
/*   Updated: 2019/04/20 12:00:27 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *str, char *str2)
{
	int			i;
	char		*fraiche;
	int			j;

	i = 0;
	j = 0;
	if (str == 0 || str2 == 0)
		return (NULL);
	if (!(fraiche = (char *)malloc((ft_strlen(str)
						+ ft_strlen(str2) + 1) * sizeof(char))))
		return (NULL);
	if (fraiche)
	{
		while (str[i])
		{
			fraiche[i] = str[i];
			i++;
		}
		while (str2[j])
			fraiche[i++] = str2[j++];
		fraiche[i] = '\0';
		return (fraiche);
	}
	return (0);
}
