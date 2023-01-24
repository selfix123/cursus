/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:21:33 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/01/24 13:40:00 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sizemap(t_map *map)
{
	int		size;
	char	*temp;
	int		i;

	size = 0;
	i = 0;
	while (i > 0)
	{
		temp = get_next_line(map->fd);
		size++;
		if (temp != NULL)
			free (temp);
		i++;
	}
	return (size);
}

void	valid_map(char *str)
{
	int	i;
	int	player_c;
	int	coll_c;
	int	exit_c;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			player_c++;
		else if (str[i] == 'C')
			coll_c++;
		else if (str[i] == 'E')
			exit_c++;
		i++;
	}
	if (player_c != 1 || coll_c < 1 || exit_c != 1)
		return (0);
	else
		return (1);
	return (coll_c);
}

char	map(t_map *map)
{
	char	*temp;
	char	*new;

	while (temp)
	{
		temp = get_next_line(map->fd);
		new = ft_fstrjoin(new, temp);
		if (temp != NULL)
			free (temp);
	}
	map->mapback = ft_split(new, '\n');
	return (map->mapback);
}

/*\
int		x;
	int		y;
	char	*gnl;

	gnl = get_next_line(fd);
	while (x < _x)
	{
		while (y < _y)
		{
			if (*gnl == 'E')
				spawnpdoor(mlx, x, y);
			if (*gnl == 'P')
				spawnplayer(mlx, x, y);
			if (gnl == 'C')
				spawncollectible(mlx, x, y);
			if (gnl == '1')
				spawnwall(mlx, x, y);
			if (gnl == '0')
				spawnbackground(mlx, x, y);
		}
	}
*/