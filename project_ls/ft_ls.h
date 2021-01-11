/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 20:45:54 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/17 11:04:04 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# define BLUE		2
# define ROUGE		4
# define JEUNE 		8
# define PURPLE		16
# define BAGRROUGE	32
# define BAGRJEUNE	64
# define BAGRBLUE	128

typedef struct s_pinfo		t_pinfo;
typedef struct s_dfile		t_dfile;
typedef struct s_option		t_option;
typedef struct s_affichage	t_affichage;
typedef struct s_pwgr		t_pwgr;
typedef enum e_ptype		t_ptype;

struct		s_pwgr
{
	char *pw_name;
	char *gr_name;
};

enum		e_ptype
{
	IF_MT,
	IF_SOCK,
	IF_LINK,
	IF_REG,
	IF_BLK,
	IF_DIR,
	IF_CHR,
	IF_IFO,
};

struct		s_affichage
{
	unsigned int howmany;
	unsigned int combien;
};

struct		s_pinfo
{
	char		*path;
	struct stat info;
	t_ptype		ptype;
	t_dfile		*file;
	t_pinfo		*back;
	t_pinfo		*next;
};

struct		s_dfile
{
	char	*file;
	t_pinfo *path;
	t_pwgr	*pwgr;
	t_dfile *next;
	t_dfile *back;
};

struct		s_option
{
	int l;
	int rr;
	int a;
	int r;
	int t;
	int u;
	int f;
	int g;
	int d;
	int o;
	int i;
	int gg;
};

t_dfile		**make_groups(t_dfile *flst, unsigned int longone);
void		del(t_dfile *lst);
void		ft_plstdel(t_pinfo *lst);
void		addflag(char *flag, t_option *op);
void		couleur(int ptype, int mode);
void		ft_ls(t_pinfo *lst, t_option op);
t_pinfo		*ft_lstpath(int ac, char **av);
void		ft_pathtypes(t_pinfo *lst);
int			error(char *path);
void		if_link(t_pinfo *ptr);
void		if_directory(t_pinfo *ptr, t_option op);
t_dfile		*ft_lstfile(t_dfile **alst, char *file);
t_pinfo		*ft_addpath(const char *path, t_pinfo **alst);
void		affiche_detail(t_pinfo *lst, t_option op);
int			affiche_simple(t_dfile *lst, t_option op);
void		sort_lsttime(t_pinfo *lst, t_option op);
void		rev_lst(t_pinfo *lst);
void		flag_d(t_pinfo *lst, t_option op);
void		flag_one(t_dfile *lst, t_option op);
void		print_chmod(int bitw, int type);
void		ordre_time(t_dfile *lst, t_option op);
void		ordre_rev(t_dfile *lst);
void		ordre_ascii(t_dfile *lst);
#endif
