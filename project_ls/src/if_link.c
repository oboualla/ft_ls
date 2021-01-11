/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:34:53 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/12 03:01:44 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	if_link(t_pinfo *ptr)
{
	char *buff;

	if (!(buff = (char*)ft_memalloc(sizeof(char) * (ptr->info.st_size + 1))))
		exit(EXIT_FAILURE);
	if (readlink(ptr->path, buff, ptr->info.st_size + 1) == -1)
		exit(EXIT_FAILURE);
	ft_lstfile(&ptr->file, buff);
	ft_strdel(&buff);
}
