/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:35:53 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/01/24 13:10:53 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH 2550
# define HEIGHT 1440
# define PIC_SIZE 75
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <memory.h>
# include "include/MLX42/include/MLX42/MLX42.h"
# include "include/libft/libft.h"

typedef struct s_img
{
	mlx_image_t	*wall;
	mlx_image_t	*player;
	mlx_image_t	*background;
	mlx_image_t	*collectible;
	mlx_image_t	*door;
	xpm_t		*xpm;
}	t_img;

typedef struct s_map
{
	int	height;
	int	width;
	int	widthnb;
	int	heightnb;
	int	**mapback;
	int	fd;
}	t_map;

void	spawnplayer(mlx_t *mlx, int x, int y, t_img *img);
void	spawnwall(mlx_t *mlx, int x, int y, t_img *img);
void	spawnpdoor(mlx_t *mlx, int x, int y, t_img *img);
void	spawncollectible(mlx_t *mlx, int x, int y, t_img *img);
void	spawnbackground(mlx_t *mlx, int x, int y, t_img *img);

#endif