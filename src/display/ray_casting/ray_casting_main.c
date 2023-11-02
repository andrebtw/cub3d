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
double	horizontal_intersections(t_cub *cub, double ray_angle);
double vertical_intersections(t_cub *cub, double ray_angle);
int		check_wall(t_cub *cub, t_point inter);

int ray_casting_main(t_cub *cub)
{
	init_ray_cast(cub);
	cast_rays(cub);
	return (0);
}

int cast_rays(t_cub *cub)
{
	double	ray_angle;
	double	wall_h;
	double	wall_v;
	int		ray_nmb;

	ray_angle = cub->player.dir - 30;
	ray_nmb = -1;
	while (++ray_nmb < RES_WIDTH)
	{
		wall_h = horizontal_intersections(cub, ray_angle);
		wall_v = vertical_intersections(cub, ray_angle);
		if (wall_h > wall_v)
			draw_walls(cub, wall_v, ray_nmb);
		else
			draw_walls(cub, wall_h, ray_nmb);
		ray_angle += cub->ray.angle_btw_ray;
	}
	return (0);
}

double horizontal_intersections(t_cub *cub, double ray_angle)
{
	t_point	inter;
	t_point	a;

	if (ray_angle >= 0 && ray_angle <= 180)
	{
		inter.y = floor(cub->player.y / WALLS_SIZE) * WALLS_SIZE - 1;
		a.y = -WALLS_SIZE;
	}
	else
	{
		inter.y = floor(cub->player.y / WALLS_SIZE) * WALLS_SIZE + 64;
		a.y = WALLS_SIZE;
	}
	a.x = floor(WALLS_SIZE / tan(to_radians(ray_angle)));
	inter.x = floor(cub->player.x + (cub->player.y - inter.y) / tan(to_radians(ray_angle)));
	while (check_wall(cub, inter) != 0)
	{
		inter.x += a.x;
		inter.y += a.y;
	}
	return (calc_wall_ditance(cub, inter, ray_angle));
}

double vertical_intersections(t_cub *cub, double ray_angle)
{
	t_point inter;
	t_point a;

	if (ray_angle >= 270 || ray_angle <= 90)
	{
		inter.x = floor(cub->player.x / WALLS_SIZE) * WALLS_SIZE + 64;
		a.x = WALLS_SIZE;
	}
	else
	{
		inter.x = floor(cub->player.x / WALLS_SIZE) * WALLS_SIZE - 1;
		a.x = -WALLS_SIZE;
	}
	a.y = WALLS_SIZE * tan(to_radians(ray_angle));
	inter.y = floor(cub->player.y + (cub->player.x - inter.x) * tan(to_radians(ray_angle)));
	if (inter.y < 0)
		inter.y = 0;
	while (check_wall(cub, inter) != 0)
	{
		inter.x += a.x;
		inter.y += a.y;
		if (inter.y < 0)
			inter.y = 0;
	}
	return (calc_wall_ditance(cub, inter, ray_angle));
}

int check_wall(t_cub *cub, t_point inter)
{
	int x;
	int y;

	x = floor(inter.x / 64);
	y = floor(inter.y / 64);
	if (cub->parsing.map[y][x] == '1')
		return (0);
	return (1);
}