/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:27:49 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/01/30 10:51:41 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	spawnplayer(mlx_t *mlx, int x, int y, t_img *img)
{
	img->xpm = mlx_load_xpm42("img/Jesus(75)");
	img->player = mlx_texture_to_image(mlx, &img->xpm->texture);
	mlx_image_to_window(mlx, img->player, x * PIC_SIZE, y * PIC_SIZE);
}

void	spawnwall(mlx_t *mlx, int x, int y, t_img *img)
{
	img->xpm = mlx_load_xpm42("img/wall(75)");
	img->wall = mlx_texture_to_image(mlx, &img->xpm->texture);
	mlx_image_to_window(mlx, img->wall, x * PIC_SIZE, y * PIC_SIZE);
}	

void	spawnpdoor(mlx_t *mlx, int x, int y, t_img *img)
{
	img->xpm = mlx_load_xpm42("img/Door(75)");
	img->door = mlx_texture_to_image(mlx, &img->xpm->texture);
	mlx_image_to_window(mlx, img->door, x * PIC_SIZE, y * PIC_SIZE);
}

void	spawncollectible(mlx_t *mlx, int x, int y, t_img *img)
{
	img->xpm = mlx_load_xpm42("img/cross(75)_B");
	img->collectible = mlx_texture_to_image(mlx, &img->xpm->texture);
	mlx_image_to_window(mlx, img->collectible, x * PIC_SIZE, y * PIC_SIZE);
}

void	spawnbackground(mlx_t *mlx, int x, int y, t_img *img)
{
	img->xpm = mlx_load_xpm42("img/Background(75)_B(1)");
	img->background = mlx_texture_to_image(mlx, &img->xpm->texture);
	mlx_image_to_window(mlx, img->background, x * PIC_SIZE, y * PIC_SIZE);
}
