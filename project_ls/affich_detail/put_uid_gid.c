/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_uid_gid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 19:15:46 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/12 00:22:46 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	put_uid_gid(t_dfile *ptr, t_pwgr **this, t_option op)
{
	int		src;
	int		srcmp;

	srcmp = 0;
	src = 0;
	if (ptr)
	{
		if (op.g == 0)
		{
			ft_putstr(ptr->pwgr->pw_name);
			src = ft_strlen(ptr->pwgr->pw_name);
			srcmp = ft_strlen(this[0]->pw_name);
			while (++src <= (srcmp + 2))
				ft_putchar(' ');
		}
		ft_putstr(ptr->pwgr->gr_name);
		src = ft_strlen(ptr->pwgr->gr_name);
		srcmp = ft_strlen(this[1]->gr_name);
		while (++src <= (srcmp + 2))
			ft_putchar(' ');
	}
}
