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

int move_player_3D(t_cub *cub)
{
    // printf("X before : %f\n", cub->player.x);
    cub->player.x += cub->player.horizontal * cos(to_radians(cub->player.dir)) * SPEED;
    if (cos(to_radians(cub->player.dir)) == 0)
        cub->player.x += cub->player.horizontal * SPEED;
    // printf("X after : %f\n\n", cub->player.x);
    cub->player.y += cub->player.vertical * sin(to_radians(cub->player.dir)) * SPEED;
    ray_casting_main(cub);
    cub->player.horizontal = 0;
    cub->player.vertical = 0;
    print_mapbg(cub);
	print_map(cub);
    move_player(cub);
    mlx_put_image_to_window(cub->mlx.ptr, cub->mlx.win, cub->img.img, 0, 0);
    return (0);
}
