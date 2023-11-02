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
	int wall_pos;
	int pxl_nmb;

	pxl_nmb = -1;
	projected_size = ceil(cub->ray.constant / wall_dist);
	wall_pos = (int) cub->ray.p_p_center.y - (projected_size / 2);
	printf("RAY NMB : %d\n", projected_size);
	while (++pxl_nmb < RES_HEIGHT)
	{
		printf("PXL NMB : %d || RAY NMB : %d\n", pxl_nmb, ray_nmb);
		if (pxl_nmb < wall_pos)
			my_mlx_pixel_put(&cub->img, pxl_nmb, ray_nmb, BLUE);
		else if (pxl_nmb >= wall_pos && pxl_nmb <= wall_pos - projected_size)
			my_mlx_pixel_put(&cub->img, pxl_nmb, ray_nmb, BROWN);
		else
			my_mlx_pixel_put(&cub->img, pxl_nmb, ray_nmb, GREEN);
	}
	return (0);
}

double	calc_wall_ditance(t_cub *cub, t_point inter, double ray)
{
	return (fabs(cub->player.x - inter.x) / cos(to_radians(ray)));
}
