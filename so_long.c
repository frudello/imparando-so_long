/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:52:43 by frudello          #+#    #+#             */
/*   Updated: 2022/06/13 16:46:18 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	close_all(t_bho *bho) //funzione di chiusura del so_long
{
	mlx_destroy_window(bho->mlx, bho->win);
	exit(0);
}

int	stampiamolo()
{
	printf("ti piace il cazzo\n");
	return (0);
}

int	keycode(int keycode, t_bho *bho) //funzione che associa ïl premere un pulsante" con una funzione
{
	if (keycode == 53)
		close_all(bho);
	else if (keycode == 3)
		stampiamolo();
	return (0);
}


int	main(void)
{
	t_bho bho;
	t_map map;
	
	bho.mlx = mlx_init(); //inizializzo la libreria?
	bho.win = mlx_new_window(bho.mlx, 1080, 1080, "Hello world!"); //creo una finestra
	map.img = mlx_new_image(bho.mlx, 1080, 1080); //creo un immagine
	bho.gerry = mlx_xpm_file_to_image(bho.mlx, "test.xpm", &bho.x, &bho.y); //assegno a una variabile vuota l'immagine che voglio stampare
	//mlx_hook(bho.win, 17, 0, close_windows, bho.mlx, bho.win);
	mlx_put_image_to_window(bho.mlx,bho.win, bho.gerry, 0, 0); //stampo l'immagine
	mlx_hook(bho.win, 2, 1L<<0, keycode, &bho);
	mlx_hook(bho.win, 17, 1L<<17, close_all, &bho);
	mlx_loop(bho.mlx);
}