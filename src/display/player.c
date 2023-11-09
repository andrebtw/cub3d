/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:22:49 by mthibaul          #+#    #+#             */
/*   Updated: 2023/10/30 18:23:50 by anrodri2         ###   ########.fr       */
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
			}
        }
    }
	cub->player.x = (cub->player.x * WALLS_SIZE) + (WALLS_SIZE / 2);
	cub->player.y = (cub->player.y * WALLS_SIZE) + (WALLS_SIZE / 2);
}

void	find_angle(t_cub *cub)
{
	if (cub->player.side == 'N')
		cub->player.dir = 90;
	else if (cub->player.side == 'S')
		cub->player.dir = 270;
	else if (cub->player.side == 'E')
		cub->player.dir = 0;
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
