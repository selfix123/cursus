/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:27:49 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/04/06 15:18:38 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	spawnplayer(mlx_t *mlx, int x, int y, t_img *img)
{
	spawnbackground(mlx, x, y, img);
	mlx_image_to_window(mlx, img->player, (x * PIC_SIZE), (y * PIC_SIZE));
}

void	spawnwall(mlx_t *mlx, int x, int y, t_img *img)
{
	mlx_image_to_window(mlx, img->wall, (x * PIC_SIZE), (y * PIC_SIZE));
}	

void	spawnpdoor(mlx_t *mlx, int x, int y, t_img *img)
{
	spawnbackground(mlx, x, y, img);
	mlx_image_to_window(mlx, img->door, (x * PIC_SIZE), (y * PIC_SIZE));
}

void	spawncollectible(mlx_t *mlx, int x, int y, t_img *img)
{
	spawnbackground(mlx, x, y, img);
	mlx_image_to_window(mlx, img->collectible, (x * PIC_SIZE), (y * PIC_SIZE));
}

void	spawnbackground(mlx_t *mlx, int x, int y, t_img *img)
{
	mlx_image_to_window(mlx, img->background, (x * PIC_SIZE), (y * PIC_SIZE));
}
