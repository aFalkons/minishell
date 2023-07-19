/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:44:26 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/19 09:02:50 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t		i;
	char	*cast;

	i = -1;
	if (count == SIZE_MAX && size == SIZE_MAX)
		return (0);
	ret = malloc(count * size);
	if (!ret)
		return (0);
	cast = (char *)ret;
	while (++i < size * count)
		cast[i] = 0;
	return (ret);
}
