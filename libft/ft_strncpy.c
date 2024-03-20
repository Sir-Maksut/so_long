/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocaman <mkocaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:06:31 by mkocaman          #+#    #+#             */
/*   Updated: 2023/11/02 13:20:30 by mkocaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, char *src, size_t len)
{
	size_t	counter;
	char	*pointer_to_dest_start;
	size_t	src_len;

	pointer_to_dest_start = dst;
	src_len = ft_strlen(src);
	counter = 0;
	while (counter < len)
	{
		if (counter < src_len)
		{
			*dst = *src;
			src++;
		}
		else
			*dst = '\0';
		dst++;
		counter++;
	}
	return (pointer_to_dest_start);
}
