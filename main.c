/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocaman <mkocaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:33:56 by mkocaman          #+#    #+#             */
/*   Updated: 2023/11/09 12:02:02 by mkocaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "so_long.h"

int	map_namecheck(char *str)
{
	int	i;

	i = (ft_strlen(str) - 1);
	if (str[i] != 'r')
		return (0);
	if (str[i - 1] != 'e')
		return (0);
	if (str[i - 2] != 'b')
		return (0);
	if (str[i - 3] != '.')
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int		fd;
	t_map	map;

	if (ac == 2)
	{
		if (!map_namecheck(av[1]))
		{
			ft_printf("Map Adı Yanlış!!");
			return (1);
		}
		fd = open(av[1], O_RDONLY);
		if (fd <= 0)
		{
			ft_printf("map açılamadı");
			close(fd);
			return (1);
		}
		map_control(&map, fd, av[1]);
		game_start(&map);
	}
	return (0);
}
