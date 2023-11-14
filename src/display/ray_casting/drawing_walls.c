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

int	draw_walls(t_cub *cub, double wall_dist, int ray_nmb, int side)
{
	int projected_size;
	int wall_pos_up;
	int wall_pos_down;
	int pxl_nmb;

	(void) side;
	pxl_nmb = -1;
	projected_size = ceil(cub->ray.constant / wall_dist);
	wall_pos_up = (int) cub->ray.p_p_center.y - (projected_size / 2);
	wall_pos_down = (int) cub->ray.p_p_center.y + (projected_size / 2);
    //printf("Ray nmb : %d\n", ray_nmb);
	while (++pxl_nmb < RES_HEIGHT)
	{
		//printf("PXL NMB : %d || RAY NMB : %d\n", pxl_nmb, ray_nmb);
		//printf("WALL POS : %d\n", wall_pos);
		if (pxl_nmb < wall_pos_up)
			my_mlx_pixel_put(&cub->img,  ray_nmb, pxl_nmb, create_trgb(255, cub->parsing.ceiling_color_rgb[0],  cub->parsing.ceiling_color_rgb[1], cub->parsing.ceiling_color_rgb[2]));
		else if (pxl_nmb > wall_pos_down)
			my_mlx_pixel_put(&cub->img, ray_nmb, pxl_nmb, create_trgb(255, cub->parsing.floor_color_rgb[0],  cub->parsing.floor_color_rgb[1], cub->parsing.floor_color_rgb[2]));
		else
			*(unsigned int*)get_mlx_pxl(&cub->img, ray_nmb, pxl_nmb) = *(unsigned int*)get_mlx_pxl(cub->ea.img.img, (ray_nmb % 64), (pxl_nmb % 64));
	}
	return (0);
}

double	calc_wall_distance(t_cub *cub, t_point inter)
{
	return (sqrt(pow(cub->player.x - inter.x, 2) + pow(cub->player.y - inter.y, 2)));
}

void    textures_to_img(t_cub *cub)
{
    cub->no.mlx = mlx_init();
    cub->so.mlx = mlx_init();
    cub->ea.mlx = mlx_init();
    cub->we.mlx = mlx_init();
    cub->no.img.img = mlx_xpm_file_to_image(cub->no.mlx, cub->parsing.no_path, &cub->no.width, &cub->no.height);
    cub->so.img.img = mlx_xpm_file_to_image(cub->so.mlx, cub->parsing.so_path, &cub->so.width, &cub->so.height);
    cub->ea.img.img = mlx_xpm_file_to_image(cub->ea.mlx, cub->parsing.ea_path, &cub->ea.width, &cub->ea.height);
    cub->we.img.img = mlx_xpm_file_to_image(cub->we.mlx, cub->parsing.we_path, &cub->we.width, &cub->we.height);
	cub->no.img.addr = mlx_get_data_addr(cub->no.img.img, &cub->no.img.bits_per_pixel, &cub->no.img.line_length, &cub->no.img.endian);
	cub->so.img.addr = mlx_get_data_addr(cub->so.img.img, &cub->so.img.bits_per_pixel, &cub->so.img.line_length, &cub->so.img.endian);
	cub->ea.img.addr = mlx_get_data_addr(cub->ea.img.img, &cub->ea.img.bits_per_pixel, &cub->ea.img.line_length, &cub->ea.img.endian);
	cub->we.img.addr = mlx_get_data_addr(cub->we.img.img, &cub->we.img.bits_per_pixel, &cub->we.img.line_length, &cub->we.img.endian);
}