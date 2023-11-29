/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp_len_and_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:44:05 by misidori          #+#    #+#             */
/*   Updated: 2023/11/28 11:48:24 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_cmp_len_and_str(char *str1, char *str2, int len)
{
	if (!str1 || !str2 || !len)
		return (0);
	if (ft_strncmp(str1, str2, len) == 0 && ft_strlen(str1) == len)
		return (1);
	else
		return (-1);
}
