/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:15:01 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/04/24 15:12:39 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_map(t_game *game, t_img *img)
{
	mlx_delete_image(game->mlx, img->collectible);
	mlx_delete_image(game->mlx, img->background);
	mlx_delete_image(game->mlx, img->door);
	mlx_delete_image(game->mlx, img->player);
	mlx_delete_image(game->mlx, img->wall);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	ft_xfree(map);
}
