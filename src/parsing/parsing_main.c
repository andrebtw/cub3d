/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:07:20 by anrodri2          #+#    #+#             */
/*   Updated: 2023/10/24 16:11:56 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	arg_checking(int argc)
{
	if (argc == 1)
	{
		ft_putstr_fd(MSG_ERR_1_ARG, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (argc > 2)
	{
		ft_putstr_fd(MSG_ERR_MULTIPLE_ARGS, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	file_exists_check(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(MSG_ERR_FILE_MAP_NOT_FOUND, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	cub_file_check(char **argv)
{
	if (!ft_isextension(argv[1], ".cub"))
	{
		ft_putstr_fd(MSG_ERR_WRONG_EXT, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	parsing(t_cub *cub, int argc, char **argv)
{
	if (arg_checking(argc))
		return (EXIT_FAILURE);
	if (cub_file_check(argv))
		return (EXIT_FAILURE);
	if (file_exists_check(argv[1]))
		return (EXIT_FAILURE);
	cub->parsing.file_path = argv[1];
	if (parsing_file(cub))
		return (EXIT_FAILURE);
	if (get_cfg(cub))
	{
		ft_putstr_fd(MSG_ERR_MALLOC, STDERR_FILENO);
		return (K_ERR_MALLOC);
	}
	if (parsing_map(cub))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
