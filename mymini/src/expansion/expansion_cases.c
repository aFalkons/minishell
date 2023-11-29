/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:53:42 by misidori          #+#    #+#             */
/*   Updated: 2023/11/29 16:02:24 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_dollar_var(t_expansion *exp, char *sub_str)
{
	exp->index_dollar_sign = ft_find_char_index_str(sub_str, '$');
	exp->i = exp->index_dollar_sign;
	exp->j = -1;
	exp->n_dollar_sign = ft_count_char(sub_str, '$');
}

char	*ft_dollar_sign_without_quotes(t_shell_info *sh_info, char *sub_str)
{
	t_expansion	exp;
	char		*temp;

	ft_init_dollar_var(&exp, sub_str);
	while (++exp.j < exp.n_dollar_sign)
	{
		exp.k = 0;
		exp.i++;
		while (sub_str[exp.i] && ft_isalnum_char(sub_str[exp.i]) == true)
		{
			exp.i++;
			exp.k++;
		}
		temp = ft_strdup(sub_str);
		free(sub_str);
		sub_str = ft_replace_dollar_with_value(sh_info, temp, &exp, exp.k);
		free(temp);
		exp.i = ft_find_index_next_char(sub_str, '$',
				exp.len_new_value + exp.index_dollar_sign);
		exp.index_dollar_sign = exp.i;
	}
	return (sub_str);
}

char	*ft_work_on_double_quotes(t_shell_info *sh_info, char *sub_str)
{
	t_expansion	exp;
	char		*temp;

	ft_init_dollar_var(&exp, sub_str);
	while (++exp.j < exp.n_dollar_sign)
	{
		exp.k = 0;
		exp.i++;
		while (sub_str[exp.i] && ft_isalnum_char(sub_str[exp.i]) == true
			&& sub_str[exp.i] != '\"' && sub_str[exp.i] != '\'')
		{
			exp.i++;
			exp.k++;
		}
		temp = ft_strdup(sub_str);
		free(sub_str);
		sub_str = ft_replace_dollar_with_value(sh_info, temp, &exp, exp.k);
		free(temp);
		exp.i = ft_find_index_next_char(sub_str, '$',
				exp.len_new_value + exp.index_dollar_sign);
		exp.index_dollar_sign = exp.i;
	}
	return (sub_str);
}

char	*ft_work_on_all_quotes(t_shell_info *sh_info, char *str)
{
	int		index_single_quote;
	int		index_double_qoutes;

	index_single_quote = ft_find_char_index_str(str, '\'');
	index_double_qoutes = ft_find_char_index_str(str, '\"');
	if (index_single_quote > index_double_qoutes)
	{
		str = ft_work_on_double_quotes(sh_info, str);
	}
	return (str);
}
