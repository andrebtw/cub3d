/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:20:52 by mthibaul          #+#    #+#             */
/*   Updated: 2023/11/09 10:25:12 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int check_movement(t_cub *cub);

void	move_player_angle(t_cub *cub)
{
	cub->player.dir += cub->player.rotating * ROTATE_SENS;
	if (cub->player.dir >= 360)
		cub->player.dir -= 360;
	if (cub->player.dir < 0)
		cub->player.dir += 360;
	if (cub->player.horizontal)
	{
		if (cub->player.horizontal == 1)
		{
			cub->player.x += sin(to_radians(cub->player.dir)) * SPEED_X;
			cub->player.y += cos(to_radians(cub->player.dir)) * SPEED_X;
		}
		else if (cub->player.horizontal == -1)
		{
			cub->player.x -= sin(to_radians(cub->player.dir)) * SPEED_X;
			cub->player.y -= cos(to_radians(cub->player.dir)) * SPEED_X;
		}
	}
	if (cub->player.vertical)
	{
		if (cub->player.vertical == 1)
		{
			cub->player.x += cos(to_radians(cub->player.dir)) * SPEED_Y;
			cub->player.y -= sin(to_radians(cub->player.dir)) * SPEED_Y;
		}
		else if (cub->player.vertical == -1)
		{
			cub->player.x -= cos(to_radians(cub->player.dir)) * SPEED_Y;
			cub->player.y += sin(to_radians(cub->player.dir)) * SPEED_Y;
		}
	}
}

int move_player_3D(t_cub *cub)
{
    // printf("X before : %f\n", cub->player.x);
    // cub->player.x += cub->player.horizontal * cos(to_radians(cub->player.dir)) * SPEED;
    // if (cos(to_radians(cub->player.dir)) == 0)
    // printf("X after : %f\n\n", cub->player.x);
    // cub->player.y += cub->player.vertical * sin(to_radians(cub->player.dir)) * SPEED;
	// if (sin(to_radians(cub->player.dir)) == 0)
		// cub->player.y += cub->player.vertical * SPEED;
	/*if (check_movement(cub) == 1)
	{
		cub->player.horizontal = 0;
		cub->player.vertical = 0;
		cub->player.rotating = 0;
		return (0);
	}*/
	move_player_angle(cub);
    ray_casting_main(cub);
	cub->player.horizontal = 0;
	cub->player.vertical = 0;
	cub->player.rotating = 0;
	// printf("X: %f\n", cub->player.x);
	// printf("Y: %f\n", cub->player.y);
	// printf("DIRECTION: %f\n", cub->player.dir);
    print_mapbg(cub);
	print_map(cub);
	print_player(cub);
    // move_player(cub);
    mlx_put_image_to_window(cub->mlx.ptr, cub->mlx.win, cub->img.img, 0, 0);
    return (EXIT_SUCCESS);
}

int check_movement(t_cub *cub)
{
	double x;
	double y;

	if (cub->player.horizontal)
	{
		if (cub->player.horizontal == 1)
		{
			x = cub->player.x + sin(to_radians(cub->player.dir)) * SPEED_X;
			y = cub->player.y + cos(to_radians(cub->player.dir)) * SPEED_X;
		}
		else if (cub->player.horizontal == -1)
		{
			x = cub->player.x -= sin(to_radians(cub->player.dir)) * SPEED_X;
			y = cub->player.y -= cos(to_radians(cub->player.dir)) * SPEED_X;
		}
	}
	if (cub->player.vertical)
	{
		if (cub->player.vertical == 1)
		{
			x = cub->player.x += cos(to_radians(cub->player.dir)) * SPEED_Y;
			y = cub->player.y -= sin(to_radians(cub->player.dir)) * SPEED_Y;
		}
		else if (cub->player.vertical == -1)
		{
			x = cub->player.x -= cos(to_radians(cub->player.dir)) * SPEED_Y;
			y = cub->player.y += sin(to_radians(cub->player.dir)) * SPEED_Y;
		}
	}
	if (cub->parsing.map[(int) floor(y / WALLS_SIZE)][(int) floor(x / WALLS_SIZE)] == '1')
		return (1);
	return (0);
}
