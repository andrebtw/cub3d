/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isextension.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:05:04 by anrodri2          #+#    #+#             */
/*   Updated: 2023/10/18 12:19:06 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isextension(char *file, char *ext)
{
	long	file_size;
	long	ext_size;

	ext_size = ft_strlen(ext);
	file_size = ft_strlen(file);
	while (ext_size >= 0)
	{
		if (!file_size)
			return (0);
		if (ext[ext_size] != file[file_size])
			return (0);
		file_size--;
		ext_size--;
	}
	return (1);
}
