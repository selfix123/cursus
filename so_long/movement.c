/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:16:58 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/01/23 13:51:13 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hook(void *param)
{
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_W))
		g_img->instances[0].y -= 20;
	if (mlx_is_key_down(param, MLX_KEY_S))
		g_img->instances[0].y += 20;
	if (mlx_is_key_down(param, MLX_KEY_A))
		g_img->instances[0].x -= 20;
	if (mlx_is_key_down(param, MLX_KEY_D))
		g_img->instances[0].x += 20;
	if (mlx_is_key_down(param, MLX_KEY_UP))
		g_img->instances[1].y -= 20;
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
		g_img->instances[1].y += 20;
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
		g_img->instances[1].x -= 20;
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
		g_img->instances[1].x += 20;
}
