/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:44:57 by anrodri2          #+#    #+#             */
/*   Updated: 2023/10/24 14:55:54 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	custom_exit(t_cub *cub, int exit_code)
{
	ft_free_tab(cub->parsing.cfg);
	ft_free_tab(cub->parsing.file);
	ft_free_tab(cub->parsing.map);
	free(cub->parsing.no_path);
	free(cub->parsing.so_path);
	free(cub->parsing.we_path);
	free(cub->parsing.ea_path);
	exit(exit_code);
}
