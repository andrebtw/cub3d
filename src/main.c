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
	//int		i = -1;

	ret_code = parsing(&cub, argc, argv);
	if (ret_code)
		return (ret_code);
	/*while (cub.parsing.cfg[++i])
		printf("%s", cub.parsing.cfg[i]);
	i = -1;
	while (cub.parsing.map[++i])
		printf("%s", cub.parsing.map[i]);*/
	return (EXIT_SUCCESS);
}
