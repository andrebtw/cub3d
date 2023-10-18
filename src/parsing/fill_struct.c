/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:22:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/10/18 17:22:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_map(t_cub *cub, int i);

void	get_cfg(t_cub *cub)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	cub->parsing.cfg = malloc(7 * sizeof(char **));
	while (cub->parsing.file[i] && count < 6)
	{
		if (cub->parsing.file[i][0] != '\n')
		{
			cub->parsing.cfg[count] = ft_strdup(cub->parsing.file[i]);
			count++;
		}
		i++;
	}
	cub->parsing.cfg[count++] = NULL;
	get_map(cub, i);
}

void	get_map(t_cub *cub, int	i)
{
	size_t		len;
	int			j;

	j = 0;
	len = 0;
	while (cub->parsing.file[len])
		len++;
	cub->parsing.map = malloc((len - i + 1) * sizeof(char **));
	while (cub->parsing.file[i])
	{
		cub->parsing.map[j] = ft_strdup(cub->parsing.file[i]);
		i++;
		j++;
	}
	cub->parsing.map[j] = NULL;
}
