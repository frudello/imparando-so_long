/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:52:43 by frudello          #+#    #+#             */
/*   Updated: 2022/06/30 19:13:22 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_all(t_mlx *mlx_s) //funzione di chiusura del so_long
{
	mlx_destroy_window(mlx_s->mlx, mlx_s->win);
	exit(0);
}

int	stampiamolo()
{
	printf("ti piace il cazzo\n");
	return (0);
}

int	keycode(int keycode, t_map *m) //funzione che associa ïl premere un pulsante" con una funzione
{
	t_mlx *mlx_s;

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
	t_mlx mlx_s;
	t_map map;
	(void)ac;

	map.mosse = 0;
	map.map = MAP(av[1]);
	walenght(&map);
	edges(&map);
	areall(&map);
	mlx_s.mlx = mlx_init(); //inizializzo la libreria?
	mlx_s.win = mlx_new_window(mlx_s.mlx, map.check.x*64, map.check.y*64, "Hello world!"); //creo una finestra
	map.mlx = &mlx_s;
	map.img = mlx_new_image(mlx_s.mlx, map.check.x*64, map.check.y*64); //creo un immagine
	muriamola(&map);
	//printf("gagaerg %d || %d\n", map.pcolonne, map.prighe);
	//mlx_s.gerry = mlx_xpm_file_to_image(mlx_s.mlx, "test.xpm", &mlx_s.x, &mlx_s.y); //assegno a una variabile vuota l'immagine che voglio stampare
	//mlx_hook(mlx_s.win, 17, 0, close_windows, mlx_s.mlx, mlx_s.win);
	//mlx_put_image_to_window(mlx_s.mlx,mlx_s.win, mlx_s.gerry, 0, 0); //stampo l'immagine
	mlx_hook(mlx_s.win, 2, 1L<<0, keycode, &map);
	mlx_hook(mlx_s.win, 17, 1L<<17, close_all, &mlx_s);
	mlx_loop(mlx_s.mlx);
}
