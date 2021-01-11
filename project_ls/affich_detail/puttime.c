/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puttime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:23:13 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/15 22:51:26 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void	ft_putsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;

	i = -1;
	if (s)
	{
		while (s[start] != '\0' && ++i < len)
			ft_putchar(s[start++]);
	}
}

void		puttime(time_t second)
{
	char			str[26];
	char			*ptr;
	time_t			now;
	unsigned int	sixmonth;
	int				i;

	i = 3;
	ft_strcpy(str, ctime(&second));
	ptr = ft_strchr(str, '\n');
	*ptr = '\0';
	sixmonth = 15552000;
	time(&now);
	now -= 15552000;
	if (second > now)
		ft_putsub(str, 4, 12);
	else
	{
		ft_putsub(str, 4, 6);
		ft_putchar(' ');
		ft_putsub(str, 19, 22);
	}
	ft_putchar(' ');
}
