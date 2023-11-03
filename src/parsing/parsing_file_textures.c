/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:54:27 by anrodri2          #+#    #+#             */
/*   Updated: 2023/10/07 14:22:33 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	find_texture(t_cub *cub, char *direction)
{
	// size_t	i;
	// size_t	j;

	// i = 0;
	// while (cub->parsing.file[i])
	// {
	// 	j = 0;
	// 	while (!ft_strchr(" \t", cub->parsing.file[j]))
	// 		j++;
	// 	if (cub->parsing.file[j] == direction[\
	// 	0] && cub->parsing.file[j + 1] == direction[1])
			
	// 	i++;
	// }
	return (EXIT_SUCCESS);
}

int	parsing_textures(t_cub *cub)
{
	find_texture(cub, "NO");
	find_texture(cub, "SO");
	find_texture(cub, "WE");
	find_texture(cub, "EA");
	return (EXIT_SUCCESS);
}
