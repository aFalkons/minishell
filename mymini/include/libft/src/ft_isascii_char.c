/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:33:36 by misidori          #+#    #+#             */
/*   Updated: 2023/08/13 13:06:14 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

bool	ft_isascii_char(int num)
{
	if (num >= 0 && num <= 127)
		return (true);
	else
		return (false);
}
