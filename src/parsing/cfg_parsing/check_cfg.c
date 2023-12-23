/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cfg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:03:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/10/18 18:03:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <errno.h>

int		check_cfg(t_cub *cub, char *str);
void	check_texture_files(t_cub *cub);
int		open_file(char *file);

int	parse_cfg(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->parsing.cfg[i])
	{
		if (check_cfg(cub, cub->parsing.cfg[i]) < 0)
		{
			ft_putstr_fd(MSG_ERR_WRONG_ID, 2);
			custom_exit(cub, EXIT_FAILURE);
		}
		i++;
	}
	check_texture_files(cub);
	return (0);
}

int	check_cfg(t_cub *cub, char *str)
{
	char	*dir;
	char	*cfg_dir;
	int		i;

	i = 0;
	cfg_dir = malloc(3 * sizeof(char));
	if (!cfg_dir)
		custom_exit(cub, K_ERR_MALLOC);
	dir = "NOSOWEEA";
	ft_strlcpy(cfg_dir, str, 3);
	while (dir[i + 1])
	{
		if (dir[i] == cfg_dir[0] && dir[i + 1] == cfg_dir[1])
			return (get_textures(cfg_dir, ++str, cub), free(cfg_dir), 0);
		i++;
	}
	if ((cfg_dir[0] == 'F' || cfg_dir[0] == 'C') && cfg_dir[1] == ' ')
		return (get_colors(cfg_dir, ++str, cub), free(cfg_dir), 0);
	return (-1);
}

void	check_texture_files(t_cub *cub)
{
	if (open_file(cub->parsing.no_path) || open_file(cub->parsing.so_path)
		|| open_file(cub->parsing.we_path) || open_file(cub->parsing.we_path))
		custom_exit(cub, EXIT_FAILURE);
}

int	open_file(char *file)
{
	int	fd;

	(void) file;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(MSG_ERR_TEXTURE_FILE, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
