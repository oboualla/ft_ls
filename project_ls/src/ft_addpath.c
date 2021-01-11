/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:04:08 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/20 23:11:41 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void		test(t_pinfo *new)
{
	DIR *dirp;

	dirp = NULL;
	if (new->ptype == IF_LINK)
	{
		if (!(dirp = opendir(new->path)))
			if_link(new);
	}
	else
		ft_lstfile(&new->file, new->path);
	if (new->file)
		new->file->path = new;
	if (dirp)
		closedir(dirp);
}

static t_pinfo	*new_path(char const *path)
{
	t_pinfo *new;

	if (!(new = (t_pinfo*)ft_memalloc(sizeof(t_pinfo))))
		exit(EXIT_FAILURE);
	if (lstat(path, &new->info) == -1)
	{
		free(new);
		return (NULL);
	}
	new->path = (char*)path;
	new->file = NULL;
	new->back = NULL;
	new->next = NULL;
	ft_pathtypes(new);
	if (new->ptype != IF_DIR)
		test(new);
	return (new);
}

t_pinfo			*ft_addpath(const char *path, t_pinfo **alst)
{
	t_pinfo *ptr;
	t_pinfo *back;

	if (!(*alst))
	{
		if (!(ptr = new_path(path)))
			return (NULL);
		*alst = ptr;
	}
	else
	{
		ptr = *alst;
		while (ptr->next)
			ptr = ptr->next;
		back = ptr;
		if (!(ptr->next = new_path(path)))
			return (NULL);
		ptr = ptr->next;
		ptr->back = back;
	}
	return (ptr);
}
