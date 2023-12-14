/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:38:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/10/30 16:38:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		cast_rays(t_cub *cub);
double	horizontal_intersections(t_cub *cub, double ray_angle, int *x_coord);
double	vertical_intersections(t_cub *cub, double ray_angle, int *y_coord);

int	ray_casting_main(t_cub *cub)
{
	init_ray_cast(cub);
	cast_rays(cub);
	return (0);
}

int	cast_rays(t_cub *cub)
{
	t_ray_data		ray;
	t_point			walls;
	t_displayed_col	displayed_col;

	ray.angle = cub->player.dir + (FOV / 2);
	ray.nmb = 0;
	displayed_col.x = 0;
	displayed_col.y = 0;
	while (ray.nmb < RES_WIDTH)
	{
		if (ray.angle > 360)
			ray.angle -= 360;
		if (ray.angle < 0)
			ray.angle += 360;
		walls.x = horizontal_intersections(cub, ray.angle, &displayed_col.x);
		walls.y = vertical_intersections(cub, ray.angle, &displayed_col.y);
		find_smallest_dist(cub, walls, &displayed_col, ray);
		ray.angle -= cub->ray.angle_btw_ray;
		ray.nmb++;
	}
	return (0);
}

double	horizontal_intersections(t_cub *cub, double ray_angle, int *x_coord)
{
	t_intersection	inter;
	t_point			a;

	inter.side = 'x';
	if (ray_angle >= 0 && ray_angle <= 180)
	{
		inter.coord.y = floor(cub->player.y / WALLS_SIZE) * WALLS_SIZE - 0.001;
		a.y = -WALLS_SIZE;
	}
	else
	{
		inter.coord.y = floor(cub->player.y / \
		WALLS_SIZE) * WALLS_SIZE + WALLS_SIZE;
		a.y = WALLS_SIZE;
	}
	a.x = WALLS_SIZE / tan(to_radians(ray_angle));
	inter.coord.x = cub->player.x + (cub->player.y - inter.coord.y) \
	/ tan(to_radians(ray_angle));
	if ((ray_angle < 270 && ray_angle > 90) && a.x > 0)
		a.x *= -1;
	if ((ray_angle >= 270 || ray_angle <= 90) && a.x < 0)
		a.x *= -1;
	if (check_error_in_ray(cub, inter))
		return (-1);
	return (increment_ray(cub, &inter, a, x_coord));
}

double	vertical_intersections(t_cub *cub, double ray_angle, int *y_coord)
{
	t_intersection	inter;
	t_point			a;

	inter.side = 'y';
	if (ray_angle >= 270 || ray_angle <= 90)
	{
		inter.coord.x = floor(cub->player.x / \
		WALLS_SIZE) * WALLS_SIZE + WALLS_SIZE;
		a.x = WALLS_SIZE;
	}
	else
	{
		inter.coord.x = floor(cub->player.x / WALLS_SIZE) * WALLS_SIZE - 0.001;
		a.x = -WALLS_SIZE;
	}
	a.y = WALLS_SIZE * tan(to_radians(ray_angle));
	if (ray_angle > 0 && ray_angle < 180 && a.y > 0)
		a.y *= -1;
	if ((ray_angle <= 0 || ray_angle >= 180) && a.y < 0)
		a.y *= -1;
	inter.coord.y = cub->player.y + (cub->player.x - inter.coord.x) \
	* tan(to_radians(ray_angle));
	if (check_error_in_ray(cub, inter))
		return (-1);
	return (increment_ray(cub, &inter, a, y_coord));
}

int	check_wall(t_cub *cub, t_point inter)
{
	int	x;
	int	y;

	x = floor(inter.x / WALLS_SIZE);
	y = floor(inter.y / WALLS_SIZE);
	if (cub->parsing.map[y][x] == '1')
		return (0);
	return (1);
}
