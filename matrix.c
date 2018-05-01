/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:10:35 by pzubar            #+#    #+#             */
/*   Updated: 2017/11/17 12:10:51 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

static	void	ft_free_double(char **stakan, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(stakan[i]);
		i++;
	}
	free(stakan);
	stakan = NULL;
}

static	void	ft_free_triple(char ***arr, int size, int nb)
{
	int i;
	int k;

	nb = 0;
	i = 0;
	while (i < nb)
	{
		k = 0;
		while (k < size - 1)
		{
			free(arr[i][k]);
			k++;
		}
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

static	int		ft_solver(char ***arr, char **stakan, int size, int i)
{
	t_dim	*st;

	if (arr[i] == NULL)
		return (1);
	st = (t_dim *)malloc(sizeof(t_dim));
	st->x = -1;
	st->y = 0;
	st->size = size;
	while (ft_next_step(st))
	{
		if (ft_new(arr[i], stakan, st))
		{
			i++;
			if (ft_solver(arr, stakan, size, i))
				return (1);
			else
			{
				ft_delete(stakan, arr[i - 1], size, i);
				i--;
			}
		}
	}
	free(st);
	return (0);
}

static	char	**ft_dots_matrix(int size)
{
	int		i;
	int		j;
	char	**arr;

	i = 0;
	j = 0;
	arr = (char**)malloc(sizeof(char*) * (size + 1));
	while (i < size)
	{
		arr[i] = (char*)malloc(sizeof(char) * (size + 1));
		j = 0;
		while (j < size)
		{
			arr[i][j] = 46;
			j++;
		}
		arr[i][j] = '\0';
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

int				ft_create_matrix(char ***arr, int size, int nb)
{
	char	**stakan;
	int		i;

	i = 0;
	while (1)
	{
		stakan = ft_dots_matrix(size);
		if (ft_solver(arr, stakan, size, i))
		{
			i = 0;
			while (i < size)
				ft_putendl_1(stakan[i++]);
			ft_free_double(stakan, size);
			ft_free_triple(arr, size, nb);
			exit(0);
		}
		else
		{
			i--;
			ft_free_double(stakan, size);
		}
		size++;
		i++;
	}
	exit(0);
}
