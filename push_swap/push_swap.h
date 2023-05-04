/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:52:04 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/04 12:56:31 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include<stdio.h>
# include "libft/libft.h"
# include <stdbool.h>

typedef struct s_data
{
	int				content;
	struct s_data	*next;
	struct s_data	*previous;
}	t_data;

typedef struct s_piles
{
	t_piles	*a;
	t_piles	*b;
}	t_piles;

#endif
