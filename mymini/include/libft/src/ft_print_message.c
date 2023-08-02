/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:00:23 by misidori          #+#    #+#             */
/*   Updated: 2023/07/28 15:38:28 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_print_message(char *message, int fd)
{
	if (fd != 2)
		ft_putstr_fd(message, fd);
	else
	{
		ft_putstr_fd("\033[31m", fd);
		ft_putstr_fd(message, fd);
		ft_putstr_fd("\n\e[0m", fd);
	}
}
