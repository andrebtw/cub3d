/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:27:58 by mthibaul          #+#    #+#             */
/*   Updated: 2023/11/03 19:25:53 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    print_pixel(t_cub *cub, int color, int x, int y);

void    get_ratio(t_cub *cub)
{
    int biggest_x;
    int y;

    y = -1;
    biggest_x = 0;
    while (cub->parsing.map[++y])
    {
		if (biggest_x <= (int)ft_strlen(cub->parsing.map[y]))
			biggest_x = (int)ft_strlen(cub->parsing.map[y]);
    }
	if (y > biggest_x)
		cub->map_ratio = ZOOM * ;
	else
		cub->map_ratio = ZOOM * ;
}

int print_map(t_cub *cub)
{
    int i;
    int j;

    i = -1;
	get_ratio(cub);
    while (cub->parsing.map[++i])
    {
        j = -1;
        while (cub->parsing.map[i][++j])
        {
            if (cub->parsing.map[i][j] == '1')
                print_pixel(cub, BROWN, j, i);
            else if (cub->parsing.map[i][j] == '0' || cub->parsing.map[i][j] == 'N'
                || cub->parsing.map[i][j] == 'E' || cub->parsing.map[i][j] == 'W'
                || cub->parsing.map[i][j] == 'S')
                print_pixel(cub, WHITE, j, i);
            // else
                // print_pixel(&cub->img, BLACK, j, i);
        }
    }
	return (0);
}

void    print_pixel(t_cub *cub, int color, int x, int y)
{
    int line_count;
    int col_count;

    x += cub->map_ratio * x;
    y += cub->map_ratio * y;
    line_count = 0;
    while (line_count <= cub->map_ratio)
    {
        col_count = 0;
        while (col_count <= cub->map_ratio)
        {
			my_mlx_pixel_put(&cub->img, x + col_count + 30, y + line_count + 50, color);
			col_count++;
		}
		line_count++;
	}
}
