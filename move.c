/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:38:53 by frudello          #+#    #+#             */
/*   Updated: 2022/07/22 14:50:08 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win(t_map *m)
{
	t_mlx	*mlx_s;

	mlx_s = m->mlx;
	mlx_destroy_window(mlx_s->mlx, mlx_s->win);
	ft_putstr("brava complimenti hai vinto! 8======D");
	exit(0);
}

void	move_up(t_map *m)
{
	if (m->map[m->prighe - 1][m->pcolonne] == '1')
		return ;
	if (m->map[m->prighe - 1][m->pcolonne] == 'C')
	{
		put_wall(m, m->prighe - 1, m->pcolonne, "floor1.xpm");
		m->collezionabile -= 1;
	}
	if (m->map[m->prighe - 1][m->pcolonne] == 'E')
	{
		if (m->collezionabile == 0)
			win(m);
		else
			return ;
	}
	m->map[m->prighe][m->pcolonne] = '0';
	put_wall(m, m->prighe, m->pcolonne, "floor1.xpm");
	m->map[m->prighe - 1][m->pcolonne] = 'P';
	put_wall(m, m->prighe - 1, m->pcolonne, "player.xpm");
	ft_putnbr(m->mosse++);
	ft_putchar('\n');
	m->prighe -= 1;
}

void	move_left(t_map *m)
{
	if (m->map[m->prighe][m->pcolonne - 1] == '1')
		return ;
	if (m->map[m->prighe][m->pcolonne - 1] == 'C')
	{
		put_wall(m, m->prighe, m->pcolonne - 1, "floor1.xpm");
		m->collezionabile--;
	}
	if (m->map[m->prighe][m->pcolonne - 1] == 'E')
	{
		if (m->collezionabile == 0)
			win(m);
		else
			return ;
	}
	m->map[m->prighe][m->pcolonne] = '0';
	put_wall(m, m->prighe, m->pcolonne, "floor1.xpm");
	m->map[m->prighe][m->pcolonne - 1] = 'P';
	put_wall(m, m->prighe, m->pcolonne - 1, "player.xpm");
	ft_putnbr(m->mosse++);
	ft_putchar('\n');
	m->pcolonne -= 1;
}

void	move_down(t_map *m)
{
	if (m->map[m->prighe + 1][m->pcolonne] == '1')
		return ;
	if (m->map[m->prighe + 1][m->pcolonne] == 'C')
	{
		put_wall(m, m->prighe + 1, m->pcolonne, "floor1.xpm");
		m->collezionabile--;
	}
	if (m->map[m->prighe + 1][m->pcolonne] == 'E')
	{
		if (m->collezionabile == 0)
			win(m);
		else
			return ;
	}
	m->map[m->prighe][m->pcolonne] = '0';
	put_wall(m, m->prighe, m->pcolonne, "floor1.xpm");
	m->map[m->prighe + 1][m->pcolonne] = 'P';
	put_wall(m, m->prighe + 1, m->pcolonne, "player.xpm");
	ft_putnbr(m->mosse++);
	ft_putchar('\n');
	m->prighe += 1;
}

void	move_right(t_map *m)
{
	if (m->map[m->prighe][m->pcolonne + 1] == '1')
		return ;
	if (m->map[m->prighe][m->pcolonne + 1] == 'C')
	{
		put_wall(m, m->prighe, m->pcolonne + 1, "floor1.xpm");
		m->collezionabile -= 1;
	}
	if (m->map[m->prighe][m->pcolonne + 1] == 'E')
	{
		if (m->collezionabile == 0)
			win(m);
		else
			return ;
	}
	m->map[m->prighe][m->pcolonne] = '0';
	put_wall(m, m->prighe, m->pcolonne, "floor1.xpm");
	m->map[m->prighe][m->pcolonne + 1] = 'P';
	put_wall(m, m->prighe, m->pcolonne + 1, "player.xpm");
	ft_putnbr(m->mosse++);
	ft_putchar('\n');
	m->pcolonne += 1;
}
