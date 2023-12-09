/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_char_index_str.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 00:19:32 by misidori          #+#    #+#             */
/*   Updated: 2023/12/01 19:24:02 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_char_index_str(char *str, char c)
{
	int	i;

	i = 0;
	if (!str || !c)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
