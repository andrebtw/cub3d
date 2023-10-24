/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:28:22 by anrodri2          #+#    #+#             */
/*   Updated: 2023/09/28 16:18:16 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	int		ret_code;
	t_cub	cub;
	int		i = -1;

	ret_code = parsing(&cub, argc, argv);
	if (ret_code)
		return (ret_code);
	printf("%s", cub.parsing.no_path);
	printf("%s", cub.parsing.so_path);
	printf("%s", cub.parsing.we_path);
	printf("%s", cub.parsing.ea_path);
	while (++i < 3)
	{
		printf("F : %d\n", cub.parsing.floor_color_rgb[i]);
		printf("C : %d\n", cub.parsing.ceiling_color_rgb[i]);
	}
	return (EXIT_SUCCESS);
}
