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
	int wall_pos_down;
	int pxl_nmb;

	pxl_nmb = -1;
	projected_size = ceil(cub->ray.constant / wall_dist);
	wall_pos_up = (int) cub->ray.p_p_center.y - (projected_size / 2);
	wall_pos_down =(int) cub->ray.p_p_center.y + (projected_size / 2);
	printf("RAY NMB : %d\n", wall_pos_up);
	while (++pxl_nmb < RES_HEIGHT)
	{
		//printf("PXL NMB : %d || RAY NMB : %d\n", pxl_nmb, ray_nmb);
		//printf("WALL POS : %d\n", wall_pos);
		if (pxl_nmb < wall_pos_up)
			my_mlx_pixel_put(&cub->img, ray_nmb, pxl_nmb, BLUE);
		else if (pxl_nmb > wall_pos_down)
			my_mlx_pixel_put(&cub->img, ray_nmb, pxl_nmb, GREEN);
		else
			my_mlx_pixel_put(&cub->img, ray_nmb, pxl_nmb, BROWN);
	}
	return (0);
}

double	calc_wall_ditance(t_cub *cub, t_point inter, double ray)
{
	return (fabs(cub->player.x - inter.x) / cos(to_radians(ray)));
}
