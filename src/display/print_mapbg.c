/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mapbg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:45:18 by anrodri2          #+#    #+#             */
/*   Updated: 2023/11/03 17:20:01 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_mapbg(t_cub *cub)
{
	t_rect	rect;

	rect.x = 2;
	rect.y = 2;
	rect.width = MAP_WIDTH / 2;
	rect.height = MAP_HEIGHT / 2;
	rect.colour = MAP_COLOUR;
	rect.border_color = 0xFFFFFF;
	rect.is_borderless = FALSE;
	print_rect(&(cub->img), &rect);
}
