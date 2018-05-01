/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stakan.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                      +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:10:35 by pzubar            #+#    #+#             */
/*   Updated: 2017/11/17 12:10:51 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

static	int		ft_pospos(char **tm, char **sk, t_dim *tt, t_dim *st)
{
	int i;
	int j;
	int yes;

	i = 0;
	j = 0;
	yes = 0;
	while (tt->y + i < tt->size && st->y + i < st->size)
	{
		while ((tm[tt->y + i][tt->x + j]) && (sk[st->y + i][st->x + j]))
		{
			if (tm[tt->y + i][tt->x + j] != 46\
			&& sk[st->y + i][st->x + j] != 46)
				return (0);
			if (tm[tt->y + i][tt->x + j] != 46)
				yes++;
			j++;
		}
		j = 0;
		i++;
	}
	return ((yes == 4) ? 1 : 0);
}

static	void	ft_place(char **tm, char **sk, t_dim *tt, t_dim *st)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tt->y + i < tt->size && st->y + i < st->size)
	{
		while ((tm[tt->y + i][tt->x + j]) && (sk[st->y + i][st->x + j]))
		{
			if (tm[tt->y + i][tt->x + j] != 46)
				(sk[st->y + i][st->x + j] = tm[tt->y + i][tt->x + j]);
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
}

static	int		ft_stepper(char **tm, char **sk, t_dim *tt, t_dim *st)
{
	int next;

	next = 1;
	while (next)
	{
		if (ft_pospos(tm, sk, tt, st))
		{
			ft_place(tm, sk, tt, st);
			free(tt);
			return (1);
		}
		next = ft_next_step(st);
	}
	return (0);
}

void			ft_delete(char **sk, char **tm, int size, int i)
{
	int		k;
	char	del;

	i = 0;
	while (i < 4)
	{
		k = 0;
		while (k < 4)
		{
			del = (tm[i][k] != 46) ? tm[i][k] : del;
			k++;
		}
		i++;
	}
	i = 0;
	while (i < size)
	{
		k = 0;
		while (k < size)
		{
			sk[i][k] = (sk[i][k] == del) ? '.' : sk[i][k];
			k++;
		}
		i++;
	}
}

int				ft_new(char **arr, char **stakan, t_dim *st)
{
	t_dim	*tt;

	tt = (t_dim *)malloc(sizeof(t_dim));
	tt->x = ft_pos_x(&arr[0]);
	tt->y = ft_pos_y(&arr[0]);
	tt->size = 4;
	if (ft_stepper(arr, stakan, tt, st))
		return (1);
	else
	{
		free(tt);
		return (0);
	}
}
