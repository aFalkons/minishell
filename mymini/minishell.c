/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:09:31 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/17 00:59:19 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	ac = 0;
	av = NULL;
	env = NULL;
	int	i;
	char str[10];
	str[0] = 'a';
	str[1] = 'a';
	str[2] = 'a';
	str[3] = 'a';
	str[4] = 'a';
	str[5] = 'a';
	str[6] = 'a';
	str[7] = 'a';
	str[8] = 'a';
	str[9] = '\0';
	i = ft_strlen(str);
	printf("%d\n", i);
	return (0);
}
