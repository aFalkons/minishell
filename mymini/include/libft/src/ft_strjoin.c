/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:49:07 by matteo            #+#    #+#             */
/*   Updated: 2023/08/08 08:18:23 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined_str;
	size_t	i;
	size_t	j;

	// if (!s1 || !s2)
	// 	return (NULL);
	i = 0;
	j = 0;
	joined_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined_str)
		return (0);
	if (s1 != 0)
	{
		while (s1[i])
			joined_str[j++] = s1[i++];
	}
	i = 0;
	if (s2 != 0)
	{
		while (s2[i])
			joined_str[j++] = s2[i++];
	}
	joined_str[j] = '\0';
	return (joined_str);
}
