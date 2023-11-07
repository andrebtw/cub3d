/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:35:51 by mthibaul          #+#    #+#             */
/*   Updated: 2023/10/29 13:35:51 by mthibaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int keypress(int keycode, t_cub *cub);
int	close_window(int keycode, t_cub *cub);

int mlx_hooks(t_cub *cub)
{
    mlx_hook(cub->mlx.win, KEYPRESS, 1L>>0, keypress, cub);
	mlx_hook(cub->mlx.win, DESTROY_WINDOW, 1L<<5, close_window, cub);
    return (0);
}

int	close_window(int keycode, t_cub *cub)
{
	(void)keycode;
    mlx_destroy_window(cub->mlx.ptr, cub->mlx.win);
    mlx_destroy_display(cub->mlx.ptr);
    free(cub->mlx.ptr);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int keypress(int keycode, t_cub *cub)
{
    printf("KEY : %d\n", keycode);
	if (keycode == ESC)
        custom_exit(cub, 0);
	if (keycode == W)
		cub->player.vertical = -1;
	if (keycode == A)
		cub->player.horizontal = -1;
	if (keycode == S)
		cub->player.vertical = 1;
	if (keycode == D)
		cub->player.horizontal = 1;
    return (0);
}