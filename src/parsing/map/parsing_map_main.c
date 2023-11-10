/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:57:06 by anrodri2          #+#    #+#             */
/*   Updated: 2023/10/24 16:24:07 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#define SPAWN_POS "NSEW"

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

int	empty_lines_check(t_cub *cub)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (cub->parsing.map[i])
	{
		while (cub->parsing.map[i])
		{
			if (cub->parsing.map[i][0] == '\n')
				i++;
			else
				break ;
		}
		j = 0;
		if (cub->parsing.map[i][j] == '\n')
		{
			ft_putstr_fd(MSG_ERR_EMPTY_LINE, STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	found_location_check(t_cub *cub, int *found_location, size_t i, size_t j)
{
	if (*found_location)
	{
		ft_putstr_fd(MSG_ERR_MULTIPLE_SPAWNS, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	*found_location = TRUE;
	if (cub->parsing.map[i][j] == 'N')
		cub->parsing.spawn_direction = K_N;
	if (cub->parsing.map[i][j] == 'S')
		cub->parsing.spawn_direction = K_S;
	if (cub->parsing.map[i][j] == 'E')
		cub->parsing.spawn_direction = K_E;
	if (cub->parsing.map[i][j] == 'W')
		cub->parsing.spawn_direction = K_W;
	cub->parsing.spawn_pos[0] = (int)i;
	cub->parsing.spawn_pos[1] = (int)j;
	return (EXIT_SUCCESS);
}

int	spawn_location_check(t_cub *cub)
{
	size_t	i;
	size_t	j;
	int		found_location;

	i = 0;
	found_location = FALSE;
	while (cub->parsing.map[i])
	{
		j = 0;
		while (cub->parsing.map[i][j])
		{
			if (ft_strchr(SPAWN_POS, cub->parsing.map[i][j]))
			{
				if (found_location_check(cub, &found_location, i, j))
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
	/*if (cub->parsing.map[0][0] != '\n')
	{
		ft_putstr_fd(MSG_ERR_NO_SEP_CFG_MAP, STDERR_FILENO);
		return (EXIT_FAILURE);
	}*/
	if (empty_lines_check(cub))
		return (EXIT_FAILURE);
	if (parsing_map_loop(cub))
		return (EXIT_FAILURE);
	if (spawn_location_check(cub))
		return (EXIT_FAILURE);
    map_max_len(cub);
	//check_diagonals(cub);
	return (EXIT_SUCCESS);
}
