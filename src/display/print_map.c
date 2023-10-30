/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:27:58 by mthibaul          #+#    #+#             */
/*   Updated: 2023/10/30 18:22:41 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    print_pixel(t_img *img, int color, int x, int y);

int print_map(t_cub *cub)
{
    int i;
    int j;

    i = -1;
    while (cub->parsing.map[++i])
    {
        j = -1;
        while (cub->parsing.map[i][++j])
        {
            if (cub->parsing.map[i][j] == '1')
                print_pixel(&cub->img, BROWN, j, i);
            else if (cub->parsing.map[i][j] == '0' || cub->parsing.map[i][j] == 'N'
                || cub->parsing.map[i][j] == 'E' || cub->parsing.map[i][j] == 'W'
                || cub->parsing.map[i][j] == 'S')
                print_pixel(&cub->img, WHITE, j, i);
            else
                print_pixel(&cub->img, BLACK, j, i);
        }
    }
	return (0);
}

void    print_pixel(t_img *img, int color, int x, int y)
{
    int line_count;
    int col_count;

    x += ZOOM * x;
    y += ZOOM * y;
    line_count = 0;
    while (line_count <= ZOOM)
    {
        col_count = 0;
        while (col_count <= ZOOM)
        {
			my_mlx_pixel_put(img, x + col_count, y + line_count, color);
			col_count++;
		}
		line_count++;
	}
}
