/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:09:25 by anrodri2          #+#    #+#             */
/*   Updated: 2023/10/19 12:18:01 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parsing_map_loop(t_cub *cub)
{
	size_t	y;
	size_t	x;
	
	y = 0;
	while (cub->parsing.map[y])
	{
		x = 0;
		while (cub->parsing.map[y][x])
		{
			if (cub->parsing.map[y][x] == ' ')
				x++;
			if (cub->parsing.map[y][x] == '1')
				
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}
