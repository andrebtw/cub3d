/* 1449830 ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:51:26 by anrodri2          #+#    #+#             */
/*   Updated: 2023/10/04 05:48:45 by anrodri2         ###   ########.fr       */
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

int	file_exists_check(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(MSG_ERR_FILE_MAP_NOT_FOUND, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	parsing(t_cub *cub, int argc, char **argv)
{
	if (arg_checking(argc))
		return (EXIT_FAILURE);
	if (file_exists_check(argv))
		return (EXIT_FAILURE);
	cub->parsing->file_path = ft_strdup(argv[1]);
	if (parsing_file(cub))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
