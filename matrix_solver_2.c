/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:10:35 by kmykhail          #+#    #+#             */
/*   Updated: 2017/11/17 12:10:51 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int		ft_next_step(t_dim *st)
{
	if (st->x < st->size - 1)
	{
		st->x++;
		return (1);
	}
	else if (st->x == st->size - 1 && st->y != st->size - 1)
	{
		st->x = 0;
		st->y++;
		return (1);
	}
	else
		return (0);
}

int		ft_pos_x(char **arr)
{
	int k;
	int c;
	int x;

	k = 0;
	x = 4;
	while (arr[k])
	{
		c = 0;
		while (c < 4)
		{
			if (arr[k][c] != 46 && c < x)
				x = c;
			c++;
		}
		k++;
	}
	return (x);
}

int		ft_pos_y(char **arr)
{
	int k;
	int c;

	k = 0;
	while (k < 4)
	{
		c = 0;
		while (c < 4)
		{
			if (arr[k][c] != '.')
				return (k);
			c++;
		}
		k++;
	}
	return (0);
}

void	ft_putendl_1(char const *s)
{
	if (!s)
		return ;
	ft_putstr_1((char*)s);
	write(1, "\n", 1);
}

void	ft_putstr_1(char const *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}
