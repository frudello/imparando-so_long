/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:29:33 by frudello          #+#    #+#             */
/*   Updated: 2022/06/30 18:19:51 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initial_value(t_map *map)
{
	map->check.collect = 0;
	map->check.correct = true;
	map->check.enemy = 0;
	map->check.exit = 0;
	map->check.pos = 0;
	map->check.space = 0;
	map->check.wall = 0;
	map->collezionabile = 0;
	map->mosse = 0;
	map->n_anim = 0;
	map->status = IN_GAME;
	map->delay = 0;
	map->e_delay = 0;
	map->can_staff_move = true;
}