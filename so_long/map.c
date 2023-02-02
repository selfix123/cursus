/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:21:33 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/02/02 15:25:14 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sizemap(t_map *map, char *mape)
{
	int	i;

	i = 0;
	while (mape[i])
	{
		if (mape[i] == '\n' || mape[i] == '\0')
			map->heightnb++;
		i++;
	}
	while (map->mapback[i])
	{
		if (mape[i] == '\n')
			return ;
		map->widthnb++;
		i++;
	}
}

int	valid_map(char *str)
{
	int			i;
	t_count		count;

	i = 0;
	count.coll_c = 0;
	count.exit_c = 0;
	count.player_c = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			count.player_c++;
		else if (str[i] == 'C')
			count.coll_c++;
		else if (str[i] == 'E')
			count.coll_c++;
		else if (count.player_c != 1 || \
		count.coll_c < 1 || count.exit_c != 1)
			return (-1);
		i++;
	}
	if (count.player_c != 1 || count.coll_c < 1 || count.exit_c != 1)
		return (0);
	return (count.coll_c);
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
		if (valid_map(*map->mapback) > 0)
		{
			map->mapback = ft_split(new, '\n');
			return (map->mapback);
		}
	}
	return (NULL);
}

void	spawn_map(t_map *map, t_img *img, mlx_t *mlx)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x <= map->heightnb)
	{
		while (y <= map->widthnb)
		{
			if (map->mapback[x][y] == 'E')
				spawnpdoor(mlx, x, y, img);
			if (map->mapback[x][y] == 'P')
				spawnplayer(mlx, x, y, img);
			if (map->mapback[x][y] == 'C')
				spawncollectible(mlx, x, y, img);
			if (map->mapback[x][y] == '1')
				spawnwall(mlx, x, y, img);
			if (map->mapback[x][y] == '0')
				spawnbackground(mlx, x, y, img);
			y++;
		}
		x++;
	}
}
