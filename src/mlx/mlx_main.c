/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 < anrodri2@student.42lyon.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:02:55 by anrodri2          #+#    #+#             */
/*   Updated: 2023/10/25 18:30:19 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * 4);
	*(unsigned int*)dst = color;
}


int	mlx_create_window(t_cub *cub)
{
	t_img	img;

	cub->mlx.ptr = mlx_init();
	if (!cub->mlx.ptr)
	{
		ft_putstr_fd(MSG_ERR_WRONG_EXT, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	cub->mlx.win = mlx_new_window(cub->mlx.ptr, RES_WIDTH, RES_HEIGHT, WIN_TITLE);
	if (!cub->mlx.win)
	{
		ft_putstr_fd(MSG_ERR_CREATE_WIN, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	img.img = mlx_new_image(cub->mlx.ptr, RES_WIDTH, RES_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
    print_map(cub, &img);
    find_player(cub, &img);
	mlx_put_image_to_window(cub->mlx.ptr, cub->mlx.win, img.img, RES_WIDTH / 4, RES_HEIGHT / 4);
	return (EXIT_SUCCESS);
}

int	mlx_main(t_cub *cub)
{
	int	ret_value;

	ret_value = mlx_create_window(cub);
	if (ret_value)
		return (ret_value);
	mlx_loop(cub->mlx.ptr);
	return (EXIT_SUCCESS);
}
