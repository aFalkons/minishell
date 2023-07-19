/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:56:26 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/19 09:14:33 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <termios.h>
# include <sys/ttydefaults.h>
# include <readline/readline.h>
# include <readline/history.h>

size_t	ft_strlen(char *str);
void	ft_exit(char *str, int i);
void	*ft_calloc(size_t count, size_t size);

#endif
