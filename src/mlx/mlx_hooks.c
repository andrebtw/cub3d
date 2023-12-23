/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 < anrodri2@student.42lyon.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:35:51 by mthibaul          #+#    #+#             */
/*   Updated: 2023/12/14 21:43:11 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	keypress(int keycode, t_cub *cub);
int	close_window(int keycode, t_cub *cub);
int	keyrelease(int keycode, t_cub *cub);

int	mlx_hooks(t_cub *cub)
{
	mlx_hook(cub->mlx.win, KEYPRESS, 1L >> 0, keypress, cub);
	mlx_hook(cub->mlx.win, DESTROY_WINDOW, 1L << 5, close_window, cub);
	mlx_key_hook(cub->mlx.win, keyrelease, cub);
	return (EXIT_SUCCESS);
}

int	close_window(int keycode, t_cub *cub)
{
	(void)keycode;
	(void)cub;
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	keyrelease(int keycode, t_cub *cub)
{
	if (keycode == W)
		cub->player.forwards = FALSE;
	if (keycode == A)
		cub->player.left = FALSE;
	if (keycode == S)
		cub->player.backwards = FALSE;
	if (keycode == D)
		cub->player.right = FALSE;
	if (keycode == LEFT)
		cub->player.rotating_left = FALSE;
	if (keycode == RIGHT)
		cub->player.rotating_right = FALSE;
	if (keycode == SHIFT)
		cub->player.sprint = 0;
	return (EXIT_SUCCESS);
}

int	keypress(int keycode, t_cub *cub)
{
	if (keycode == ESC)
		custom_exit(cub, 0);
	if (keycode == SHIFT)
		cub->player.sprint = SPRINT_SPEED;
	if (keycode == W)
		cub->player.forwards = TRUE;
	if (keycode == A)
		cub->player.left = TRUE;
	if (keycode == S)
		cub->player.backwards = TRUE;
	if (keycode == D)
		cub->player.right = TRUE;
	if (keycode == LEFT)
		cub->player.rotating_left = TRUE;
	if (keycode == RIGHT)
		cub->player.rotating_right = TRUE;
	return (EXIT_SUCCESS);
}
