/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IF_DIR.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:42:31 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/22 16:48:09 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void		ft_dellst(t_dfile **lst)
{
	t_dfile *tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		if ((*lst)->path)
		{
			if ((*lst)->path->ptype != IF_DIR)
			{
				ft_strdel(&(*lst)->path->file->file);
				ft_memdel((void**)&(*lst)->path->file);
			}
			ft_strdel(&(*lst)->path->path);
			ft_memdel((void**)&(*lst)->path);
		}
		if ((*lst)->pwgr)
		{
			free((*lst)->pwgr->pw_name);
			free((*lst)->pwgr->gr_name);
			ft_memdel((void**)&(*lst)->pwgr);
		}
		ft_strdel(&(*lst)->file);
		ft_memdel((void**)&(*lst));
		*lst = tmp;
	}
}

static char		*join_name(char *file1, char *file2)
{
	char	*jn;
	int		chr;

	chr = ft_strlen(file1) - 1;
	if (!(jn = (char*)ft_memalloc(sizeof(char) *
			(ft_strlen(file1) + ft_strlen(file2) + 2))))
		return (NULL);
	ft_strcpy(jn, file1);
	if (file1[chr] != '/')
		ft_strcat(jn, "/");
	ft_strcat(jn, file2);
	return (jn);
}

static int		get_lstfile(char *file, t_option op, t_dfile **alst)
{
	DIR				*dirp;
	struct dirent	*dirn;
	t_dfile			*pdf;

	if (!(dirp = opendir(file)))
		return (error(file));
	while ((dirn = readdir(dirp)))
		if (dirn->d_name[0] != '.' || op.a == 1)
		{
			pdf = ft_lstfile(&*alst, dirn->d_name);
			if (!ft_addpath(join_name(file, pdf->file), &pdf->path))
				return (0);
			if (pdf->path->ptype == IF_LINK && !pdf->path->file)
				if_link(pdf->path);
		}
	if (op.f == 0)
		ordre_ascii(*alst);
	if (op.t == 1 && op.f == 0)
		ordre_time(*alst, op);
	if (op.r == 1 && op.f == 0)
		ordre_rev(*alst);
	closedir(dirp);
	return (1);
}

static void		find_method_aff(t_pinfo *directory, t_option op)
{
	if (op.l == 0 && op.g == 0 && op.o == 0)
		affiche_simple(directory->file, op);
	else if (op.o < op.l || op.o < op.g)
		affiche_detail(directory, op);
	else
		flag_one(directory->file, op);
}

void			if_directory(t_pinfo *ptr, t_option op)
{
	t_dfile *file;

	if (!(get_lstfile(ptr->path, op, &ptr->file)))
		return ;
	find_method_aff(ptr, op);
	if (op.rr == 1)
	{
		file = ptr->file;
		while (file)
		{
			if ((ft_strcmp(file->file, ".") && ft_strcmp(file->file, "..")))
				if (file->path->ptype == IF_DIR)
				{
					ft_putchar('\n');
					ft_putstr(file->path->path);
					ft_putendl(":");
					if_directory(file->path, op);
				}
			file = file->next;
		}
	}
	ft_dellst(&ptr->file);
}
