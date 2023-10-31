/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:22:49 by mthibaul          #+#    #+#             */
/*   Updated: 2023/10/28 18:22:49 by mthibaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    print_player(t_cub *cub);
void	init_player(t_cub *cub);
void	find_angle(t_cub *cub);

void    find_player(t_cub *cub)
{
    int 		i;
    int 		j;

    i = -1;
	init_player(cub);
    while (cub->parsing.map[++i] && cub->player.x < 0)
    {
        j = -1;
        while (cub->parsing.map[i][++j] && cub->player.x < 0)
        {
            if (cub->parsing.map[i][j] == 'N' || cub->parsing.map[i][j] == 'S'
				|| cub->parsing.map[i][j] == 'E' || cub->parsing.map[i][j] == 'W')
			{
				cub->player.x = j;
				cub->player.y = i;
				cub->player.side = cub->parsing.map[i][j];
				find_angle(cub);
				print_player(cub);
			}
        }
    }
}

void    print_player(t_cub *cub)
{
    int line_count;
    int col_count;
    int count;

    line_count = 0;
    count = 0;
    cub->player.new_x = cub->player.x + cub->player.x * ZOOM;
    cub->player.new_y = cub->player.y + cub->player.y * ZOOM;
    while (line_count <= PLAYER_SIZE)
    {
        col_count = 0;
        while (col_count <= PLAYER_SIZE - (count * 2))
        {
            my_mlx_pixel_put(&cub->img, cub->player.new_x + col_count + count, cub->player.new_y - line_count, RED);
            col_count++;
        }
        line_count++;
        count++;
    }
}

void	move_player(t_cub *cub)
{
	int line_count;
	int col_count;
	int count;

	line_count = 0;
	count = 0;
	while (line_count <= PLAYER_SIZE)
	{
		col_count = 0;
		while (col_count <= PLAYER_SIZE - (count * 2))
		{
			my_mlx_pixel_put(&cub->img, cub->player.new_x + cub->player.horizontal + col_count + count, cub->player.new_y + cub->player.vertical - line_count, RED);
			col_count++;
		}
		line_count++;
		count++;
	}
}

void	find_angle(t_cub *cub)
{
	if (cub->player.side == 'N')
		cub->player.dir = 90;
	else if (cub->player.side == 'S')
		cub->player.dir = 270;
	else if (cub->player.side == 'E')
		cub->player.dir = 360;
	else
		cub->player.dir = 180;
}

void	init_player(t_cub *cub)
{
	cub->player.x = -1;
	cub->player.y = -1;
	cub->player.side = 0;
	cub->player.horizontal = 0;
	cub->player.vertical = 0;
}