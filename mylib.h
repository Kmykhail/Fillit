/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:36:39 by pzubar            #+#    #+#             */
/*   Updated: 2017/11/15 12:36:49 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIB_H
# define MYLIB_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct		s_dim
{
	int				x;
	int				y;
	int				size;
}					t_dim;
char				***ft_triple_mass(char *buff);
void				ft_letter(char ***qw, char *buff);
int					ft_create_matrix(char ***arr, int size, int nb);
int					ft_next_step(t_dim *st);
int					ft_pos_x(char **arr);
int					ft_pos_y(char **arr);
int					ft_tt_dim(char ***arr, char **stakan);
void				ft_delete(char **st, char **tm, int size, int i);
int					ft_new(char **arr, char **stakan, t_dim *st);
void				ft_putendl_1(char const *s);
void				ft_putstr_1(char const *s);
#endif
