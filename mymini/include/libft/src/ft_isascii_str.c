/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:33:36 by misidori          #+#    #+#             */
/*   Updated: 2023/09/01 15:58:30 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

bool ft_isascii_str(char *str)
{
    int i = 0;

    while (str[i])
    {
        if ((unsigned char)str[i] <= 127)
        {
            i++;
        }
        else
        {
            return false;
        }
    }

    return true;
}

