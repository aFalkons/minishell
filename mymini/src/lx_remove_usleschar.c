/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_remove_usleschar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:26:39 by afalconi          #+#    #+#             */
/*   Updated: 2023/09/06 09:25:59 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	lx_cont_size_quotes(t_lx_list_token *token)
{
	int				i;
	int				ret;
	char			quotes;

	quotes = 0;
	i = -1;
	ret = 0;
	while(token->str[++i])
	{
		if (token->str[i] == '\\' || token->str[i] == '\"' || token->str[i] == '\'')
		{
			if (i == 0)
				ret ++;
			else if ((token->str[i] == '\"' || token->str[i] == '\'') && token->str[i - 1] != '\\')
			{
				ret = ret + 2;
				quotes = token->str[i];
				i ++;
				while(token->str[i] != quotes && token->str[i] && token->str[i - 1] != '\\')
					i++;
			}
		}
	}
	return(ft_strlen(token->str) - ret);
}

static void	lx_real_remove(t_lx_list_token *token)
{
	char	*str;
	int		i;
	int		j;
	char	q;

	i = -1;
	j = 0;
	q = 0;
	str = ft_calloc(lx_cont_size_quotes(token), 1);
	while(token->str[++i])
	{
		if ((token->str[i] == '\"' || token->str[i] == '\'') && token->str[i - 1] != '\\')
		{
			q = token->str[i];
			i ++;
			while(token->str[i] != q && token->str[i - 1] != '\\')
			{
				if (token->str[i] == '\\' && token->str[i - 1] =='\\')
				{
					str[j] = token->str[i];
					j ++;
					i ++;
				}
			}
		}
		else
		{
			str[j] = token->str[i];
			j ++;
		}
	}
	str[j] = '\0';
	free(token->str);
	token->str = str;
}

void	lx_remove_usleschar(t_lx_list_token *token)
{
	while(token)
	{
		if (token->token == ARG)
			lx_real_remove(token);
		token = token->next;
	}
}
