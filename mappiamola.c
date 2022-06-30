/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappiamola.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:29:58 by frudello          #+#    #+#             */
/*   Updated: 2022/06/30 18:12:48 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_wall(t_map *m, int i, int j, char *s)
{
	t_mlx	*gay;
	int		h;

	gay = m->mlx;
	mlx_put_image_to_window(gay->mlx, gay->win, mlx_xpm_file_to_image(gay->mlx, s, &h, &h), j * 64, i * 64);
}

int	cazzostampo(char c)
{
	if(c == '0')
		return(5);
	else if(c == '1')
		return(1);
	else if(c == 'C')
		return(2);
	else if(c == 'E')
		return(3);
	else if(c == 'P')
		return(4);
	//if(c == '0')
	return(0);
}

void	muriamola(t_map *map_s)
{
	int i;
	int j;
	map_s->collezionabile=0;

	i = -1;
	while(++i < map_s->check.y)
	{
		j = -1;
		while(++j < map_s->check.x)
		{
			if (cazzostampo(map_s->map[i][j]) != 1)
				put_wall(map_s, i, j, "floor1.xpm");
			if (cazzostampo(map_s->map[i][j]) == 1)
				put_wall(map_s, i, j, "test.xpm");
			else if (cazzostampo(map_s->map[i][j]) == 2)
			{
				put_wall(map_s, i, j, "evil1.xpm");
				map_s->collezionabile +=1;
			}
			else if (cazzostampo(map_s->map[i][j]) == 3)
				put_wall(map_s, i, j, "four.xpm");
			else if (cazzostampo(map_s->map[i][j]) == 4)
			{
				put_wall(map_s, i, j, "three.xpm");
				map_s->pcolonne = j;
				map_s->prighe = i;
			}
		}
	}
	//printf("gagaerg %d || %d\n", map_s->pcolonne, map_s->prighe);
	//i = -1;
	//while(++i < map_s->check.y)
	//{
	//	j = -1;
	//	while(++j < map_s->check.x)
	//	{
	//		cazzostampo (map_s->map[i][j])

	//	}
	//}
}