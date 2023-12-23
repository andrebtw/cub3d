/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 < anrodri2@student.42lyon.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:20:52 by mthibaul          #+#    #+#             */
/*   Updated: 2023/12/14 20:15:13 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_player_angle2(t_cub *cub);
int		check_movement(t_cub *cub);
void	check_movement2(t_cub *cub, t_point vertical, t_point *pos);

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
	move_player_angle2(cub);
}

void	move_player_angle2(t_cub *cub)
{
	if (cub->player.forwards)
	{
		cub->player.x += cos(to_radians(cub->player.dir)) \
		* (SPEED_Y + cub->player.sprint);
		cub->player.y -= sin(to_radians(cub->player.dir)) \
		* (SPEED_Y + cub->player.sprint);
	}
	else if (cub->player.backwards)
	{
		cub->player.x -= cos(to_radians(cub->player.dir)) * SPEED_Y;
		cub->player.y += sin(to_radians(cub->player.dir)) * SPEED_Y;
	}
}

int	move_player_3d(t_cub *cub)
{
	print_map(cub);
	if ((cub->player.left || cub->player.right) || (\
	cub->player.forwards || cub->player.backwards))
	{
		cub->is_colision = check_movement(cub);
		if (cub->is_colision)
			return (EXIT_FAILURE);
	}
	move_player_angle(cub);
	ray_casting_main(cub);
	print_map(cub);
	print_player(cub);
	mlx_put_image_to_window(cub->mlx.ptr, cub->mlx.win, cub->img.img, 0, 0);
	return (EXIT_SUCCESS);
}

int	check_movement(t_cub *cub)
{
	t_point	pos;
	t_point	vertical;

	pos.x = 0;
	pos.y = 0;
	vertical.x = 5;
	vertical.y = 5;
	if (cub->player.dir < 90 || cub->player.dir > 270)
		vertical.y *= -1;
	if (cub->player.dir <= 180 && cub->player.dir >= 0)
		vertical.x *= -1;
	if (cub->player.right)
	{
		pos.x = cub->player.x - vertical.x + \
		sin(to_radians(cub->player.dir)) * SPEED_X;
		pos.y = cub->player.y - vertical.y + \
		cos(to_radians(cub->player.dir)) * SPEED_X;
	}
	check_movement2(cub, vertical, &pos);
	pos.x = floor(pos.x / WALLS_SIZE);
	pos.y = floor(pos.y / WALLS_SIZE);
	if (cub->parsing.map[(int) pos.y][(int) pos.x] == '1')
		return (1);
	return (0);
}

void	check_movement2(t_cub *cub, t_point vertical, t_point *pos)
{
	if (cub->player.left)
	{
		pos->x = cub->player.x + vertical.x - \
		sin(to_radians(cub->player.dir)) * SPEED_X;
		pos->y = cub->player.y + vertical.y - \
		cos(to_radians(cub->player.dir)) * SPEED_X;
	}
	if (cub->player.forwards)
	{
		pos->x = cub->player.x - vertical.y + \
		cos(to_radians(cub->player.dir)) * (SPEED_Y + cub->player.sprint);
		pos->y = cub->player.y + vertical.x - \
		sin(to_radians(cub->player.dir)) * (SPEED_Y + cub->player.sprint);
	}
	else if (cub->player.backwards)
	{
		pos->x = cub->player.x + vertical.y - \
		cos(to_radians(cub->player.dir)) * SPEED_Y;
		pos->y = cub->player.y - vertical.x + \
		sin(to_radians(cub->player.dir)) * SPEED_Y;
	}
}
