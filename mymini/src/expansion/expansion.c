/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:46:00 by matteo            #+#    #+#             */
/*   Updated: 2023/11/21 22:10:53 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_expansion(t_shell_info *sh_info, t_lx_list_token *token)
{
	char	**sub_strs;
	int		i;

	while (token)
	{
		i = -1;
		if (token->token == ARG)
		{
			sub_strs = ft_get_sub_str(token->str);
			while (sub_strs[++i])
				sub_strs[i] = ft_check_type_quotes(sh_info, sub_strs[i]);
			ft_expand_dollar_in_input_str(sub_strs, token);
			ft_free_array(sub_strs);
		}
		token = token->next;
	}
	return (0);
}

char	**ft_get_sub_str(char *str)
{
	char	**sub_strs;
	int		index;
	int		*i;
	int		k;

	sub_strs = (char **) malloc(sizeof(char *) * (strlen(str) + 1));
	if (!sub_strs)
		return (NULL);
	index = 0;
	i = &index;
	k = 0;
	while (str[*i])
	{
		if (str[*i] == '\'' || str[*i] == '\"')
			sub_strs[k] = ft_make_sub_str_with_quotes(str, i);
		else
			sub_strs[k] = ft_make_sub_str_without_quotes(str, i);
		k++;
	}
	sub_strs = ft_realloc(sub_strs, sizeof(char *) * (k + 1));
	sub_strs[k] = NULL;
	return (sub_strs);
}

char	*ft_check_type_quotes(t_shell_info *sh_info, char *str)
{
	int		n_single_quote;
	int		n_double_quotes;
	int		n_dollar_sign;

	n_single_quote = ft_count_char(str, '\'');
	n_double_quotes = ft_count_char(str, '\"');
	n_dollar_sign = ft_count_char(str, '$');
	if ((n_single_quote + n_double_quotes == 0) && n_dollar_sign > 0)
	{
		str = ft_dollar_sign_without_quotes(sh_info, str);
	}
	else if ((n_double_quotes > 0 && n_single_quote == 0) && n_dollar_sign > 0)
	{
		str = ft_work_on_double_quotes(sh_info, str);
	}
	else if ((n_double_quotes > 0 && n_single_quote > 0) && n_dollar_sign > 0)
	{
		str = ft_work_on_all_quotes(sh_info, str);
	}
	return (str);
}

void	ft_expand_dollar_in_input_str(char **sub_strs, t_lx_list_token *token)
{
	char	*temp;
	int		i;

	i = 1;
	while (sub_strs[i])
	{
		temp = ft_strdup(sub_strs[0]);
		free(sub_strs[0]);
		sub_strs[0] = ft_strjoin(temp, sub_strs[i]);
		free(temp);
		i++;
	}
	free(token->str);
	token->str = ft_strdup(sub_strs[0]);
}
