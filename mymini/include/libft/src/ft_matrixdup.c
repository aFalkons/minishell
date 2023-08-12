/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 08:01:08 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/12 08:06:34 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	**ft_matrixdup(char **matrix)
{
	int		i;
	char	**ret;

	i = -1;
	ret = ft_calloc(sizeof(matrix), 1);
	while (matrix[++i])
		ret[i] = ft_strdup(matrix[i]);
	ret[i] = NULL;
	return(ret);
}
