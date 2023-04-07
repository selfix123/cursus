/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:30:20 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/04/07 11:14:41 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include  <limits.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_var
{
	char	*tmp;
	char	*old;
	int		rv;
	size_t	cut;
}	t_var;

char	*get_next_line(int fd);
char	*ft_tiny_split(char *s, size_t *cut);
char	ft_find(char *s);

#endif