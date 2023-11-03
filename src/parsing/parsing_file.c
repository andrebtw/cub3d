/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:23:43 by anrodri2          #+#    #+#             */
/*   Updated: 2023/10/24 16:06:16 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

size_t	map_malloc_size(t_cub *cub)
{
	char	*tmp_str;
	size_t	counter;
	int		fd_line_counter;

	fd_line_counter = open(cub->parsing.file_path, O_RDONLY);
	if (fd_line_counter == -1)
	{
		ft_putstr_fd(MSG_ERR_FILE_ACCESS, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	counter = 0;
	tmp_str = (char *) malloc (1);
	if (!tmp_str)
	{
		ft_putstr_fd(MSG_ERR_MALLOC, STDERR_FILENO);
		exit(K_ERR_MALLOC);
	}
	while (tmp_str)
	{
		free(tmp_str);
		tmp_str = get_next_line(fd_line_counter);
		counter++;
	}
	close(fd_line_counter);
	return ((counter * sizeof(char **)) + 8);
}

int	write_map_file_loop(t_cub *cub, int fd)
{
	char	*tmp_str;
	size_t	i;

	i = 0;
	tmp_str = (char *) malloc (sizeof(char));
	if (!tmp_str)
	{
		ft_putstr_fd(MSG_ERR_MALLOC, STDERR_FILENO);
		return (close(fd), free(cub->parsing.file), K_ERR_MALLOC);
	}
	while (tmp_str)
	{
		free(tmp_str);
		tmp_str = get_next_line(fd);
		if (!tmp_str)
			break ;
		cub->parsing.file[i] = ft_strdup(tmp_str);
		if (!cub->parsing.file[i])
			return (close(fd), ft_free_tab(\
			cub->parsing.file), free(tmp_str), K_ERR_MALLOC);
		i++;
	}
	cub->parsing.file[i] = NULL;
	return (close(fd), EXIT_SUCCESS);
}

int	write_map_file(t_cub *cub)
{
	int		fd;
	int		return_code;

	fd = open(cub->parsing.file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(MSG_ERR_FILE_ACCESS, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return_code = write_map_file_loop(cub, fd);
	if (return_code)
		return (return_code);
	return (EXIT_SUCCESS);
}

int	parsing_file(t_cub *cub)
{
	int	return_code;

	cub->parsing.file = (char **) malloc (map_malloc_size(cub));
	if (!cub->parsing.file)
	{
		ft_putstr_fd(MSG_ERR_MALLOC, STDERR_FILENO);
		custom_exit(cub, K_ERR_MALLOC);
	}
	return_code = write_map_file(cub);
	if (return_code)
		return (exit(return_code), EXIT_FAILURE);
	get_cfg(cub);
	parse_cfg(cub);
	return (EXIT_SUCCESS);
}

void    map_max_len(t_cub *cub)
{
    int x;
    int tmp;
    int y;

    y = -1;
    x = 0;
    while (cub->parsing.map[++y])
    {
        tmp = 0;
        while (cub->parsing.map[y][tmp])
            tmp++;
        if (x < tmp)
            x = tmp;
    }
    cub->parsing.map_max_x = x;
    cub->parsing.map_max_y = y;
}
