/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                      +#+  +:+     +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:31:53 by pzubar            #+#    #+#             */
/*   Updated: 2017/11/13 13:31:55 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

static	int		ft_check_val_t(char *s)
{
	int next;
	int i;

	next = 0;
	i = 0;
	while (i < 20)
	{
		if (s[i] == '#')
		{
			next = (((i + 1) < 20 && s[i + 1] == '#') ? next + 1 : next);
			next = (((i - 1) >= 0 && s[i - 1] == '#') ? next + 1 : next);
			next = (((i + 5) < 20 && s[i + 5] == '#') ? next + 1 : next);
			next = (((i - 5) >= 0 && s[i - 5] == '#') ? next + 1 : next);
		}
		i++;
	}
	return ((next == 6 || next == 8) ? 1 : 0);
}

static	int		ft_ifvalid(char *s, int last)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (i < 20)
	{
		if (i != 4 && i != 9 && i != 14 && i != 19)
		{
			if (!(s[i] == '#' || s[i] == '.'))
				return (0);
			if (s[i] == '#' && ++n > 4)
				return (0);
		}
		else if (s[i] != '\n')
			return (0);
		i++;
	}
	if (ft_check_val_t(s) == 0)
		return (0);
	if (((last == 20) && s[i] != '\0') || last > 545)
		return (0);
	return (1);
}

static	int		ft_opener(char **argv, int i)
{
	int		fd;
	char	buff;
	int		j;
	char	*mass;

	j = 0;
	if (!(mass = (char*)malloc(sizeof(char) * 546)))
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	while (read(fd, &buff, 1) != 0)
	{
		if (((i % 21 == 0) && (i != 0)))
		{
			j = (!(ft_ifvalid(&mass[i - 21], i))) ? 0 : (j + 21);
			if (j == 0)
				return (0);
		}
		mass[i++] = buff;
	}
	close(fd);
	mass[i] = '\0';
	if (ft_ifvalid(&mass[j], 20) != 0)
		ft_letter(ft_triple_mass(mass), mass);
	return ((ft_ifvalid(&mass[j], 20) != 0) ? 1 : 0);
}

static	void	ft_gatekeeper(int res)
{
	if (res == 0)
	{
		write(1, "error\n", 6);
		exit(1);
	}
}

int				main(int argc, char *argv[])
{
	int i;

	i = 0;
	if (argc != 2)
	{
		write(1, "usage: ./fillit input_file\n", 28);
		exit(1);
	}
	ft_gatekeeper((ft_opener(argv, i)));
	return (0);
}
