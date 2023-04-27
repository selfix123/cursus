/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:05:53 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/04/27 15:12:17 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_movement_handler(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			move_player(game, -1, 0);
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			move_player(game, 1, 0);
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			move_player(game, 0, -1);
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			move_player(game, 0, 1);
		else if (keydata.key == MLX_KEY_ESCAPE)
		{
			mlx_close_window(game->mlx);
			map_error(3, game, STOP_GAME);
		}
	}
}

int	check_if_ber(char *av)
{
	av = ft_strrchr(av, '.');
	if (!av)
		return (0);
	else
		return (ft_strncmp(av, ".ber", 5));
}

void	map_initialisation(t_game *game, char *arg)
{
	game->map_data.fd = open(arg, O_RDONLY);
	if (game->map_data.fd < 0)
		map_error(2, game, FILE_ERROR);
	map(game);
	game->map_data.height = game->map_data.heightnb * PIC_SIZE;
	game->map_data.width = game->map_data.widthnb * PIC_SIZE;
	game->mlx = mlx_init(game->map_data.width, game->map_data.height,
			"Frog on ice", false);
	ft_player_position(game);
	init_img(game);
	check_map_size(game, &game->map_data.heightnb, &game->map_data.widthnb);
	if (is_map_valid(game) == 0)
	{
		map_error(1, game, MAP_ERROR);
	}
	spawn_map(game);
}

void	ft_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_data.heightnb)
	{
		x = 0;
		while (x < game->map_data.widthnb)
		{
			if (game->map_data.mapback[y][x] == 'P')
			{
				game->player_posx = x;
				game->player_posy = y;
			}
			x++;
		}
		y++;
	}
}

int32_t	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (argc == 1)
		map_initialisation(&game, MAP);
	else if (argc == 2 && check_if_ber(argv[1]) == 0)
		map_initialisation(&game, argv[1]);
	else
		map_error(2, &game, FILE_ERROR);
	mlx_loop_hook(game.mlx, respawn_map, &game);
	mlx_key_hook(game.mlx, ft_movement_handler, &game);
	mlx_loop(game.mlx);
	free_map(game.map_data.mapback);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
