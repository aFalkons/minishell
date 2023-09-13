/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:37:01 by afalconi          #+#    #+#             */
/*   Updated: 2023/09/13 15:38:59 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	print_list(t_lx_list_token *list)
{
	while (list != NULL)
	{
		printf("--%s--\n", list->str);
		printf("%c\n", list->token);
		list = list->next;
	}
}
