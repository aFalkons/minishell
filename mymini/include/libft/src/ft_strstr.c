/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:01:58 by matteo            #+#    #+#             */
/*   Updated: 2023/11/22 20:42:40 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*h;
	const char	*n;

	while (*haystack)
	{
		h = haystack;
		n = needle;
		while (*haystack && *n && *haystack == *n)
		{
			haystack++;
			n++;
		}
		if (!*n)
		{
			return ((char *)h);
		}
		haystack = h + 1;
	}
	return (NULL);
}
