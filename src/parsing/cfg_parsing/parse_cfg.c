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

int	get_textures(char *dir, char *cfg, t_cub *cub)
{
	cfg++;
	while (ft_isspace(*cfg))
		cfg++;
	if (ft_strcmp(dir, "NO"))
		cub->parsing.no_path = ft_strdup(cfg);
	else if (ft_strcmp(dir, "SO"))
		cub->parsing.so_path = ft_strdup(cfg);
	else if (ft_strcmp(dir, "WE"))
		cub->parsing.we_path = ft_strdup(cfg);
	else if (ft_strcmp(dir, "EA"))
		cub->parsing.ea_path = ft_strdup(cfg);
}
