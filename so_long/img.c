/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:29:23 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/04/07 14:14:23 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_game *game)
{
	game->img.collectible = load_img(game->mlx, COLL);
	game->img.background = load_img(game->mlx, BACKGROUND);
	game->img.player = load_img(game->mlx, PLAYER);
	game->img.door = load_img(game->mlx, DOOR);
	game->img.wall = load_img(game->mlx, WALL);

}


mlx_image_t	*load_img(mlx_t *mlx, char *path)
{
	xpm_t		*xpm;
	mlx_image_t	*tmp;

	xpm = mlx_load_xpm42(path);
	tmp = mlx_texture_to_image(mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	return (tmp);
}
