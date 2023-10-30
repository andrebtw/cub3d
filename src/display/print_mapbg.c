/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mapbg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:45:18 by anrodri2          #+#    #+#             */
/*   Updated: 2023/10/30 19:09:07 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_mapbg(t_cub *cub)
{
	t_rect	rect;

	rect.x = 20;
	rect.y = 10;
	rect.width = MAP_WIDTH;
	rect.height = MAP_HEIGHT;
	rect.colour = MAP_COLOUR;
	rect.is_borderless = FALSE;
	print_rect(&(cub->img_mapbg), &rect);
}
