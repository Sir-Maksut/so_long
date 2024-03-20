/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocaman <mkocaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:37:54 by mkocaman          #+#    #+#             */
/*   Updated: 2023/11/09 14:16:50 by mkocaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

# include "libft/libft.h"
# include "minilibx/mlx.h"

typedef struct s_list
{
	int		mapx;
	int		mapy;
	int		ecount;
	int		pcount;
	int		ccount;
	int		px;
	int		py;
	int		ex;
	int		ey;
	int		player_steps;
	char	**map;
	char	**cmap;
	void	*mlx_ptr;
	void	*win;
	void	*p_image;
	void	*c_image;
	void	*e_image;
	void	*f_image;
	void	*w_image;
}	t_map;

void	ft_error(t_map *map, int x);
void	map_control(t_map *map, int fd, char *map_name);
void	map_check(t_map *map);
void	game_start(t_map *game);
void	draw_image(t_map *game);
int		wasd_player(int key, t_map *map);
void	destroyer(t_map *map, int exit_code, int to_free);
int		destroyer_2(void	*map);

#endif
