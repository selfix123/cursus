/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:30:26 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/01/11 15:30:47 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_tiny_split(char *s, size_t *cut)
{
	char	*new;
	size_t	i;

	i = 0;
	while (s[i])
		if (s[i++] == '\n')
			break ;
	new = ft_calloc(i + 1, sizeof(char));
	if (!new)
		return (new = ft_xfree(new));
	*cut = i;
	while (i--)
		new[i] = s[i];
	return (new);
}

char	ft_find(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return ('\n');
		i++;
	}
	return ('0');
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	t_var		t_data;

	if (fd < 0 || BUFFER_SIZE < 0 || fd > OPEN_MAX)
		return (NULL);
	if (!stash[fd])
		stash[fd] = ft_calloc(1, sizeof(char));
	t_data.tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	t_data.rv = 0;
	while (ft_find(stash[fd]) == '0')
	{
		ft_bzero(t_data.tmp, BUFFER_SIZE + 1);
		t_data.rv = read(fd, t_data.tmp, BUFFER_SIZE);
		if (t_data.rv <= 0)
			break ;
		stash[fd] = ft_strjoin(stash[fd], t_data.tmp);
	}
	t_data.tmp = ft_xfree(t_data.tmp);
	if (t_data.rv == -1 || (t_data.rv <= 0 && *stash[fd] == 0))
		return (stash[fd] = ft_xfree(stash[fd]), NULL);
	t_data.tmp = ft_tiny_split(stash[fd], &t_data.cut);
	t_data.old = stash[fd];
	stash[fd] = ft_strjoin(NULL, stash[fd] + t_data.cut);
	return (ft_xfree(t_data.old), t_data.tmp);
}
