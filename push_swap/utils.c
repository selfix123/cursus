/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:38:06 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/18 13:43:04 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_dlstadd_back(t_data **lst, t_data *new)
{
	t_data	*last;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
	}
	else
	{
		last = (*lst)->previous;
		last->next = new;
		new->previous = last;
		new->next = (*lst);
		(*lst)->previous = new;
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

// void	get_total_args(char *ac, char **av, t_piles *piles)
// {
// 	char	**new_ac;

// 	if (*ac == 2)
// 	{
// 		*ac = word_count(av[1], ' ');
// 		new_ac = ft_split(av[1], ' ');
// 	}
// 	else
// 	{
// 		*ac = ac - 1;
// 		new_ac = av + 1;
// 	}
// 	return (new_ac);
// }
