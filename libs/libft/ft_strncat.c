/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:03:06 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/08 15:46:28 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	src_size;
	unsigned int	dest_size;

	src_size = 0;
	dest_size = 0;
	while (dest[dest_size] != '\0')
		dest_size++;
	while (src[src_size] != '\0' && nb > 0)
	{
		dest[dest_size] = src[src_size];
		dest_size++;
		src_size++;
		nb--;
	}
	dest[dest_size] = '\0';
	return (dest);
}
