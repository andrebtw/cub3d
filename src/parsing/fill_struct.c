/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:22:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/10/24 16:23:41 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		tablen(char **tab);
void	check_arg_nmb_by_line(t_cub *cub);

void	get_cfg(t_cub *cub)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	cub->parsing.cfg = (char **) malloc(7 * sizeof(char **));
	if (!cub->parsing.cfg)
		custom_exit(cub, K_ERR_MALLOC);
	while (cub->parsing.file[i] && count < 6)
	{
		if (cub->parsing.file[i][0] != '\n')
		{
			cub->parsing.cfg[count] = ft_strdup(cub->parsing.file[i]);
			if (!cub->parsing.cfg[count])
				custom_exit(cub, K_ERR_MALLOC);
			count++;
		}
		i++;
	}
	cub->parsing.cfg[count++] = NULL;
	check_arg_nmb_by_line(cub);
	get_map(cub, i);
}

void	get_map(t_cub *cub, int i)
{
	size_t		len;
	int			j;

	j = 0;
	len = 0;
	while (cub->parsing.file[len])
		len++;
	cub->parsing.map = (char **) malloc((len - i) * sizeof(char **));
	if (!cub->parsing.map)
		custom_exit(cub, K_ERR_MALLOC);
	while (cub->parsing.file[++i])
	{
		cub->parsing.map[j] = ft_strdup(cub->parsing.file[i]);
		if (!cub->parsing.map[j])
			custom_exit(cub, K_ERR_MALLOC);
		j++;
	}
	cub->parsing.map[j] = NULL;
}

void	check_arg_nmb_by_line(t_cub *cub)
{
	char	**splited_line;
	int		i;

	i = -1;
	while (cub->parsing.cfg[++i])
	{
		splited_line = ft_split(cub->parsing.cfg[i], ' ');
		if (i < 4 && ft_strlen(splited_line[0]) != 2)
		{
			ft_putstr_fd(MSG_ERR_WRONG_ID, 2);
			ft_free_tab(splited_line);
			custom_exit(cub, EXIT_FAILURE);
		}
		if (tablen(splited_line) != 2)
		{
			ft_putstr_fd(MSG_ERR_CFG, 2);
			ft_free_tab(splited_line);
			custom_exit(cub, EXIT_FAILURE);
		}
		ft_free_tab(splited_line);
	}
}

int	tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
