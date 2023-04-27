/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:37:24 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/04/27 15:23:04 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game, int y, int x)
{
	if ((x < game->map_data.widthnb && y < game->map_data.heightnb)
		&& (x > 0 && y > 0) && (game->map_data.mapback[y]))
	{
		if (invalid_map(game, y, x) == 1)
			return ;
		else if (game->map_data.mapback[y][x] == 'E')
		{
			game->exit_fc++;
			game->map_data.mapback[y][x] = 'e';
			return ;
		}
		else if (game->map_data.mapback[y][x] == 'C')
		{
			game->coll_fc++;
			game->map_data.mapback[y][x] = 'c';
		}
		else if (game->map_data.mapback[y][x] == '0')
			game->map_data.mapback[y][x] = 'o';
		flood_fill(game, y + 1, x);
		flood_fill(game, y - 1, x);
		flood_fill(game, y, x + 1);
		flood_fill(game, y, x - 1);
	}
}

int	is_map_valid(t_game *game)
{
	flood_fill(game, game->player_posy, game->player_posx);
	if (game->coll_fc != game->coll_c || game->exit_c != game->exit_fc
		|| game->player_c != 1 || game->coll_fc == 0)
		return (0);
	else
		return (1);
}

void	render_map(t_game *game, int y, int x)
{
	if (game->map_data.mapback[y][x] == 'e' ||
		game->map_data.mapback[y][x] == 'E')
		spawnpdoor(game->mlx, x, y, &game->new_img);
	else if (game->map_data.mapback[y][x] == 'p' ||
			game->map_data.mapback[y][x] == 'P')
		spawnplayer(game->mlx, x, y, &game->new_img);
	else if (game->map_data.mapback[y][x] == 'c' ||
		game->map_data.mapback[y][x] == 'C')
		spawncollectible(game->mlx, x, y, &game->new_img);
	else if (game->map_data.mapback[y][x] == '1')
		spawnwall(game->mlx, x, y, &game->new_img);
	else if (game->map_data.mapback[y][x] == 'o' ||
				game->map_data.mapback[y][x] == '0')
		spawnbackground(game->mlx, x, y, &game->new_img);
}

int	check_map_size(t_game *game, int *y_s, int *x_s)
{
	int	i;

	i = 0;
	*x_s = ft_strlen(game->map_data.mapback[i]);
	while (game->map_data.mapback[i] && game->map_data.mapback[i + 1])
	{
		if (ft_strlen(game->map_data.mapback[i])
			== ft_strlen(game->map_data.mapback[i + 1]))
		i++;
		else
			map_error(1, game, MAP_ERROR);
		y_s++;
	}
	if (*x_s >= 34 || *y_s >= 18)
		map_error(1, game, MAP_TOO_BIG);
	return (is_map_rectangular(game));
}

int	is_map_rectangular(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (game->map_data.mapback[0][x])
		if (game->map_data.mapback[0][x++] != '1')
			map_error(1, game, MAP_ERROR);
	while (game->map_data.mapback[y])
	{
		if (game->map_data.mapback[y][0] != '1'
			|| game->map_data.mapback[y][x - 1] != '1')
			map_error(1, game, MAP_ERROR);
		y++;
	}
	y--;
	while (--x)
	{
		if (game->map_data.mapback[y][x] != '1')
			map_error(1, game, MAP_ERROR);
	}
	return (0);
}
