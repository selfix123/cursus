/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:59:33 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/04/25 12:49:09 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(int nb, t_game *game, char *message)
{
	if (nb == 1)
	{
		printf("Error\n%s\n", message);
		if (game->map_data.mapback != NULL)
			free_map(game->map_data.mapback);
	}
	else if (nb == 2)
		printf("Error\n%s\n", message);
	else if (nb == 3)
	{
		printf("%s\n", message);
		if (game->map_data.mapback != NULL)
			free_map(game->map_data.mapback);
	}
	if (game->mlx)
		mlx_terminate(game->mlx);
	exit(0);
}

int	invalid_map(t_game *game, int y, int x)
{
	if (game->map_data.mapback[y][x] == '1' ||
		game->map_data.mapback[y][x] == 'p' ||
		game->map_data.mapback[y][x] == 'c' ||
		game->map_data.mapback[y][x] == 'e' ||
		game->map_data.mapback[y][x] == 'o')
		return (1);
	else
		return (0);
}
