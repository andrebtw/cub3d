/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 < anrodri2@student.42lyon.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:20:52 by mthibaul          #+#    #+#             */
/*   Updated: 2023/11/29 17:11:34 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int check_movement(t_cub *cub);

void	move_player_angle(t_cub *cub)
{
	if (cub->player.rotating_right)
		cub->player.dir -= ROTATE_SENS;
	if (cub->player.rotating_left)
		cub->player.dir += ROTATE_SENS;
	if (cub->player.dir >= 360)
		cub->player.dir -= 360;
	if (cub->player.dir < 0)
		cub->player.dir += 360;
	if (cub->player.right)
	{
		cub->player.x += sin(to_radians(cub->player.dir)) * SPEED_X;
		cub->player.y += cos(to_radians(cub->player.dir)) * SPEED_X;
	}
	else if (cub->player.left)
	{
		cub->player.x -= sin(to_radians(cub->player.dir)) * SPEED_X;
		cub->player.y -= cos(to_radians(cub->player.dir)) * SPEED_X;
	}
	if (cub->player.forwards)
	{
		cub->player.x += cos(to_radians(cub->player.dir)) * (SPEED_Y + cub->player.sprint);
		cub->player.y -= sin(to_radians(cub->player.dir)) * (SPEED_Y + cub->player.sprint);
	}
	else if (cub->player.backwards)
	{
		cub->player.x -= cos(to_radians(cub->player.dir)) * SPEED_Y;
		cub->player.y += sin(to_radians(cub->player.dir)) * SPEED_Y;
	}
}

int move_player_3D(t_cub *cub)
{

	if (check_movement(cub) != 0)
        return (0);
    move_player_angle(cub);
    ray_casting_main(cub);
	// printf("X: %f\n", cub->player.x);
	// printf("Y: %f\n", cub->player.y);
	// printf("DIRECTION: %f\n", cub->player.dir);
	print_map(cub);
	print_player(cub);
    // move_player(cub);
    mlx_put_image_to_window(cub->mlx.ptr, cub->mlx.win, cub->img.img, 0, 0);
    return (EXIT_SUCCESS);
}

int check_movement(t_cub *cub)
{
	double	x;
	double	y;
	t_point	vertical;

    x = 0;
    y = 0;
	vertical.x = 2;
	vertical.y = 2;
    if (cub->player.dir < 90 || cub->player.dir > 270)
		vertical.y *= -1;
	if (cub->player.dir <= 180 && cub->player.dir >= 0)
		vertical.x *= -1;
    if (cub->player.right)
    {
        x = cub->player.x - vertical.x + sin(to_radians(cub->player.dir)) * SPEED_X;
        y = cub->player.y - vertical.y + cos(to_radians(cub->player.dir)) * SPEED_X;
    }
    else if (cub->player.left)
    {
        x = cub->player.x + vertical.x - sin(to_radians(cub->player.dir)) * SPEED_X;
        y = cub->player.y + vertical.y - cos(to_radians(cub->player.dir)) * SPEED_X;
    }
    if (cub->player.forwards)
    {
        x = cub->player.x - vertical.y + cos(to_radians(cub->player.dir)) * (SPEED_Y + cub->player.sprint);
        y = cub->player.y + vertical.x - sin(to_radians(cub->player.dir)) * (SPEED_Y + cub->player.sprint);
    }
    else if (cub->player.backwards)
    {
        x = cub->player.x + vertical.y - cos(to_radians(cub->player.dir)) * SPEED_Y;
        y = cub->player.y - vertical.x + sin(to_radians(cub->player.dir)) * SPEED_Y;
    }
	x = floor(x / WALLS_SIZE);
	y = floor(y / WALLS_SIZE);
	if (cub->parsing.map[(int) y][(int) x] == '1')
		return (1);
	return (0);
}
