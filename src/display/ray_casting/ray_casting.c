/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:20:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/12/14 02:20:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	find_smallest_dist(t_cub *cub, t_point walls, \
		t_displayed_col *displayed_col, t_ray_data ray)
{
	if ((walls.x >= walls.y && walls.y > 0) || walls.x < 0)
	{
		displayed_col->x = -1;
		if (ray.angle <= 90 || ray.angle >= 270)
			displayed_col->texture = &(cub->ea);
		else
			displayed_col->texture = &(cub->we);
		draw_walls(cub, walls.y * cos(to_radians(ray.angle \
			- cub->player.dir)), ray.nmb, displayed_col);
	}
	else
	{
		if (ray.angle >= 0 && ray.angle <= 180)
			displayed_col->texture = &(cub->no);
		else
			displayed_col->texture = &(cub->so);
		draw_walls(cub, walls.x * cos(to_radians(ray.angle \
			- cub->player.dir)), ray.nmb, displayed_col);
	}
}

double	increment_ray(t_cub *cub, t_intersection *inter, \
		t_point a, int *int_coord)
{
	while (check_wall(cub, inter->coord) != 0)
	{
		inter->coord.x += a.x;
		inter->coord.y += a.y;
		if (check_error_in_ray(cub, *inter))
			return (-1);
	}
	if (inter->side == 'x')
		*int_coord = (int) floor(inter->coord.x) % (int) WALLS_SIZE;
	else
		*int_coord = (int) floor(inter->coord.y) % (int) WALLS_SIZE;
	return (calc_wall_distance(cub, inter->coord));
}

int	check_error_in_ray(t_cub *cub, t_intersection inter)
{
	if (inter.coord.y < 0 || inter.coord.x < 0 || inter.coord.y / WALLS_SIZE >= \
cub->parsing.map_max_y || inter.coord.x / WALLS_SIZE >= cub->parsing.map_max_x)
		return (1);
	return (0);
}
