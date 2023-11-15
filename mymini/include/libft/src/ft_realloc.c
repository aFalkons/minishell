/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <matteo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:08:36 by matteo            #+#    #+#             */
/*   Updated: 2023/11/15 13:10:04 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	size_t	i;
	char	*src;
	char	*dst;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(size));
	new_ptr = (char *) malloc(size);
	if (!new_ptr)
		return (NULL);
	src = (char *) ptr;
	dst = (char *) new_ptr;
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	free(ptr);
	return (new_ptr);
}
