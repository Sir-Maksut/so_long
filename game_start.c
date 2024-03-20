/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocaman <mkocaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:00:39 by mkocaman          #+#    #+#             */
/*   Updated: 2023/11/09 15:01:37 by mkocaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_points(t_map *game)
{
	int	x;
	int	y;

	game->p_image
		= mlx_xpm_file_to_image(game->mlx_ptr, "textures/s.xpm", &x, &y);
	game->c_image
		= mlx_xpm_file_to_image(game->mlx_ptr, "textures/g.xpm", &x, &y);
	game->e_image
		= mlx_xpm_file_to_image(game->mlx_ptr, "textures/p.xpm", &x, &y);
	game->w_image
		= mlx_xpm_file_to_image(game->mlx_ptr, "textures/w.xpm", &x, &y);
	game->f_image
		= mlx_xpm_file_to_image(game->mlx_ptr, "textures/f.xpm", &x, &y);
}

void	file_check(t_map *game)
{
	if (!game->c_image || !game->w_image
		|| !game->p_image || !game->e_image || !game->f_image)
	{
		ft_printf("Dosya adı yanlıs\n");
		ft_error(game, game->mapy - 1);
	}
}

void	draw_win(t_map *game, int y, int x)
{
	mlx_put_image_to_window(game->mlx_ptr,
		game->win, game->f_image, x * 32, y * 32);
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win, game->p_image, game->px * 32, game->py * 32);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win, game->e_image, game->ex * 32, game->ey * 32);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win, game->c_image, x * 32, y * 32);
	else if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win, game->w_image, x * 32, y * 32);
}

void	draw_image(t_map *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->mapy)
	{
		x = 0;
		while (x < game->mapx)
		{
			draw_win(game, y, x);
			x++;
		}
		y++;
	}
}

void	game_start(t_map *game)
{
	game->mlx_ptr = mlx_init();
	game->win = mlx_new_window(game->mlx_ptr,
			game->mapx * 32, game->mapy * 32, "so_long");
	image_points(game);
	file_check(game);
	draw_image(game);
	mlx_hook(game->win, 2, 0, wasd_player, game);
	mlx_hook(game->win, 17, 0, destroyer_2, game);
	mlx_loop(game->mlx_ptr);
}
