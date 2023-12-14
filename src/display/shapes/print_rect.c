/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:08:03 by anrodri2          #+#    #+#             */
/*   Updated: 2023/11/03 17:07:16 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_border(t_img *img, t_rect *rect)
{
	size_t	counter_width;
	size_t	counter_height;

	counter_width = 0;
	counter_height = 0;
	while (counter_width < (size_t)rect->width)
	{
		counter_height = 0;
		while (counter_height < (size_t)rect->height)
		{
			if (!counter_height || !(counter_height + 1 < (size_t)rect->height))
				my_mlx_pixel_put(img, rect->x + (int)counter_width, \
				rect->y + (int)counter_height, rect->border_color);
			if (!counter_width || !(counter_width + 1 < (size_t)rect->width))
				my_mlx_pixel_put(img, rect->x + (int)counter_width, \
				rect->y + (int)counter_height, rect->border_color);
			counter_height++;
		}
		counter_width++;
	}
}

void	print_rect(t_img *img, t_rect *rect)
{
	size_t	counter_width;
	size_t	counter_height;

	counter_width = 0;
	counter_height = 0;
	while (counter_width < (size_t)rect->width)
	{
		counter_height = 0;
		while (counter_height < (size_t)rect->height)
		{
			my_mlx_pixel_put(img, rect->x + (int)counter_width, \
			rect->y + (int)counter_height, rect->colour);
			counter_height++;
		}
		counter_width++;
	}
	if (rect->is_borderless)
		return ;
	print_border(img, rect);
}
