/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plein_pwgr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 21:26:46 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/12 00:18:51 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static t_pwgr	*add_pwgr(uid_t uid, gid_t gid, t_pwgr **pwgr)
{
	t_pwgr			*new;
	struct passwd	*pwd;
	struct group	*grg;

	if (!(new = (t_pwgr*)ft_memalloc(sizeof(t_pwgr))))
		exit(EXIT_FAILURE);
	pwd = getpwuid(uid);
	grg = getgrgid(gid);
	new->pw_name = ft_strdup(pwd->pw_name);
	new->gr_name = ft_strdup(grg->gr_name);
	*pwgr = new;
	return (new);
}

t_pwgr			**plein_pwgr(t_dfile *lst)
{
	t_dfile *ptr;
	t_pwgr	**this;

	if (!(this = (t_pwgr**)ft_memalloc(sizeof(t_pwgr*) * 3)))
		exit(EXIT_FAILURE);
	ptr = lst;
	while (ptr)
	{
		add_pwgr(ptr->path->info.st_uid,
				ptr->path->info.st_gid, &ptr->pwgr);
		ptr = ptr->next;
	}
	ptr = lst;
	this[0] = ptr->pwgr;
	this[1] = ptr->pwgr;
	while (ptr)
	{
		if (ft_strlen(ptr->pwgr->pw_name) > ft_strlen(this[0]->pw_name))
			this[0] = ptr->pwgr;
		if (ft_strlen(ptr->pwgr->gr_name) > ft_strlen(this[1]->gr_name))
			this[1] = ptr->pwgr;
		ptr = ptr->next;
	}
	this[2] = NULL;
	return (this);
}
