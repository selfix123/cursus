/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:05:53 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/02/02 15:39:39 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(void)
{
	mlx_t	*mlx;
	t_map	*map;

	mlx = mlx_init(WIDTH, HEIGHT, "jesus carnage", true);
	sizemap(map, map->fd);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
