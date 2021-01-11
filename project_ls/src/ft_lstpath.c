/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:59:08 by oboualla          #+#    #+#             */
/*   Updated: 2019/08/04 20:23:04 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void	putnom(char const *path)
{
	ft_putstr(path);
	ft_putendl(":");
}

t_pinfo		*ft_lstpath(int ac, char **av)
{
	t_pinfo *lst;
	t_pinfo *ptr;
	int		j;
	int		flag;

	j = 1;
	lst = NULL;
	while (j < ac && av[j][0] == '-' && av[j][1] != '\0')
		j++;
	flag = ac - j;
	while (j < ac)
	{
		if (!(ptr = ft_addpath(av[j], &lst)))
			error(av[j]);
		j++;
	}
	if (!lst && flag < 1)
		if (!(ft_addpath(".", &lst)))
			return (NULL);
	if (lst && !lst->next && flag > 1 && lst->ptype == IF_DIR)
		putnom(lst->path);
	return (lst);
}
