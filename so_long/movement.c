/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:31:56 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/04/25 12:47:02 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_in_map(t_game *game, int ny, int nx)
{
	game->map_data.mapback[ny][nx] = 'p';
	game->player_posx = nx;
	game->player_posy = ny;
	respawn_map(game);
	game->player_move++;
	ft_putnbr_fd(game->player_move, 1);
	ft_putchar_fd('\n', 1);
}

void	move_player(t_game *game, int y, int x)
{
	int	nx;
	int	ny;

	ny = game->player_posy + y;
	nx = game->player_posx + x;
	if (game->map_data.mapback[ny][nx] != '1')
	{
		if (game->map_data.mapback[ny][nx] == 'c'
			|| game->map_data.mapback[ny][nx] == 'C')
		{
			game->coll_c--;
			game->map_data.mapback[ny][nx] = 'o';
		}
		if ((game->map_data.mapback[ny][nx] == 'e'
			|| game->map_data.mapback[ny][nx] == 'E') && game->coll_c <= 0)
			map_error(3, game, WIN_GAME);
		if (game->map_data.mapback[ny][nx] == 'o')
		{
			game->map_data.mapback[game->player_posy][game->player_posx] = 'o';
			move_in_map(game, ny, nx);
		}
	}
}
