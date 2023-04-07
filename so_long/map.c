/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:21:33 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/04/07 10:31:14 by zbeaumon         ###   ########.fr       */
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
	map->heightnb++;
	i = 0;
	while (mape[i])
	{
		if (mape[i] == '\n')
			return ;
		map->widthnb++;
		i++;
	}
}

int	valid_map(char *str, t_game *game)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == 'P' || str[i] == 'E' || str[i] == 'C'
				|| str[i] == '1' || str[i] == '0' || str[i] == '\n'))
			return (0);
		if (str[i] == 'C')
			game->coll_c++;
		i++;
	}
	return (1);
}

void	map(t_game *game)
{
	char	*temp;
	char	*new;

	temp = "yessir miller";
	new = NULL;
	if (game->map_data.fd > 0)
	{	
		while (temp)
		{
			temp = get_next_line(game->map_data.fd);
			Ct_mprintf(temp, ft_strlen(temp), 1, 'a');
			new = ft_fstrjoin(new, temp);
			ft_xfree(temp);
		}
		close(game->map_data.fd);
		if (valid_map(new, game) > 0)
			game->map_data.mapback = ft_split(new, '\n');
		sizemap(&game->map_data, new);
	}
}

void	spawn_map(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->map_data.heightnb)
	{
		x = 0;
		while (x < game->map_data.widthnb)
		{
			if (game->map_data.mapback[y][x] == 'E')
				spawnpdoor(game->mlx, x, y, &game->img);
			else if (game->map_data.mapback[y][x] == 'P')
				spawnplayer(game->mlx, x, y, &game->img);
			else if (game->map_data.mapback[y][x] == 'C')
				spawncollectible(game->mlx, x, y, &game->img);
			else if (game->map_data.mapback[y][x] == '1')
				spawnwall(game->mlx, x, y, &game->img);
			else if (game->map_data.mapback[y][x] == '0')
				spawnbackground(game->mlx, x, y, &game->img);
			x++;
		}
		y++;
	}
}
