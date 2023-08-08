/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:56:26 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/08 07:11:05 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "../../libraries.h"

int		ft_strlen(const char *str);
void	ft_exit(char *str, int i);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strndup(char *str, int start, int finish);
void	ft_putstr_fd(char *s, int fd);
void	ft_print_message(char *message, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		ft_count_char_split(char const *s, char c);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, int start, int len);
int		ft_contchar(char *str, char c);

#endif
