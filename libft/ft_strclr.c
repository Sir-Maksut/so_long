/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocaman <mkocaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:36:35 by mkocaman          #+#    #+#             */
/*   Updated: 2023/11/02 13:27:40 by mkocaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strclr(char *s)
{
	if (s != 0)
	{
		while (s != 0 && *s != '\0')
		{
			*s = '\0';
			s++;
		}
	}
}