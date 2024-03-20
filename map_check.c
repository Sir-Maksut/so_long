/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocaman <mkocaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:45:25 by mkocaman          #+#    #+#             */
/*   Updated: 2023/11/09 14:36:33 by mkocaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_surrounded(t_map *map, int y, int x)
{
	if ((y == 0 || x == 0 || x == map->mapx - 1
			|| y == map->mapy - 1) && map->map[y][x] != '1')
		ft_error(map, y);
}

void	map_set(t_map *map, int y, int x)
{
	if (map->map[y][x] == 'E')
	{
		map->ecount++;
		map->ex = x;
		map->ey = y;
	}
	if (map->map[y][x] == 'P')
	{
		map->pcount++;
		map->px = x;
		map->py = y;
	}
	if (map->map[y][x] == 'C')
		map->ccount++;
	if (y == map->mapy - 1 && (map->pcount != 1 || map->ecount != 1))
		ft_error(map, map->mapy - 1);
}

void	is_reachable(char **map, int y, int x)
{
	if (map[y][x] == '#' || map[y][x] == '1')
		return ;
	map[y][x] = '#';
	is_reachable(map, y + 1, x);
	is_reachable(map, y - 1, x);
	is_reachable(map, y, x + 1);
	is_reachable(map, y, x - 1);
}

void	rem_coin(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->mapy)
	{
		x = 0;
		while (x < map->mapx)
		{
			if (map->cmap[y][x] != '1' && map->cmap[y][x] != '#'
				&& map->cmap[y][x] != '0')
				ft_error(map, map->mapy -1);
			x++;
		}
		y++;
	}
}

void	map_check(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y <= map->mapy -1)
	{
		x = 0;
		while (x <= map->mapx -1)
		{
			is_surrounded(map, y, x);
			map_set(map, y, x);
			if (map->map[y][x] != '1' && map->map[y][x] != 'P'
			&& map->map[y][x] != 'E' && map->map[y][x] != 'C'
			&& map->map[y][x] != '0')
				ft_error(map, map->mapy - 1);
			x++;
		}
		y++;
	}
	is_reachable(map->cmap, map->py, map->px);
	rem_coin(map);
}
