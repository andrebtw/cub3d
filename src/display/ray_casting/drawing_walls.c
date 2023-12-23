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

char	*get_texture_pxl(t_displayed_col dis_col, int raw);
int		draw_ceiling_floor(t_cub *cub, int ray_nmb, \
		int pxl_nmb, int projected_size);

int	draw_walls(t_cub *cub, double wall_dist, int ray_nmb, \
				t_displayed_col *displayed_col)
{
	int		projected_size;
	int		pxl_nmb;
	int		texture_pxl;
	char	*pxl;

	pxl_nmb = -1;
	projected_size = floor(cub->ray.constant / wall_dist);
	texture_pxl = 0;
	if ((int) cub->ray.p_p_center.y - (projected_size / 2) < 0)
		texture_pxl = -((int) cub->ray.p_p_center.y - (projected_size / 2));
	while (++pxl_nmb < RES_HEIGHT)
	{
		if (draw_ceiling_floor(cub, ray_nmb, pxl_nmb, projected_size))
		{
			pxl = get_texture_pxl(*displayed_col, \
			texture_pxl / (projected_size / WALLS_SIZE));
			my_mlx_pixel_put(&cub->img, ray_nmb, pxl_nmb, *(unsigned int *)pxl);
			texture_pxl++;
		}
	}
	return (0);
}

double	calc_wall_distance(t_cub *cub, t_point inter)
{
	return (sqrt(pow(cub->player.x - inter.x, 2) \
	+ pow(cub->player.y - inter.y, 2)));
}

void	textures_to_img(t_cub *cub)
{
	cub->no.img.img = mlx_xpm_file_to_image(cub->mlx.ptr, cub->parsing.no_path, \
	&cub->no.width, &cub->no.height);
	cub->so.img.img = mlx_xpm_file_to_image(cub->mlx.ptr, cub->parsing.so_path, \
	&cub->so.width, &cub->so.height);
	cub->ea.img.img = mlx_xpm_file_to_image(cub->mlx.ptr, cub->parsing.ea_path, \
	&cub->ea.width, &cub->ea.height);
	cub->we.img.img = mlx_xpm_file_to_image(cub->mlx.ptr, cub->parsing.we_path, \
	&cub->we.width, &cub->we.height);
	cub->no.img.addr = mlx_get_data_addr(cub->no.img.img, \
	&cub->no.img.bits_per_pixel, &cub->no.img.line_length, &cub->no.img.endian);
	cub->so.img.addr = mlx_get_data_addr(cub->so.img.img, \
	&cub->so.img.bits_per_pixel, &cub->so.img.line_length, &cub->so.img.endian);
	cub->ea.img.addr = mlx_get_data_addr(cub->ea.img.img, \
	&cub->ea.img.bits_per_pixel, &cub->ea.img.line_length, &cub->ea.img.endian);
	cub->we.img.addr = mlx_get_data_addr(cub->we.img.img, \
	&cub->we.img.bits_per_pixel, &cub->we.img.line_length, &cub->we.img.endian);
}

char	*get_texture_pxl(t_displayed_col dis_col, int raw)
{
	char	*pix;

	if (dis_col.x < 0)
		pix = get_mlx_pxl(&dis_col.texture->img, dis_col.y, raw);
	else
		pix = get_mlx_pxl(&dis_col.texture->img, dis_col.x, raw);
	return (pix);
}

int	draw_ceiling_floor(t_cub *cub, int ray_nmb, int pxl_nmb, int projected_size)
{
	int	floor_color;
	int	ceiling_color;
	int	wall_pos_up;

	wall_pos_up = (int) cub->ray.p_p_center.y - (projected_size / 2);
	floor_color = create_trgb(255, cub->parsing.floor_color_rgb[0], \
	cub->parsing.floor_color_rgb[1], cub->parsing.floor_color_rgb[2]);
	ceiling_color = create_trgb(255, cub->parsing.ceiling_color_rgb[0], \
	cub->parsing.ceiling_color_rgb[1], cub->parsing.ceiling_color_rgb[2]);
	if (pxl_nmb < wall_pos_up)
		my_mlx_pixel_put(&cub->img, ray_nmb, pxl_nmb, ceiling_color);
	else if (pxl_nmb > wall_pos_up + projected_size)
		my_mlx_pixel_put(&cub->img, ray_nmb, pxl_nmb, floor_color);
	else
		return (1);
	return (0);
}
