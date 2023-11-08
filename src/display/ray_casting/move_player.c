/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:20:52 by mthibaul          #+#    #+#             */
/*   Updated: 2023/11/03 19:20:52 by mthibaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_player_angle(t_cub *cub)
{
	cub->player.dir += cub->player.rotating * ROTATE_SENS;
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
		// cub->player.y += sin(to_radians(cub->player.dir)) * SPEED;
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
	move_player_angle(cub);
    ray_casting_main(cub);
	cub->player.horizontal = 0;
	cub->player.vertical = 0;
	cub->player.rotating = 0;
	printf("X: %f\n", cub->player.x);
	printf("Y: %f\n", cub->player.y);
	printf("DIRECTION: %f\n", cub->player.dir);
    print_mapbg(cub);
	print_map(cub);
    // move_player(cub);
    mlx_put_image_to_window(cub->mlx.ptr, cub->mlx.win, cub->img.img, 0, 0);
    return (0);
}
