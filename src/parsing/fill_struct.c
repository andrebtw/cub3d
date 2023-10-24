/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:22:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/10/24 16:23:41 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_map(t_cub *cub, int i);

int	get_cfg(t_cub *cub)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	cub->parsing.cfg = malloc(7 * sizeof(char **));
	if (!cub->parsing.cfg)
		return (ft_free_tab(cub->parsing.file), K_ERR_MALLOC);
	while (cub->parsing.file[i] && count < 6)
	{
		if (cub->parsing.file[i][0] != '\n')
		{
			cub->parsing.cfg[count] = ft_strdup(cub->parsing.file[i]);
			if (!cub->parsing.cfg[count])
				return (ft_free_tab(cub->parsing.cfg), ft_free_tab(\
				cub->parsing.file), K_ERR_MALLOC);
			count++;
		}
		i++;
	}
	cub->parsing.cfg[count++] = NULL;
	if (get_map(cub, i))
		return (K_ERR_MALLOC);
	return (EXIT_SUCCESS);
}

int	get_map(t_cub *cub, int i)
{
	size_t		len;
	int			j;

	j = 0;
	len = 0;
	while (cub->parsing.file[len])
		len++;
	cub->parsing.map = malloc((len - i + 1) * sizeof(char **));
	if (!cub->parsing.map)
		return (ft_free_tab(cub->parsing.cfg), ft_free_tab(\
		cub->parsing.file), K_ERR_MALLOC);
	while (cub->parsing.file[i])
	{
		cub->parsing.map[j] = ft_strdup(cub->parsing.file[i]);
		if (!cub->parsing.map[j])
			return (ft_free_tab(cub->parsing.cfg), ft_free_tab(\
			cub->parsing.map), ft_free_tab(cub->parsing.file), K_ERR_MALLOC);
		i++;
		j++;
	}
	cub->parsing.map[j] = NULL;
	return (EXIT_SUCCESS);
}
