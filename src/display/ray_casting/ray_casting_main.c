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
	int		ray_nmb;

	ray_angle = cub->player.dir - 30;
	ray_nmb = 0;
	while (ray_nmb < RES_WIDTH)
	{
		horizontal_intersections(cub, ray_angle);
		ray_angle += cub->ray.angle_btw_ray;
		ray_nmb++;
	}
	return (0);
}

double horizontal_intersections(t_cub *cub, double ray_angle)
{
	t_point	inter;
	t_point	a;

	printf("ANGLE : %f\n", ray_angle);
	if (ray_angle > 0 && ray_angle < 180)
	{
		inter.y = cub->player.y * WALLS_SIZE - 1;
		a.y = - WALLS_SIZE;
	}
	else
	{
		inter.y = cub->player.y * WALLS_SIZE + 64;
		a.y = WALLS_SIZE;
	}
	a.x = WALLS_SIZE / tan(to_radians(ray_angle));
	inter.x = cub->player.x * WALLS_SIZE + ((cub->player.y * 64) - inter.y) / tan(to_radians(ray_angle));
	while (check_wall(cub, inter) != 0)
	{
		inter.x += a.x;
		inter.y += a.y;
	}
	return (0);
}

int check_wall(t_cub *cub, t_point inter)
{
	if (cub->parsing.map[(int) inter.y / 64][(int) floor(inter.x / 64)] == '1')
	{
		printf("WALL : Y:%f   || X:%f\n", floor(inter.y / 64), floor(inter.x / 64));
		return (0);
	}
	return (1);
}