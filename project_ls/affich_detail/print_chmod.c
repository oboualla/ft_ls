/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chmod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:02:57 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/16 23:48:42 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void			affich_acl(char *path)
{
	acl_t		acl;
	ssize_t		xattr;

	xattr = 0;
	acl = NULL;
	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (xattr > 0)
		ft_putchar('@');
	else if (acl != NULL)
		ft_putchar('+');
	else
		ft_putchar(' ');
	if (acl)
		free(acl);
}

static char		detect_type(int type)
{
	if (type == IF_DIR)
		return ('d');
	if (type == IF_LINK)
		return ('l');
	if (type == IF_IFO)
		return ('p');
	if (type == IF_CHR)
		return ('c');
	if (type == IF_SOCK)
		return ('s');
	if (type == IF_BLK)
		return ('b');
	return ('-');
}

static void		special_permissions(char chmod[12], int mode)
{
	if (mode & S_ISUID)
		chmod[3] = (mode & S_IXUSR) ? 's' : 'S';
	else if (mode & S_IXUSR)
		chmod[3] = 'x';
	if (mode & S_ISGID)
		chmod[6] = (mode & S_IXGRP) ? 's' : 'S';
	else if (mode & S_IXUSR)
		chmod[6] = 'x';
	if (mode & S_ISVTX)
		chmod[9] = (mode & S_IXOTH) ? 't' : 'T';
	else if (mode & S_IXOTH)
		chmod[9] = 'x';
}

void			print_chmod(int bitw, int type)
{
	char chmod[12];

	ft_memset((void*)chmod, '-', 11);
	chmod[0] = detect_type(type);
	if (bitw & S_IRUSR)
		chmod[1] = 'r';
	if (bitw & S_IWUSR)
		chmod[2] = 'w';
	if (bitw & S_IRGRP)
		chmod[4] = 'r';
	if (bitw & S_IWGRP)
		chmod[5] = 'w';
	if (bitw & S_IROTH)
		chmod[7] = 'r';
	if (bitw & S_IWOTH)
		chmod[8] = 'w';
	special_permissions(chmod, bitw);
	chmod[10] = '\0';
	ft_putstr(chmod);
}
