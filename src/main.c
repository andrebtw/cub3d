/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:28:22 by anrodri2          #+#    #+#             */
/*   Updated: 2023/10/24 14:52:23 by anrodri2         ###   ########.fr       */
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
}

int	main(int argc, char **argv)
{
	int		ret_code;
	t_cub	cub;
	int		i;

	i = -1;
	ret_code = parsing(&cub, argc, argv);
	if (ret_code)
		return (ret_code);
	printf("%s\n", cub.parsing.no_path);
	printf("%s\n", cub.parsing.so_path);
	printf("%s\n", cub.parsing.we_path);
	printf("%s\n", cub.parsing.ea_path);
	while (++i < 3)
	{
		printf("F : %d\n", cub.parsing.floor_color_rgb[i]);
		printf("C : %d\n", cub.parsing.ceiling_color_rgb[i]);
	}
	custom_exit(&cub, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
