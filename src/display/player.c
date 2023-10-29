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

void    print_player(t_img *img, int x, int y, char side);

void    find_player(t_cub *cub)
{
    int i;
    int j;

    i = -1;
    while (cub->parsing.map[++i])
    {
        j = -1;
        while (cub->parsing.map[i][++j])
        {
            if (cub->parsing.map[i][j] == 'N')
                print_player(&cub->img, j, i, 'N');
            else if (cub->parsing.map[i][j] == 'S')
                print_player(&cub->img, j, i, 'S');
            else if (cub->parsing.map[i][j] == 'E')
                print_player(&cub->img, j, i, 'E');
            else if (cub->parsing.map[i][j] == 'W')
                print_player(&cub->img, j, i, 'W');
        }
    }
}

void    print_player(t_img *img, int x, int y, char side)
{
    int line_count;
    int col_count;
    int count;

    (void) side;
    line_count = 0;
    count = 0;
    x += x * ZOOM + ZOOM / 2;
    y += (y + 1) * ZOOM;
    while (line_count <= 7)
    {
        col_count = 0;
        while (col_count <= 7 - (count * 2))
        {
            my_mlx_pixel_put(img, x + col_count + count, y - line_count, RED);
            col_count++;
        }
        line_count++;
        count++;
    }
}