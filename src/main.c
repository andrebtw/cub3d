/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:28:22 by anrodri2          #+#    #+#             */
/*   Updated: 2023/10/24 13:12:51 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
# include <stdio.h>

int	main(int argc, char **argv)
{
	int		ret_code;
	t_cub	cub;

	ret_code = parsing(&cub, argc, argv);
	if (ret_code)
		return (ret_code);
	return (EXIT_SUCCESS);
}
