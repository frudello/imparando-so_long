/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:52:43 by frudello          #+#    #+#             */
/*   Updated: 2022/07/22 15:14:58 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_name(char *filename)
{
	int	len;

	len = 0;
	while (filename[len])
		len++;
	if (filename[len - 4] != '.' || filename[len - 3] != 'b'
		|| filename[len - 2] != 'e' || filename[len - 1] != 'r')
		return (0);
	else
		return (1);
}

int	close_all(t_mlx *mlx_s)
{
	mlx_destroy_window(mlx_s->mlx, mlx_s->win);
	exit(0);
}

int	stampiamolo(void)
{
	printf("ti piace il cazzo\n");
	return (0);
}

int	keycode(int keycode, t_map *m)
{
	t_mlx	*mlx_s;

	mlx_s = m->mlx;
	if (keycode == 53)
		close_all(mlx_s);
	else if (keycode == 3)
		stampiamolo();
	if (keycode == 13 || keycode == 126)
		move_up(m);
	if (keycode == 0 || keycode == 123)
		move_left(m);
	if (keycode == 1 || keycode == 125)
		move_down(m);
	if (keycode == 2 || keycode == 124)
		move_right(m);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx_s;
	t_map	map;

	if (ac < 2 || !ft_check_map_name(av[1]))
		return (ft_putstr("Use ./so_long *.ber"), 1);
	map.mosse = 0;
	map.map = smap(av[1]);
	if (map.map == NULL)
		return (0);
	walenght(&map);
	edges(&map);
	areall(&map);
	mlx_s.mlx = mlx_init();
	mlx_s.win = mlx_new_window(mlx_s.mlx, map.check.x * 64, map.check.y * 64, \
	"Hello world!");
	map.mlx = &mlx_s;
	map.img = mlx_new_image(mlx_s.mlx, map.check.x * 64, map.check.y * 64);
	muriamola(&map);
	mlx_hook(mlx_s.win, 2, 1L << 0, keycode, &map);
	mlx_hook(mlx_s.win, 17, 1L << 17, close_all, &mlx_s);
	mlx_loop(mlx_s.mlx);
}
