/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathtypes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:19:01 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/12 00:10:02 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ft_pathtypes(t_pinfo *plst)
{
	int type;

	type = plst->info.st_mode & S_IFMT;
	if (type == S_IFBLK)
		plst->ptype = IF_BLK;
	else if (type == S_IFCHR)
		plst->ptype = IF_CHR;
	else if (type == S_IFDIR)
		plst->ptype = IF_DIR;
	else if (type == S_IFIFO)
		plst->ptype = IF_IFO;
	else if (type == S_IFLNK)
		plst->ptype = IF_LINK;
	else if (type == S_IFREG)
		plst->ptype = IF_REG;
	else if (type == S_IFSOCK)
		plst->ptype = IF_SOCK;
}
