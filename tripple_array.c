/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tomass.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:37:41 by pzubar            #+#    #+#             */
/*   Updated: 2017/11/15 12:37:46 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

static	int		ft_sizeof_matrix(int cnt)
{
	int size;
	int i;

	i = 0;
	size = cnt * 4;
	while (i * i != size)
	{
		i++;
		if (i * i == size)
			return (i);
		if (i * i > size)
			return (i);
	}
	return (0);
}

static	int		ft_count_tet(char *str)
{
	int i;
	int res;
	int k;

	i = 0;
	res = 0;
	k = 0;
	while (str[i])
	{
		k++;
		if (k == 18)
			res++;
		if ((str[i] == '\n' && str[i + 1] == '\n') ||\
		((str[i] == '\0' && str[i + 1] == '\0')))
			k = 0;
		i++;
	}
	return (res);
}

void			ft_letter(char ***qw, char *buff)
{
	int		i;
	int		k;
	int		p;
	char	symb;

	i = 0;
	symb = 'A';
	while (i < ft_count_tet(buff))
	{
		k = 0;
		while (k < 4)
		{
			p = 0;
			while (p < 5)
			{
				qw[i][k][p] = (qw[i][k][p] == '#') ? symb : qw[i][k][p];
				p++;
			}
			k++;
		}
		symb++;
		i++;
	}
	free(buff);
	ft_create_matrix(qw, ft_sizeof_matrix(i), i);
}

static	char	***ft_componator(char ***mass, char *buff, int i, int j)
{
	int k;
	int p;
	int z;

	z = ft_count_tet(buff);
	while (i < z)
	{
		if (!(mass[i] = (char**)malloc(sizeof(char*) * 4 + 1)))
			return (NULL);
		k = 0;
		while (k < 4)
		{
			if (!(mass[i][k] = (char*)malloc(sizeof(char) * 4 + 1)))
				return (NULL);
			p = 0;
			while (buff[j] == '\n')
				j++;
			while (p < 4)
				mass[i][k][p++] = buff[j++];
			mass[i][k++][p] = '\0';
		}
		mass[i++][k] = NULL;
	}
	mass[i] = NULL;
	return (mass);
}

char			***ft_triple_mass(char *buff)
{
	int		i;
	int		j;
	char	***mass;
	int		count_sqr;

	i = 0;
	j = 0;
	count_sqr = ft_count_tet(buff);
	if (!(mass = (char***)malloc(sizeof(char**) * count_sqr + 1)))
		return (NULL);
	mass = ft_componator(mass, buff, i, j);
	return (mass);
}
