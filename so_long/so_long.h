/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:35:53 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/04/25 13:01:13 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH 2550
# define HEIGHT 1440
# define MAP	"maps/map.ber"
# define PIC_SIZE 75
# define PLAYER	"img/Jesus(75).xpm42"
# define WALL	"img/wall(75).xpm42"
# define DOOR	"img/Door(75).xpm42"
# define BACKGROUND	"img/Background(75)_B.xpm42"
# define COLL	"img/cross(75)_B.xpm42"
# define MAP_ERROR "invalid map"
# define WIN_GAME "Good job you won!"
# define FILE_ERROR "invalid file"
# define STOP_GAME "Quitting game"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <memory.h>
# include <fcntl.h>
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

typedef struct s_game
{
	t_map	map_data;
	t_img	old_img;
	t_img	new_img;
	mlx_t	*mlx;
	int		player_posx;
	int		player_posy;
	int		player_c;
	int		coll_c;
	int		coll_fc;
	int		player_move;
	int		exit_c;
}	t_game;

void		spawnplayer(mlx_t *mlx, int x, int y, t_img *img);
void		spawnwall(mlx_t *mlx, int x, int y, t_img *img);
void		spawnpdoor(mlx_t *mlx, int x, int y, t_img *img);
void		spawncollectible(mlx_t *mlx, int x, int y, t_img *img);
void		spawnbackground(mlx_t *mlx, int x, int y, t_img *img);
void		sizemap(t_game *game, char *mape);
int			valid_map(char *str, t_game *game);
void		map(t_game *game);
void		spawn_map(t_game *game);
void		init_img(t_game *game);
mlx_image_t	*load_img(mlx_t *mlx, char *path);
void		move_player(t_game *game, int x, int y);
void		ft_player_position(t_game *game);
void		destroy_map(t_game *game, t_img *img);
void		respawn_map(void *ptr);
void		free_map(char **map);
void		flood_fill(t_game *game, int y, int x);
void		map_error(int nb, t_game *game, char *message);
int			is_map_valid(t_game *game);
int			invalid_map(t_game *game, int y, int x);
void		end_game_win(t_game *game, char *message);

#endif