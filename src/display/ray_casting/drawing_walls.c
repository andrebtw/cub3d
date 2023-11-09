/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:05:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/11/02 13:05:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	draw_walls(t_cub *cub, double wall_dist, int ray_nmb)
{
	int projected_size;
	int wall_pos_up;
	//int wall_pos_down;
	int pxl_nmb;

	pxl_nmb = -1;
	projected_size = ceil(cub->ray.constant / wall_dist);
	wall_pos_up = (int) cub->ray.p_p_center.y - (projected_size / 2);
	//wall_pos_down = (int) cub->ray.p_p_center.y + (projected_size / 2);
    //printf("Wall dist : %f\n", wall_dist);
	while (++pxl_nmb < RES_HEIGHT)
	{
		//printf("PXL NMB : %d || RAY NMB : %d\n", pxl_nmb, ray_nmb);
		//printf("WALL POS : %d\n", wall_pos);
		if (pxl_nmb < wall_pos_up)
			my_mlx_pixel_put(&cub->img,  ray_nmb, pxl_nmb, create_trgb(255, cub->parsing.ceiling_color_rgb[0],  cub->parsing.ceiling_color_rgb[1], cub->parsing.ceiling_color_rgb[2]));
		else if (pxl_nmb > wall_pos_down)
			my_mlx_pixel_put(&cub->img, ray_nmb, pxl_nmb, create_trgb(255, cub->parsing.floor_color_rgb[0],  cub->parsing.floor_color_rgb[1], cub->parsing.floor_color_rgb[2]));
		else if ()
			my_mlx_pixel_put(&cub->img, ray_nmb, pxl_nmb, BROWN);
	}
	return (0);
}

double	calc_wall_distance(t_cub *cub, t_point inter, double ray_angle)
{
	(void) ray_angle;
	return (sqrt(pow(cub->player.x - inter.x, 2) + pow(cub->player.y - inter.y, 2)));
	//return (fabs(cub->player.y - inter.y) / cos(ray_angle));
}
