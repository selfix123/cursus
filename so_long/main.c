/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:05:53 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/01/31 10:46:02 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(void)
{
	mlx_t	*mlx;
	t_img	*img = NULL;
	t_map	*map = NULL;

	mlx = mlx_init(WIDTH, HEIGHT, "jesus battle", true);
	spawn_map(map, img, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
