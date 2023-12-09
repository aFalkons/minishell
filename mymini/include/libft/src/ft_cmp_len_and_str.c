/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp_len_and_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:44:05 by misidori          #+#    #+#             */
/*   Updated: 2023/12/01 21:21:43 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_cmp_len_and_str(char *str1, char *str2, int len)
{
	if (!str1 || !str2 || !len)
		return (0);
	if (ft_strncmp(str1, str2, len) == 0 && ft_strlen(str2) == len)
		return (1);
	else
		return (-1);
}
