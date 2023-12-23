/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 < anrodri2@student.42lyon.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:44:57 by anrodri2          #+#    #+#             */
/*   Updated: 2023/12/13 19:57:06 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_textures(t_cub *cub);

void	custom_exit(t_cub *cub, int exit_code)
{
	ft_free_tab(cub->parsing.cfg);
	ft_free_tab(cub->parsing.file);
	ft_free_tab(cub->parsing.map);
	if (cub->parsing.no_path)
		free_textures(cub);
	if (cub->mlx.ptr)
	{
		mlx_destroy_image(cub->mlx.ptr, cub->img.img);
		mlx_destroy_window(cub->mlx.ptr, cub->mlx.win);
		mlx_destroy_display(cub->mlx.ptr);
		free(cub->mlx.ptr);
	}
	exit(exit_code);
}

void	free_textures(t_cub *cub)
{
	free(cub->parsing.no_path);
	free(cub->parsing.so_path);
	free(cub->parsing.we_path);
	free(cub->parsing.ea_path);
	if (cub->mlx.ptr)
	{
		mlx_destroy_image(cub->mlx.ptr, cub->no.img.img);
		mlx_destroy_image(cub->mlx.ptr, cub->so.img.img);
		mlx_destroy_image(cub->mlx.ptr, cub->we.img.img);
		mlx_destroy_image(cub->mlx.ptr, cub->ea.img.img);
	}
}
