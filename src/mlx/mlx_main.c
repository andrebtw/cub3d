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
