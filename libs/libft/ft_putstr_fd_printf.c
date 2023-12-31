/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:23:49 by anrodri2          #+#    #+#             */
/*   Updated: 2023/03/02 03:48:55 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd_p(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (write(fd, &s[i], 1) == -1)
			return (-1);
		i++;
	}
	return (0);
}
