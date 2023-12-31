/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:37:31 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/24 12:53:53 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_if_of(long long number, int neg_mult, size_t nb_length)
{
	if (!number)
		return (0);
	if (nb_length >= 20)
	{
		if (neg_mult == 1)
			return (-1);
		else
			return (0);
	}
	if (neg_mult == 1)
	{
		if ((unsigned long long)number >= __LONG_LONG_MAX__)
			return (-1);
	}
	else
	{
		if ((unsigned long long)number - 1 >= __LONG_LONG_MAX__)
			return (0);
	}
	return (number * neg_mult);
}

int	ft_atoi(const char *nptr)
{
	long long		number;
	int				neg_mult;
	int				i;
	size_t			nb_length;

	i = 0;
	number = 0;
	neg_mult = 1;
	nb_length = 0;
	while (ft_isspace(nptr[i]) == 1)
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		i++;
		neg_mult = -1;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10 + nptr[i++] - '0';
		if (nptr[i - 1] != '0' || (nptr[i - 1] == '0' && number))
			nb_length++;
	}
	return (ft_check_if_of(number, neg_mult, nb_length));
}
