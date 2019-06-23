/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathtypes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:19:01 by oboualla          #+#    #+#             */
/*   Updated: 2019/06/23 14:12:45 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ft_pathtypes(t_pinfo *plst)
{
	while (plst)
	{
		switch (plst->info.st_mode & S_IFMT)
		{
			case (S_IFBLK) :
				plst->ptype = IF_BLK;	break;
			case (S_IFCHR) :
				plst->ptype = IF_CHR;	break;
			case (S_IFDIR) :
				plst->ptype = IF_DIR;	break;
			case (S_IFIFO) :
				plst->ptype = IF_IFO;	break;
			case (S_IFLNK) :
				plst->ptype = IF_LINK;	break;
			case (S_IFREG) :
				plst->ptype = IF_REG;	break;
			case (S_IFSOCK) :
				plst->ptype = IF_SOCK;	break;
			default : break;
		}
		plst = plst->next;
	}
}
