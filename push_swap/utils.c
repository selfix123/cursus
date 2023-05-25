/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:38:06 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/25 10:26:11 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	index(int *temp, int index, int len)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < len - 1)
	{
		if (temp[i] < temp[index])
			count++;
		i++;
	}
	return (count + 1);
}

t_data	*ft_dlstnew(int content)
{
	t_data	*new;

	new = ft_calloc(sizeof(t_data), 1);
	if (!new)
		return (NULL);
	new->index = 0;
	new->content = content;
	new->next = new;
	new->previous = new;
	return (new);
}

void	ft_dlstadd_back(t_data **lst, int *temp, int i, int ac)
{
	t_data	*ptr;
	t_data	*head;

	if (!*lst)
		*lst = ft_dlstnew(index(temp, i, ac));
	else
	{
		head = (*lst);
		ptr = ft_calloc(1, sizeof(t_data));
		ptr->content = index(temp, i, ac);
		ptr->previous = head->previous;
		ptr->next = head;
		ptr->next->previous = ptr;
		ptr->previous->next = ptr;
		(*lst) = head;
	}
}

size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	nb_cols;

	nb_cols = 0;
	if (!s[0])
		return (0);
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_cols++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_cols++;
	return (nb_cols);
}

char	**get_total_args(int *ac, char **av)
{
	char	**new_av;

	if (*ac == 2)
	{
		*ac = word_count(av[1], ' ');
		new_av = ft_split(av[1], ' ');
	}
	else
	{
		*ac = *(ac - 1);
		new_av = av + 1;
	}
	return (new_av);
}
