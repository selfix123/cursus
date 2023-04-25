/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:37:24 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/04/24 12:06:11 by zbeaumon         ###   ########.fr       */
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
		else if (game->map_data.mapback[y][x] == 'P')
		{
			game->player_c++;
			game->map_data.mapback[y][x] = 'p';
		}
		else if (game->map_data.mapback[y][x] == 'E')
		{
			game->exit_c++;
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
	if (game->coll_fc != game->coll_c || game->exit_c != 1
		|| game->player_c != 1)
		return (0);
	else
		return (1);
}
