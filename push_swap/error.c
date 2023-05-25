/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:48:59 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/03/23 15:03:36 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_int(int ac, char **av)
{
    int i;
    int len;

    i = -1;
    while (++i < ac)
    {
        len = ft_strlen(av[i]);
        if (len > 11)
            return (1);
        if (len == 11 && ft_liatoi(av[i]) < INT_MIN)
            return (1);
        if (len == 10 && ft_liatoi(av[i]) > INT_MAX)
            return (1);
    }
    return (0);
}

int valid_argv(int ac, char **av)
{
    int i;
    int j;

    i = -1;
    while (++i < ac)
    {
        j = 0;
        if (av[i][j] == '-' && av[i][j + 1] != '\0')
            j++;
        while (av[i][j])
        {
            if (av[i][j] < '0' || av[i][j] > '9')
                return (1);
            j++;
        }
    }
    return (0);
}

int check_double(int ac, char **av)
{
    int *temp;
    int i;
    int j;

    temp = temp_array(ac, av);
    if (temp == NULL)
        return (1);
    i = 0;
    while (i < ac)
    {
        j = i + 1;
        while (j < ac)
        {
            if (temp[i] == temp[j]) //free
                return (1);
            j++;
        }
        i++;
    }
    return (0); //free
}