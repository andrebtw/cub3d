/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 < anrodri2@student.42lyon.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:28:22 by anrodri2          #+#    #+#             */
/*   Updated: 2023/12/13 21:45:41 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	values_init(t_cub *cub)
{
	cub->parsing.file_path = NULL;
	cub->parsing.no_path = NULL;
	cub->parsing.so_path = NULL;
	cub->parsing.we_path = NULL;
	cub->parsing.ea_path = NULL;
	cub->parsing.map = NULL;
	cub->parsing.cfg = NULL;
	cub->parsing.file = NULL;
	cub->player.rotating = 0;
	cub->player.forwards = FALSE;
	cub->player.backwards = FALSE;
	cub->player.left = FALSE;
	cub->player.right = FALSE;
	cub->player.rotating_left = FALSE;
	cub->player.rotating_right = FALSE;
	cub->player.sprint = FALSE;
	cub->is_colision = FALSE;
}

int	main(int argc, char **argv)
{
	int		ret_code;
	t_cub	cub;

	values_init(&cub);
	ret_code = parsing(&cub, argc, argv);
	if (ret_code)
		return (ret_code);
	ret_code = mlx_main(&cub);
	if (ret_code)
		return (ret_code);
	custom_exit(&cub, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
