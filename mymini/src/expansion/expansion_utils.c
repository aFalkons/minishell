/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <matteo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:06:59 by matteo            #+#    #+#             */
/*   Updated: 2023/11/15 17:41:32 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
//	free(temp);
	return (result);
}
