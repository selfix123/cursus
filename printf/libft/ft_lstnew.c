/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:38:43 by zbeaumon          #+#    #+#             */
/*   Updated: 2022/11/03 10:50:59 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = ft_calloc(sizeof(t_list), 1);
	if (!new)
		return (NULL);
	new->next = NULL;
	new->content = content;
	return (new);
}
