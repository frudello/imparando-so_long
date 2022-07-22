/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:15:02 by frudello          #+#    #+#             */
/*   Updated: 2022/07/02 13:45:30 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_line(int fd)
{
	char	a[999999];
	char	buffer[1];
	char	*new_a;
	int		i;

	i = 0;
	a[i] = 0;
	while (read(fd, buffer, 1) == 1)
	{
		a[i] = buffer[0];
		a[i + 1] = '\0';
		if (a[i] == '\0' || !a[i])
			break ;
		i++;
	}
	new_a = malloc(i + 1);
	if (!new_a)
		return (NULL);
	i = -1;
	while (a[++i])
		new_a[i] = a[i];
	return (new_a);
}

char	**smap(char *wam)
{
	char	*pippo;
	char	**map;
	int		fd;

	fd = open(wam, O_RDONLY);
	if (fd < 1)
	{
		ft_putstr("errato scemodemmerdaa\n");
		return (NULL);
	}
	pippo = get_next_line(fd);
	map = ft_split(pippo, '\n');
	free(pippo);
	return (map);
}
