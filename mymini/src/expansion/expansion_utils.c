/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:06:59 by matteo            #+#    #+#             */
/*   Updated: 2023/11/21 18:00:04 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_make_sub_str_with_quotes(char *str, int *i)
{
	char	*new_substr;
	char	quote;
	int		j;

	quote = str[*i];
	j = *i + 1;
	while (str[j] != quote && str[j] != '\0')
		j++;
	new_substr = (char *) malloc(j - *i + 2);
	if (!new_substr)
		return (NULL);
	ft_strncpy(new_substr, &str[*i], j - *i + 1);
	new_substr[j - *i + 1] = '\0';
	*i = j + 1;
	return (new_substr);
}

char	*ft_make_sub_str_without_quotes(char *str, int *i)
{
	char	*new_substr;
	int		j;

	j = *i;
	while (str[j] != '\'' && str[j] != '\"' && str[j] != '\0')
		j++;
	new_substr = (char *) malloc(j - *i + 1);
	if (!new_substr)
		return (NULL);
	ft_strncpy(new_substr, &str[*i], j - *i);
	new_substr[j - *i] = '\0';
	*i = j;
	return (new_substr);
}

char	*dl_dollar_expander(char **env, char *name)
{
	char	*value_env;
	int		j;
	int		index_egual_sign;

	j = 0;
	index_egual_sign = 0;
	value_env = NULL;
	while (env[j])
	{
		if (ft_strncmp(env[j], name, ft_strlen(name)) == 0
			&& env[j][ft_strlen(name)] == '=')
		{
			index_egual_sign = ft_find_char_index_str(env[j], '=');
			value_env = ft_substr(env[j], index_egual_sign + 1,
					ft_strlen(env[j]) - index_egual_sign);
			return (value_env);
		}
		j++;
	}
	return (NULL);
}

char	*ft_replace_substring(char *str, char *sub_str, char *replace_str)
{
	char	*result;
	char	*ins;
	char	*temp;
	int		len_front;

	ins = str;
	temp = (char *) malloc(ft_strlen(str)
			+ (ft_strlen(replace_str) - ft_strlen(sub_str)) + 1);
	if (!temp)
		return (NULL);
	result = temp;
	ins = ft_strstr(str, sub_str);
	if (ins != NULL)
	{
		len_front = ins - str;
		temp = ft_memcpy(temp, str, len_front);
		temp += len_front;
		temp = ft_memcpy(temp, replace_str, ft_strlen(replace_str));
		temp += ft_strlen(replace_str);
		str += len_front + ft_strlen(sub_str);
	}
	ft_memcpy(temp, str, strlen(str) + 1);
	return (result);
}
