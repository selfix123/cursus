/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:14:04 by zbeaumon          #+#    #+#             */
/*   Updated: 2022/12/11 16:33:21 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include  <limits.h>

char	*get_next_line(int fd)
{
	static t_list	*stash;
	char			*line;
	int				readed;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (free_stash(stash), NULL);
	readed = 1;
	line = NULL;
	if (read_and_stash(fd, &stash) == 1)
		return (free_stash(stash), NULL);
	if (stash == NULL)
		return (NULL);
	extract_line(stash, &line);
	clean_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

int	read_and_stash(int fd, t_list **stash)
{
	char	*buf;
	int		readed;

	readed = 0;
	while (!found_newline(*stash))
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return (1);
		readed = (int)read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buf);
			return (1);
		}
		if ((*stash == NULL && readed == 0))
		{
			free(buf);
			return (1);
		}
		buf[readed] = '\0';
		add_to_stash(stash, buf, readed);
		free(buf);
	}
	return (0);
}

void	add_to_stash(t_list **stash, char *buf, int readed)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node ->next = NULL;
	new_node->cont = malloc(sizeof(char) * (readed + 1));
	if (new_node->cont == NULL)
		return ;
	i = 0;
	while (buf[i] && i < readed)
	{
		new_node->cont[i] = buf[i];
		i++;
	}
	new_node->cont[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_node;
		return ;
	}
	last = ft_lst_get_last(*stash);
	last->next = new_node;
}

void	extract_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return ;
	generate_line(line, stash);
	if (*line == NULL)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->cont && stash->cont[i])
		{
			if (stash->cont[i] == '\n')
			{
				(*line)[j++] = stash->cont[i];
				break ;
			}
			(*line)[j++] = stash->cont[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

void	clean_stash(t_list **stash)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (stash == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = ft_lst_get_last(*stash);
	i = 0;
	while (last->cont[i] && last->cont[i] != '\n')
		i++;
	if (last->cont && last->cont[i] == '\n')
		i++;
	clean_node->cont = malloc(sizeof(char) * ((ft_strlen(last->cont) - i) + 1));
	if (clean_node->cont == NULL)
		return ;
	j = 0;
	while (last->cont[i])
		clean_node->cont[j++] = last->cont[i++];
	clean_node->cont[j] = '\0';
	free_stash(*stash);
	*stash = clean_node;
}
