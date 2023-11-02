/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_cast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:49:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/10/31 11:49:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_ray_cast(t_cub *cub)
{
	cub->ray.p_p_dist = (RES_WIDTH / 2.0) / tan(to_radians(FOV) / 2);
	cub->ray.angle_btw_ray = 60.0 / RES_WIDTH;
	cub->ray.constant = WALLS_SIZE * cub->ray.p_p_dist;
	cub->ray.p_p_center.x = RES_WIDTH / 2.0;
	cub->ray.p_p_center.y = RES_HEIGHT / 2.0;
}
