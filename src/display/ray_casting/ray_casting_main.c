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
double  vertical_intersections(t_cub *cub, double ray_angle);
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

	ray_angle = cub->player.dir + (FOV / 2);
	ray_nmb = 0;
	//printf("Angle : %f\n", cub->player.dir);
	while (ray_nmb < RES_WIDTH)
	{
		if (ray_angle > 360)
			ray_angle -= 360;
		if (ray_angle < 0)
			ray_angle += 360;
		wall_h = horizontal_intersections(cub, ray_angle);
		wall_v = vertical_intersections(cub, ray_angle);
		//wall_v = -1;
        //printf("Wall H : %f || Wall V : %f\n", wall_h, wall_v);
		if ((wall_h >= wall_v && wall_v > 0) || wall_h < 0)
		{
			//printf("Angle : %f || Nmb : %d\n", ray_angle, ray_nmb);
            if (ray_angle <= 90 || ray_angle >= 270)
			    draw_walls(cub, wall_v * cos(to_radians(cub->player.dir - ray_angle)), ray_nmb, WE);
            else
                draw_walls(cub, wall_v * cos(to_radians(cub->player.dir - ray_angle)), ray_nmb, EA);
		}
		else
        {
            if (ray_angle >= 0 && ray_angle <= 180)
                draw_walls(cub, wall_h * cos(to_radians(cub->player.dir - ray_angle)), ray_nmb, SO);
            else
                draw_walls(cub, wall_h * cos(to_radians(cub->player.dir - ray_angle)), ray_nmb, NO);
        }
		ray_angle -= cub->ray.angle_btw_ray;
		ray_nmb++;
	}
	return (0);
}

double horizontal_intersections(t_cub *cub, double ray_angle)
{
	t_point	inter;
	t_point	a;

	if (ray_angle >= 0 && ray_angle <= 180)
	{
		inter.y = floor(cub->player.y / WALLS_SIZE) * WALLS_SIZE - 0.001;
		a.y = -WALLS_SIZE;
	}
	else
	{
		inter.y = floor(cub->player.y / WALLS_SIZE) * WALLS_SIZE + WALLS_SIZE;
		a.y = WALLS_SIZE;
	}
	a.x = WALLS_SIZE / tan(to_radians(ray_angle));
    inter.x = cub->player.x + (cub->player.y - inter.y) / tan(to_radians(ray_angle));
	if ((ray_angle < 270 && ray_angle > 90) && a.x > 0)
        a.x *= -1;
	if ((ray_angle >= 270 || ray_angle <= 90) && a.x < 0)
		a.x *= -1;
    if (inter.y < 0 || inter.x < 0 || inter.y / WALLS_SIZE >= cub->parsing.map_max_y || inter.x / WALLS_SIZE >= cub->parsing.map_max_x)
		return (-1);
    while (check_wall(cub, inter) != 0)
	{
		inter.x += a.x;
		inter.y += a.y;
        if (inter.y < 0 || inter.x < 0 || inter.y / WALLS_SIZE >= cub->parsing.map_max_y || inter.x / WALLS_SIZE >= cub->parsing.map_max_x)
            return (-1);
	}
	return (calc_wall_distance(cub, inter));
}

double vertical_intersections(t_cub *cub, double ray_angle)
{
	t_point inter;
	t_point a;

	if (ray_angle >= 270 || ray_angle <= 90)
	{
		inter.x = floor(cub->player.x / WALLS_SIZE) * WALLS_SIZE + WALLS_SIZE;
		a.x = WALLS_SIZE;
	}
	else
	{
		inter.x = floor(cub->player.x / WALLS_SIZE) * WALLS_SIZE - 0.001;
		a.x = -WALLS_SIZE;
	}
	a.y = WALLS_SIZE * tan(to_radians(ray_angle));
	if (ray_angle > 0 && ray_angle < 180 && a.y > 0)
        a.y *= -1;
	if ((ray_angle <= 0 || ray_angle >= 180) && a.y < 0)
		a.y *= -1;
	inter.y = cub->player.y + (cub->player.x - inter.x) * tan(to_radians(ray_angle));
    if (inter.y < 0 || inter.x < 0 || inter.y / WALLS_SIZE >= cub->parsing.map_max_y || inter.x / WALLS_SIZE >= cub->parsing.map_max_x)
		return (-1);
    while (check_wall(cub, inter) != 0)
	{
		inter.x += a.x;
		inter.y += a.y;
        if (inter.y < 0 || inter.x < 0 || inter.y / WALLS_SIZE >= cub->parsing.map_max_y || inter.x / WALLS_SIZE >= cub->parsing.map_max_x)
			return (-1);
	}
	return (calc_wall_distance(cub, inter));
}

int check_wall(t_cub *cub, t_point inter)
{
	int x;
	int y;

	x = floor(inter.x / WALLS_SIZE);
	y = floor(inter.y / WALLS_SIZE);
	if (cub->parsing.map[y][x] == '1')
    {
        //printf("Inter x : %d || Inter y : %d\n", x, y);
        //printf("WALL\n\n");
        return (0);
    }
	return (1);
}