/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:35:53 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/02/02 15:21:15 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define MAP "map.ber"
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
	int		height;
	int		width;
	int		widthnb;
	int		heightnb;
	char	**mapback;
	int		fd;
}	t_map;

typedef struct s_count
{
	int	player_c;
	int	coll_c;
	int	exit_c;
}	t_count;

void	spawnplayer(mlx_t *mlx, int x, int y, t_img *img);
void	spawnwall(mlx_t *mlx, int x, int y, t_img *img);
void	spawnpdoor(mlx_t *mlx, int x, int y, t_img *img);
void	spawncollectible(mlx_t *mlx, int x, int y, t_img *img);
void	spawnbackground(mlx_t *mlx, int x, int y, t_img *img);
void	sizemap(t_map *map, char *mape);
int		valid_map(char *str);
char	**map(t_map *map);
void	spawn_map(t_map *map, t_img *img, mlx_t *mlx);

#endif