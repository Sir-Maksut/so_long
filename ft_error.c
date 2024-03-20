/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocaman <mkocaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:05:48 by mkocaman          #+#    #+#             */
/*   Updated: 2023/11/09 16:23:19 by mkocaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroyer_2(void	*map)
{
	t_map	*game;

	game = map;
	destroyer(game, 0, game->mapy);
	return (1);
}

void	destroy_image(t_map *map)
{
	if (map->e_image)
		mlx_destroy_image(map->mlx_ptr, map->e_image);
	if (map->w_image)
		mlx_destroy_image(map->mlx_ptr, map->w_image);
	if (map->p_image)
		mlx_destroy_image(map->mlx_ptr, map->p_image);
	if (map->f_image)
		mlx_destroy_image(map->mlx_ptr, map->f_image);
	if (map->c_image)
		mlx_destroy_image(map->mlx_ptr, map->c_image);
	if (map->mlx_ptr)
		mlx_destroy_window(map->mlx_ptr, map->win);
}

void	destroyer(t_map *map, int exit_code, int to_free)
{
	int	i;

	i = 0;
	if (exit_code == 42)
		ft_printf("Game Finished!\n");
	else if (exit_code == ESC || exit_code == 0)
		ft_printf("Game Cancelled\n");
	while ((i < map->mapy && to_free == 1)
		|| (i < map->mapy && to_free != 1
			&& to_free != 2 && to_free != 0))
		free(map->map[i++]);
	while ((i < map->mapy && exit_code > 0
			&& exit_code != 4 && to_free == 2)
		|| (i < map->mapy && to_free != 1
			&& to_free != 2 && to_free != 0))
		free(map->cmap[i++]);
	destroy_image(map);
	exit(1);
}

void	ft_error(t_map	*map, int x)
{
	while (x >= 0 && map->map[x])
	{
		free(map->map[x]);
		free(map->cmap[x]);
		x--;
	}
	ft_printf("ERROR");
	exit(1);
}
