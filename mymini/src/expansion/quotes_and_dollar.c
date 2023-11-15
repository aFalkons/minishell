/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_and_dollar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <matteo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:39:56 by matteo            #+#    #+#             */
/*   Updated: 2023/11/15 17:42:20 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_exp_variables(t_expansion	*exp)
{
	if (exp->name_var != NULL)
		free(exp->name_var);
	if (exp->temp_str != NULL)
		free(exp->temp_str);
	if (exp->name_w_dollar != NULL)
		free(exp->name_w_dollar);
	if (exp->value_var != NULL)
		free(exp->value_var);
}

void	ft_replace_dollar_with_value(t_shell_info *sh_info, char **sub_str,
	t_expansion *exp, int k)
{
	exp->name_w_dollar = ft_substr(*sub_str, exp->index_dollar_sign, k + 1);
	exp->name_var = ft_substr(*sub_str, exp->index_dollar_sign + 1, k);
	exp->value_var = dl_dollar_expander(sh_info->env, exp->name_var);
	exp->temp_str = ft_strdup(*sub_str);
	*sub_str = ft_replace_substring(exp->temp_str,
			exp->name_w_dollar, exp->value_var);
	ft_free_exp_variables(exp);
}

char	*ft_dollar_sign_without_quotes(t_shell_info *sh_info, char *sub_str)
{
	t_expansion	exp;
	int			i;
	int			k;
	int			j;

	exp.index_dollar_sign = ft_find_char_index_str(sub_str, '$');
	i = exp.index_dollar_sign;
	exp.n_dollar_sign = ft_count_char(sub_str, '$');
	j = -1;
	while (++j < exp.n_dollar_sign)
	{
		k = 0;
		i++;
		while (sub_str[i] && sub_str[i] != ' ' && sub_str[i] != '\t')
		{
			i++;
			k++;
		}
		ft_replace_dollar_with_value(sh_info, &sub_str, &exp, k);
		i = ft_find_index_next_char(sub_str, '$', i);
		exp.index_dollar_sign = i;
	}
	return (sub_str);
}

char	*ft_work_on_double_quotes(t_shell_info *sh_info, char *sub_str)
{
	t_expansion	exp;
	int			i;
	int			k;
	int			j;

	exp.index_dollar_sign = ft_find_char_index_str(sub_str, '$');
	i = exp.index_dollar_sign;
	exp.n_dollar_sign = ft_count_char(sub_str, '$');
	j = -1;
	while (++j < exp.n_dollar_sign)
	{
		k = 0;
		i++;
		while (sub_str[i] && (sub_str[i] != ' ' && sub_str[i] != '\t'
				&& sub_str[i] != '\"' && sub_str[i] != '\''))
		{
			i++;
			k++;
		}
		ft_replace_dollar_with_value(sh_info, &sub_str, &exp, k);
		i = ft_find_index_next_char(sub_str, '$', i);
		exp.index_dollar_sign = i;
	}
	return (sub_str);
}

char	*ft_work_on_all_quotes(t_shell_info *sh_info, char *str)
{
	char	*temp;
	int		index_single_quote;
	int		index_double_qoutes;

	index_single_quote = ft_find_char_index_str(str, '\'');
	index_double_qoutes = ft_find_char_index_str(str, '\"');
	if (index_single_quote > index_double_qoutes)
	{
		temp = ft_strdup(str);
		free(str);
		str = ft_work_on_double_quotes(sh_info, temp);
		free(temp);
	}
	return (str);
}
