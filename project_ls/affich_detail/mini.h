/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:16:01 by oboualla          #+#    #+#             */
/*   Updated: 2019/07/15 22:52:06 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

void	print_total(t_dfile *lst);
int		longone(t_dfile *flst, int flag);
int		nbrlen(int nbr);
void	put_st(int st, int longone);
void	puttime(time_t time);
t_pwgr	**plein_pwgr(t_dfile *lst);
void	put_uid_gid(t_dfile *ptr, t_pwgr **this, t_option op);
void	affich_acl(char *path);
#endif
