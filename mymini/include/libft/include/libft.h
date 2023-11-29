/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:56:26 by afalconi          #+#    #+#             */
/*   Updated: 2023/11/29 17:16:03 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "../../libraries.h"
# include "../../structures.h"

int		ft_strlen(const char *str);
void	ft_exit(int fd, char *str, int num_error);
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
int		ft_count_char(char *str, char c);
char	**ft_matrixdup(char **matrix);
void	print_list(t_lx_list_token *list);
void	print_tree(t_minitree *tree_node, t_minitree *tree_node_h, int i);
int		ft_isnumeric(char c);
int		ft_atoi(char *str);
void	ft_for_debug(char *str);
int		ft_print_array(char **array_strings);
int		ft_strcmp(const char *str1, const char *str2);
bool	ft_isdigit(int num);
bool	ft_isalnum_char(int num);
bool	ft_isalnum_str(char *str);
bool	ft_isascii_char(int num);
bool	ft_isascii_str(char *str);
char	*ft_strchr(const char *s, int c);
int		ft_count_char_array(char const **array, char c);
void	ft_remove_char_in_str(char *str, char c);
bool	ft_isdigit_str(char *str);
int		ft_get_size_array(char **array);
int		ft_find_index_next_char(char *str, char c, int i);
char	*ft_strncpy(char *dest, const char *src, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strstr(const char *haystack, const char *needle);
void	*ft_realloc(void *ptr, size_t size);
char	**ft_copy_array(char **original_array, int size_array);
int		ft_find_char_index_str(char *str, char c);
int		ft_find_char_array(char **array, char c);
void	ft_swap_strings(char **a, char **b);
char	**ft_add_string(char **array, int *size, const char *string);
int 	ft_cmp_len_and_str(char *str1, char *str2, int len);

#endif
