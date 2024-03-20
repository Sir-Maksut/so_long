/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocaman <mkocaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:11:22 by mkocaman          #+#    #+#             */
/*   Updated: 2023/11/06 12:37:16 by mkocaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_coo(t_map *data, int x, int y)
{
	if (data->map[data->py + y][data->px + x] == '1')
		return ;
	if (data->ccount == 0
		&& data->map[data->py + y][data->px + x] == 'E')
		destroyer(data, 42, 2);
	else if (data->map[data->py + y][data->px + x] == 'E')
		return ;
	if (data->map[data->py + y][data->px + x] == 'C')
		data->ccount--;
	data->map[data->py][data->px] = '0';
	data->px += x;
	data->py += y;
	data->map[data->py][data->px] = 'P';
	data->player_steps++;
	draw_image(data);
	ft_printf("Steps %d\n", data->player_steps);
}

int	wasd_player(int key, t_map *map)
{
	if (key == ESC)
		destroyer(map, ESC, 2);
	else if (key == W)
		player_coo(map, 0, -1);
	else if (key == A)
		player_coo(map, -1, 0);
	else if (key == S)
		player_coo(map, 0, 1);
	else if (key == D)
		player_coo(map, 1, 0);
	else
		return (0);
	return (1);
}
