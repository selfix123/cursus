/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:21:33 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/04/27 15:13:40 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sizemap(t_game *game, char *mape)
{
	int	i;

	i = 0;
	if (!(mape) || mape[i] == '\n')
		map_error(1, game, MAP_ERROR);
	while (mape[i])
	{
		if (mape[i] == '\n' || mape[i] == '\0')
			game->map_data.heightnb++;
		if (mape[i] == '\n' && (mape[i + 1] == '\0' || mape[i + 1] == '\n'))
			map_error(1, game, MAP_ERROR);
		i++;
	}
	game->map_data.heightnb++;
	i = 0;
	while (mape[i])
	{
		if (mape[i] == '\n')
			return ;
		game->map_data.widthnb++;
		i++;
	}
}

int	valid_map(char *str, t_game *game)
{
	int			i;

	i = 0;
	if (!str)
		map_error(1, game, MAP_ERROR);
	while (str[i])
	{
		if (!(str[i] == 'P' || str[i] == 'E' || str[i] == 'C'
				|| str[i] == '1' || str[i] == '0' || str[i] == '\n'))
			return (0);
		if (str[i] == 'C')
			game->coll_c++;
		if (str[i] == 'E')
			game->exit_c++;
		if (str[i] == 'P')
			game->player_c++;
		i++;
	}
	return (1);
}

void	map(t_game *game)
{
	char	*temp;
	char	*new;

	temp = "yessir miller";
	new = NULL;
	if (game->map_data.fd > 0)
	{	
		while (temp)
		{
			temp = get_next_line(game->map_data.fd);
			new = ft_fstrjoin(new, temp);
			ft_xfree(temp);
		}
		close(game->map_data.fd);
		if (!valid_map(new, game))
			map_error(1, game, MAP_ERROR);
		game->map_data.mapback = ft_split(new, '\n');
		sizemap(game, new);
		ft_xfree(new);
	}
}

void	spawn_map(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->map_data.heightnb)
	{
		x = 0;
		while (x < game->map_data.widthnb)
		{
			render_map(game, y, x);
			x++;
		}
		y++;
	}
}

void	respawn_map(void *ptr)
{
	t_game			*game;

	game = ptr;
	destroy_map(game, &game->old_img);
	game->old_img = game->new_img;
	init_img(game);
	spawn_map(game);
}
