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

int mlx_hooks(t_cub *cub)
{
    mlx_key_hook(cub->mlx.win,keypress, cub);
    return (0);
}

int keypress(int keycode, t_cub *cub)
{
    printf("KEY : %d\n", keycode);
    if (keycode == ESC)
        custom_exit(cub, 0);
    return (0);
}