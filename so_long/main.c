/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:05:53 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/04/07 14:41:07 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_movement_handler(mlx_key_data_t *keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata->key == MLX_PRESS || keydata->key == MLX_REPEAT)
	{
		if (keydata->key == MLX_KEY_W || keydata->key == MLX_KEY_UP)
			move_player(game, 1, 0);
		else if (keydata->key == MLX_KEY_S || keydata->key == MLX_KEY_DOWN)
			move_player(game, -1, 0);
		else if (keydata->key == MLX_KEY_A || keydata->key == MLX_KEY_LEFT)
			move_player(game, 0, -1);
		else if (keydata->key == MLX_KEY_D || keydata->key == MLX_KEY_RIGHT)
			move_player(game, 0, 1);
		else if (keydata->key == MLX_KEY_ESCAPE)
			ft_putendl_fd("You are bad at the game", 1);
	}
}

void	map_initialisation(t_map *map_data, t_img *img, t_game *game)
{
	(void) img;
	map_data->fd = open(MAP, O_RDONLY);
	if (map_data->fd == -1)
		exit(printf("cannot open map\n"));
	map(game);
	map_data->height = map_data->heightnb * PIC_SIZE;
	map_data->width = map_data->widthnb * PIC_SIZE;
	game->mlx = mlx_init(map_data->width, map_data->height, "Frog on ice", false);
	init_img(game);
	spawn_map(game);
}

void	ft_player_position(t_map *map_data)
{
	int	x;
	int	y;

	x = 0;
	while (x < map_data->heightnb)
	{
		y = 0;
		while (y < map_data->widthnb)
		{
			if (map_data->mapback[x][y] == 'P')
			{
				map_data->player_posx = x;
				map_data->player_posy = y;
			}
			y++;
		}
		x++;
	}
}

int32_t	main(void)
{
	t_game	game;

	ft_bzero(&game.map_data, sizeof(t_map));
	map_initialisation(&game.map_data, &game.img, &game);
	mlx_loop_hook(game.mlx, , );
	mlx_key_hook(game.mlx, ft_movement_handler, );
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
