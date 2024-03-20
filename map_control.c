/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocaman <mkocaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:53:32 by mkocaman          #+#    #+#             */
/*   Updated: 2023/11/09 16:23:30 by mkocaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "so_long.h"

void	malloc_check(t_map *map)
{
	if (!map->map)
		destroyer(map, 1, 2);
	else if (!map->cmap)
		destroyer(map, 1, 1);
}

void	check_mapwidth(t_map *map, int fd)
{
	malloc_check(map);
	if (map->mapy == 0)
		map->mapx = ft_strlen(map->map[map->mapy]);
	else if (map->mapx != (int)ft_strlen(map->map[map->mapy]))
	{
		ft_printf("hatalı mapaaa");
		close(fd);
		ft_error(map, map->mapy);
	}
}

int	map_size(int fd)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	while (get_next_line(fd, &ptr) > 0)
	{
		free(ptr);
		i++;
	}
	close(fd);
	free(ptr);
	return (i);
}

void	valueset(t_map *map)
{
	map->map = NULL;
	map->cmap = NULL;
	map->mapx = 0;
	map->mapy = 0;
	map->ecount = 0;
	map->pcount = 0;
	map->ccount = 0;
	map->px = 0;
	map->py = 0;
	map->player_steps = 0;
}

void	map_control(t_map *map, int fd, char *map_name)
{
	int		len;
	char	*line;

	valueset(map);
	len = map_size(fd);
	map->map = (char **)malloc(sizeof(char *) * (len));
	map->cmap = (char **)malloc(sizeof(char *) * (len));
	malloc_check(map);
	fd = open(map_name, O_RDONLY);
	if (fd <= 0)
	{
		close(fd);
		ft_error(map, 0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		map->map[map->mapy] = ft_strdup(line);
		map->cmap[map->mapy] = ft_strdup(line);
		check_mapwidth(map, fd);
		free(line);
		map->mapy++;
	}
	close(fd);
	map_check(map);
}
