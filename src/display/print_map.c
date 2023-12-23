/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 < anrodri2@student.42lyon.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:27:58 by mthibaul          #+#    #+#             */
/*   Updated: 2023/11/29 17:28:45 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_pixel(t_cub *cub, int color, int x, int y);

void	get_ratio(t_cub *cub)
{
	int	biggest_x;
	int	y;

	y = -1;
	biggest_x = 0;
	while (cub->parsing.map[++y])
	{
		if (biggest_x <= (int)ft_strlen(cub->parsing.map[y]))
			biggest_x = (int)ft_strlen(cub->parsing.map[y]);
	}
	if (y > biggest_x)
		cub->map_ratio = (MAP_WIDTH / 2) / y;
	else
		cub->map_ratio = (MAP_WIDTH / 2) / biggest_x;
}

int	print_map(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	get_ratio(cub);
	while (cub->parsing.map[++i])
	{
		j = -1;
		while (cub->parsing.map[i][++j])
		{
			if (cub->parsing.map[i][j] == '1')
				print_pixel(cub, BROWN, j, i);
			else if (cub->parsing.map[i][j] == '0' || \
			cub->parsing.map[i][j] == 'N'
			|| cub->parsing.map[i][j] == 'E' || cub->parsing.map[i][j] == 'W'
			|| cub->parsing.map[i][j] == 'S')
				print_pixel(cub, WHITE, j, i);
			if (ft_strchr("NEWS", cub->parsing.map[i][j]))
			{
				cub->player.map_x = j;
				cub->player.map_y = i;
			}
		}
	}
	return (0);
}

void	print_pixel(t_cub *cub, int color, int x, int y)
{
	t_rect	rect;

	rect.x = (x * cub->map_ratio) + (MAP_OFFSET / 2);
	rect.y = (y * cub->map_ratio) + (MAP_OFFSET / 2);
	rect.height = cub->map_ratio;
	rect.width = cub->map_ratio;
	rect.colour = color;
	rect.is_borderless = TRUE;
	print_rect(&(cub->img), &rect);
}
