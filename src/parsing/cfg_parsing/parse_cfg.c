/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cfg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:51:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/10/18 18:51:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*get_textures(char *dir, char *cfg, t_cub *cub)
{
	cfg++;
	while (ft_isspace(*cfg))
		cfg++;
	if (!ft_strcmp(dir, "NO"))
		return (cub->parsing->no_path = ft_strdup(cfg));
	else if (!ft_strcmp(dir, "SO"))
		return (cub->parsing->so_path = ft_strdup(cfg));
	else if (!ft_strcmp(dir, "WE"))
		return (cub->parsing->we_path = ft_strdup(cfg));
	else if (!ft_strcmp(dir, "EA"))
		return (cub->parsing->ea_path = ft_strdup(cfg));
	return (NULL);
}

int	get_colors(char *side, char *cfg, t_cub *cub)
{
	char	**splited_colors;
	int		i;

	i = -1;
	while (ft_isspace(*cfg))
		cfg++;
	splited_colors = ft_split(cfg, ',');
	if (!ft_strncmp(side, "F", 1))
	{
		while (++i < 3)
			cub->parsing->floor_color_rgb[i] = ft_atoi(splited_colors[i]);
	}
	else if (!ft_strncmp(side, "C", 1))
	{
		while (++i < 3)
			cub->parsing->ceiling_color_rgb[i] = ft_atoi(splited_colors[i]);
	}
	i = -1;
	while (++i < 3)
		free(splited_colors[i]);
	return (free(splited_colors), 0);
}
