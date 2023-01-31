/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:21:33 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/01/31 11:18:34 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sizemap(t_map *map)
{
	int		size;
	char	*temp;
	int		i;

	size = 0;
	i = 0;
	temp = NULL;
	while (i > 0)
	{
		map->mapback;
		size++;
		if (temp != NULL)
			free (temp);
		i++;
	}
	return (size);
}

int	valid_map(char *str, t_count *count)
{
	int	i;

	i = 0;
	count->coll_c = 0;
	count->exit_c = 0;
	count->player_c = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			count->player_c++;
		else if (str[i] == 'C')
			count->coll_c++;
		else if (str[i] == 'E')
			count->exit_c++;
		else if (count->player_c != 1 || \
		count->coll_c < 1 || count->exit_c != 1)
			return (-1);
		i++;
	}
	if (count->player_c != 1 || count->coll_c < 1 || count->exit_c != 1)
		return (0);
	return (count->coll_c);
}

char	**map(t_map *map)
{
	char	*temp;
	char	*new;

	temp = "yessir miller";
	new = NULL;
	if (map->fd > 0)
	{	
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
	else
		return (NULL);
}

void	spawn_map(t_map *map, t_img *img, mlx_t *mlx)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	while (x <= map->height)
	{
		x++;
		while (y <= map->width)
		{
			if ( == 'E')
				spawnpdoor(mlx, x, y, img);
			if ( == 'P')
				spawnplayer(mlx, x, y, img);
			if ( == 'C')
				spawncollectible(mlx, x, y, img);
			if ( == '1')
				spawnwall(mlx, x, y, img);
			if ( == '0')
				spawnbackground(mlx, x, y, img);
			y++;
		}
	}
}
