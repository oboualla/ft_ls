/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 20:45:54 by oboualla          #+#    #+#             */
/*   Updated: 2019/06/22 20:11:43 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct s_pinfo	t_pinfo;
typedef struct s_dfile	t_dfile;
typedef struct s_option t_option;

typedef enum e_path_types {
	IF_MT,
	IF_SOCK,
	IF_LINK,
	IF_REG,
	IF_BLK,
	IF_DIR,
	IF_CHR,
	IF_IFO,
} t_ptype;

struct s_pinfo
{
	char *path;
	struct stat info;
	t_ptype ptype;
	t_dfile *file;
	t_pinfo *next;
};

struct s_dfile
{
	char *file;
	t_pinfo *path;
	t_dfile *next;
};

struct s_option
{
	int l;
	int R;
	int a;
	int r;
	int t;
};

void	ft_ls(t_pinfo *lst, t_option op);

t_pinfo *ft_lstpath(int ac, char **av);
void    ft_pathtypes(t_pinfo *plst);
void	notfound(char *path);
# endif
