/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:11:11 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/28 15:38:36 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strndup(char *str, int start, int finish)
{
	int	i;
	char *ret;

	i = 0;
	ret = ft_calloc((finish - start) + 1, 1);
	while(start < finish)
	{
		ret[i] = str[start];
		i ++ ;
		start ++;
	}
	ret[i + 1] = 0;
	return(ret);
}
