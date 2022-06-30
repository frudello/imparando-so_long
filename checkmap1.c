/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:41:41 by frudello          #+#    #+#             */
/*   Updated: 2022/06/24 17:44:11 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	walenght(t_map *map_s)
{
	map_s->check.y = -1;
	map_s->check.x = ft_strlen(map_s->map[0]);
	while (map_s->map[++map_s->check.y])
		if(map_s->check.x != ft_strlen(map_s->map[map_s->check.y]))
			ft_putstr("piscia1\n");
	//map_s->check.y--;
}

void	one(char *s, char c)
{
	int i;

	i = 0;
	while(s[i] && s[i] == c)
		i++;
	if (i != ft_strlen(s))
		ft_putstr("piscia2\n");
}

void	edges(t_map *map_s)
{
	int i;

	i = 1;
	one(map_s->map[0], '1');
	while(i < map_s->check.y - 1)
	{
		if(map_s->map[i][0] != '1' && map_s->map[i][map_s->check.x - 1] != '1')
			ft_putstr("piscia3\n");
		i++;
	}
	one(map_s->map[map_s->check.y - 1], '1');
}

int	troviamolo(t_map *map_s, char c)
{
	int i;
	int a;

	a = 0;
	while(a < map_s->check.y)
	{
		i = 0;
		while(i < map_s->check.x)
		{
			if(map_s->map[a][i] == c)
				return(1);
			i++;
		}
		a++;
	}
	return (0);
}

void	areall(t_map *map_s)
{
	if(troviamolo(map_s, 'C') == 0)
		ft_putstr("hai fatto una mappa di merda1\n");
	if(!troviamolo(map_s, 'P'))
		ft_putstr("hai fatto una mappa di merda2\n");
	if(!troviamolo(map_s, 'E'))
		ft_putstr("hai fatto una mappa di merda3\n");
	if(!troviamolo(map_s, '0'))
		ft_putstr("hai fatto una mappa di merda4\n");
}
