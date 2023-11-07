/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:02:55 by anrodri2          #+#    #+#             */
/*   Updated: 2023/11/03 17:44:41 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	update_map(t_cub *cub);

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * 4);
	*(unsigned int*)dst = color;
}

int	mlx_create_window(t_cub *cub)
{
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
	cub->img.img = mlx_new_image(cub->mlx.ptr, RES_WIDTH, RES_HEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel, &cub->img.line_length,
								 &cub->img.endian);
    print_mapbg(cub);
	print_map(cub);
    find_player(cub);
	ray_casting_main(cub);
	mlx_put_image_to_window(cub->mlx.ptr, cub->mlx.win, cub->img.img, 0, 0);
	return (EXIT_SUCCESS);
}

int	mlx_main(t_cub *cub)
{
	int	ret_value;

	ret_value = mlx_create_window(cub);
	if (ret_value)
		return (ret_value);
    mlx_hooks(cub);
	mlx_loop_hook(cub->mlx.ptr, move_player_3D, cub);
	mlx_loop(cub->mlx.ptr);
	return (EXIT_SUCCESS);
}

int	update_map(t_cub *cub)
{
	print_map(cub);
	move_player(cub);
	mlx_put_image_to_window(cub->mlx.ptr, cub->mlx.win, cub->img.img, RES_WIDTH / 4, RES_HEIGHT / 4);
	return (0);
}
