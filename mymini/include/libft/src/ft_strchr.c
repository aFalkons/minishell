/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:21:31 by misidori          #+#    #+#             */
/*   Updated: 2023/08/13 13:37:02 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len_s;

	i = 0;
	len_s = ft_strlen(s);
	while (i <= len_s)
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
