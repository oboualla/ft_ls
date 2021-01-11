/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:37:37 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/12 02:29:16 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static t_dfile	*new_file(char *file)
{
	t_dfile *new;

	if (!(new = (t_dfile*)ft_memalloc(sizeof(t_dfile))))
		return (NULL);
	new->file = ft_strdup(file);
	new->pwgr = NULL;
	new->path = NULL;
	new->next = NULL;
	new->back = NULL;
	return (new);
}

t_dfile			*ft_lstfile(t_dfile **alst, char *file)
{
	t_dfile *ptr;
	t_dfile *back;

	if (!(*alst))
	{
		ptr = new_file(file);
		*alst = ptr;
	}
	else
	{
		ptr = *alst;
		while (ptr->next)
			ptr = ptr->next;
		back = ptr;
		ptr->next = new_file(file);
		ptr = ptr->next;
		ptr->back = back;
	}
	return (ptr);
}
