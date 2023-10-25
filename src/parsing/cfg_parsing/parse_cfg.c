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

int	ft_isnmb(char *str);

void	get_textures_sides(char *dir, char *cfg, t_cub *cub)
{
	if (!ft_strcmp(dir, "WE"))
	{
		cub->parsing.we_path = ft_strdup(cfg);
		if (!cub->parsing.we_path)
			custom_exit(cub, K_ERR_MALLOC);
	}
	else if (!ft_strcmp(dir, "EA"))
	{
		cub->parsing.ea_path = ft_strdup(cfg);
		if (!cub->parsing.ea_path)
			custom_exit(cub, K_ERR_MALLOC);
	}
}

void	get_textures(char *dir, char *cfg, t_cub *cub)
{
	cfg++;
	cfg[ft_strlen(cfg) - 1] = '\0';
	while (ft_isspace(*cfg))
		cfg++;
	if (!ft_strcmp(dir, "NO"))
	{
		cub->parsing.no_path = ft_strdup(cfg);
		if (!cub->parsing.no_path)
			custom_exit(cub, K_ERR_MALLOC);
	}
	else if (!ft_strcmp(dir, "SO"))
	{
		cub->parsing.so_path = ft_strdup(cfg);
		if (!cub->parsing.so_path)
			custom_exit(cub, K_ERR_MALLOC);
	}
	get_textures_sides(dir, cfg, cub);
}

int	get_colors(char *side, char *cfg, t_cub *cub)
{
	char	**splited_colors;
	int 	nmb;
	int		i;

	i = -1;
	while (ft_isspace(*cfg))
		cfg++;
	splited_colors = ft_split(cfg, ',');
	if (!splited_colors)
		custom_exit(cub, K_ERR_MALLOC);
	while (++i < 3)
	{
		nmb = ft_atoi(splited_colors[i]);
		if (!ft_isnmb(splited_colors[i]) || nmb > 255 || nmb < 0)
		{
			ft_putstr_fd(MSG_ERR_COLOUR, 2);
			ft_free_tab(splited_colors);
			custom_exit(cub, EXIT_FAILURE);
		}
		if (!ft_strncmp(side, "F", 1))
			cub->parsing.floor_color_rgb[i] = nmb;
		else if (!ft_strncmp(side, "C", 1))
			cub->parsing.ceiling_color_rgb[i] = nmb;
	}
	ft_free_tab(splited_colors);
	return (0);
}

int	ft_isnmb(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}
