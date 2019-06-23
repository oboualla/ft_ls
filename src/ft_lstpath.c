/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 14:44:20 by oboualla          #+#    #+#             */
/*   Updated: 2019/06/22 16:45:44 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_pinfo *new_path(const char *path)
{
	t_pinfo *new;

	if (!(new = (t_pinfo*)ft_memalloc(sizeof(t_pinfo))))
		return (NULL);
	new->path = (char*)path;
	if (lstat(new->path, &new->info) == -1)
		if (stat(new->path, &new->info) == -1)
			return (NULL);
	new->file = NULL;
	new->next = NULL;
	return (new);
}

t_pinfo *ft_addpath(const char *path, t_pinfo **alst)
{
	t_pinfo *ptr;

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
		if (!(ptr->next = new_path(path)))
			return (NULL);
	}
	return (ptr);
}

t_pinfo *ft_lstpath(int ac, char **av)
{
	t_pinfo *lst;
	t_pinfo *ptr;
	int j;

	j = 1;
	lst = NULL;
	while (j < ac && av[j][0] == '-')
		j++;
	while (j < ac)
	{
		if (!(ptr = ft_addpath(av[j], &lst)))
			notfound(av[j]);
		j++;				
	}
	if (!lst)
		if (!(ft_addpath(ft_strdup("."), &lst)))
			return (NULL);
	return (lst);
}
