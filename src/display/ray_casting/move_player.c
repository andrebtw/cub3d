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

    x = 0;
    y = 0;
	if (cub->player.dir >= 360)
		cub->player.dir -= 360;
	if (cub->player.dir < 0)
		cub->player.dir += 360;
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
	x = floor(x / WALLS_SIZE);
	y = floor(y / WALLS_SIZE);
	if (x != 0)
		printf("X : %f || Y : %f  |||  Val : %c\n", x, y, cub->parsing.map[(int) y][(int) x]);
	if (cub->parsing.map[(int) y][(int) x] == '1')
		return (1);
	return (0);
}
