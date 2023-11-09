/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:36:51 by afalconi          #+#    #+#             */
/*   Updated: 2023/11/09 18:14:20 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isnumeric(char c)
{
	if (c == '0' || c == '1' || c == '2'
		|| c == '3' || c == '4' || c == '5'
		|| c == '6' || c == '7' || c == '8' || c == '9')
		return (1);
	return (0);
}
