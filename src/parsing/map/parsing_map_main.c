/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:57:06 by anrodri2          #+#    #+#             */
/*   Updated: 2023/10/18 15:57:28 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	illegal_chars_check(t_cub *cub)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (cub->parsing.map[i])
	{
		j = 0;
		while (cub->parsing.map[i][j])
		{
			if (!ft_strchr(POSSIBLE_CHARS, cub->parsing.map[i][j]))
			{
				ft_putstr_fd(MSG_ERR_ILLEGAL_CHARS_MAP, STDERR_FILENO);
				return (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	parsing_map(t_cub *cub)
{
	if (illegal_chars_check(cub))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
