/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:27:58 by mthibaul          #+#    #+#             */
/*   Updated: 2023/10/28 16:28:36 by mthibaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    print_pixel(t_img *img, int color, int x, int y);

void print_map(t_cub *cub, t_img *img)
{
    int i;
    int j;

    i = -1;
    while (cub->parsing.map[++i])
    {
        printf("%s\n", cub->parsing.map[i]);
        j = -1;
        while (cub->parsing.map[i][++j])
        {
            if (cub->parsing.map[i][j] == '1')
                print_pixel(img, BROWN, j, i);
            else if (cub->parsing.map[i][j] == '0')
                print_pixel(img, WHITE, j, i);
            else
                print_pixel(img, BLACK, j, i);
        }
    }
}

void    print_pixel(t_img *img, int color, int x, int y)
{
    int line_count;
    int col_count;

    if (x != 0)
        x += (20 * x);
    if (y != 0)
        y += (20 * y);
    line_count = 0;
    while (line_count < 21)
    {
        col_count = 0;
        while (col_count < 21)
        {
            my_mlx_pixel_put(img, x + col_count, y + line_count, color);
            col_count++;
        }
        col_count = 0;
        line_count++;
    }
}