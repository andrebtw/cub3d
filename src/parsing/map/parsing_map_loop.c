/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:09:25 by anrodri2          #+#    #+#             */
/*   Updated: 2023/10/24 16:25:06 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#define NOT_WALLS "0NSEW"

int	check_if_out(t_cub *cub, size_t *y, size_t *x, size_t last_y)
{
	if (*y == last_y)
		return (EXIT_FAILURE);
	if (*y == 1)
		return (EXIT_FAILURE);
	if (*x == 0)
		return (EXIT_FAILURE);
	if (cub->parsing.map[*y][*x + 1] == '\n')
		return (EXIT_FAILURE);
	if (ft_strlen(cub->parsing.map[*y - 1]) - 1 <= *x)
		return (EXIT_FAILURE);
	if (cub->parsing.map[*y - 1][*x] == ' ')
		return (EXIT_FAILURE);
	if (cub->parsing.map[*y + 1][*x] == ' ')
		return (EXIT_FAILURE);
	if (cub->parsing.map[*y][*x - 1] == ' ')
		return (EXIT_FAILURE);
	if (cub->parsing.map[*y][*x + 1] == ' ')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_zeros(t_cub *cub, size_t *y, size_t *x, size_t last_y)
{
	while (cub->parsing.map[*y])
	{
		*x = 0;
		while (cub->parsing.map[*y][*x])
		{
			if (ft_strchr(NOT_WALLS, cub->parsing.map[*y][*x]))
			{
				if (check_if_out(cub, y, x, last_y))
				{
					ft_putstr_fd(MSG_ERR_MAP_NOT_CLOSED, STDERR_FILENO);
					return (EXIT_FAILURE);
				}
			}
			*x = *x + 1;
		}
		*y = *y + 1;
	}
	return (EXIT_SUCCESS);
}

size_t	map_size(t_cub *cub)
{
	size_t	index;

	index = 0;
	if (!cub->parsing.map[index])
		return (index);
	while (cub->parsing.map[index])
		index++;
	return (index - 1);
}

int	parsing_map_loop(t_cub *cub)
{
	size_t	y;
	size_t	x;
	size_t	last_y;

	y = 1;
	last_y = map_size(cub);
	if (check_zeros(cub, &y, &x, last_y))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
