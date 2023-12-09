/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:39:56 by matteo            #+#    #+#             */
/*   Updated: 2023/11/30 14:40:53 by misidori         ###   ########.fr       */
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

char	*ft_replace_dollar_with_value(t_shell_info *sh_info, char *sub_str,
	t_expansion *exp, int k)
{
	char	*new_string;

	exp->name_w_dollar = ft_substr(sub_str, exp->index_dollar_sign, k + 1);
	exp->name_var = ft_substr(sub_str, exp->index_dollar_sign + 1, k);
	exp->value_var = dl_dollar_expander(sh_info->env, exp->name_var);
	exp->len_new_value = ft_strlen(exp->value_var) - ft_strlen(exp->name_var);
	exp->temp_str = ft_strdup(sub_str);
	new_string = ft_replace_substring(exp->temp_str,
			exp->name_w_dollar, exp->value_var);
	ft_free_exp_variables(exp);
	return (new_string);
}
