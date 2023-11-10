/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_diagonals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:09:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/11/10 14:09:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_diagonals(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	while (cub->parsing.map[i])
	{
		j = 0;
		while (cub->parsing.map[i][j])
		{
			if (cub->parsing.map[i][j] == '0' && cub->parsing.map[i - 1][j - 1] == ' ')
				cub->parsing.map[i - 1][j - 1] = '1';
			else if (cub->parsing.map[i][j] == '0' && cub->parsing.map[i - 1][j + 1] == ' ')
				cub->parsing.map[i - 1][j + 1] = '1';
			else if (cub->parsing.map[i][j] == '0' && cub->parsing.map[i + 1][j - 1] == ' ')
				cub->parsing.map[i + 1][j - 1] = '1';
			else if (cub->parsing.map[i][j] == '0' && cub->parsing.map[i + 1][j + 1] == ' ')
				cub->parsing.map[i + 1][j + 1] = '1';
			j++;
		}
		i++;
	}
}
