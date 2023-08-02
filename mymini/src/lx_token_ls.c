/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_token_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:54:47 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/02 19:00:29 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// con questa vado a inserire un nodo differenzaiando se e una pipe "|" o un or "||"
static void	lx_insert_OR_PIPE(t_shell_info *sh_info, int *i)
{
	lx_create_or_insert(sh_info);
	if (sh_info->input[*i + 1] == '|')
	{
		sh_info->lx_ls_token->token = OR;
		sh_info->lx_ls_token->str = "||";
		*i = *i + 2;
	}
	else
	{
		*i = *i + 1;
		sh_info->lx_ls_token->token = PIPE;
		sh_info->lx_ls_token->str = "|";
	}
}

// qui vado a inserire un nodo se trovo un and "&&"
static void	lx_insert_AND(t_shell_info *sh_info, int *i)
{
	if (sh_info->input[*i + 1] == '&')
	{
		lx_create_or_insert(sh_info);
		sh_info->lx_ls_token->token = AND;
		sh_info->lx_ls_token->str = "&&";
		*i = *i + 2;
	}
}

// con questa vado a inserire un nodo differenzaiando se e output ">" o append ">>"
static void	lx_insert_OUT_APP(t_shell_info *sh_info, int *i)
{
	int	finish;
	int	start;

	start = *i;
	finish = 0;
	lx_create_or_insert(sh_info);
	if (sh_info->input[*i + 1] == '>')
	{
		*i = *i + 1;
		sh_info->lx_ls_token->token = APP;
	}
	else
		sh_info->lx_ls_token->token = OUT;
	finish = *i + 1;
	while (sh_info->input[finish] == ' ')
		finish ++;
	while (sh_info->input[finish] != ' ')
	{
		if (!(sh_info->input[finish]))
			break ;
		finish++;
	}
	sh_info->lx_ls_token->str = ft_strndup(sh_info->input, start, finish);
	*i = finish;
}

// con questa vado a inserire un nodo differenzaiando se e input "<" o heredoc "<<"
static void	lx_insert_INP_HDOC(t_shell_info *sh_info, int *i)
{
	int	finish;
	int	start;

	finish = *i + 1;
	start = *i;
	lx_create_or_insert(sh_info);
	if (sh_info->input[*i + 1] == '<')
	{
		*i = *i + 1;
		sh_info->lx_ls_token->token = HDOC;
	}
	else
		sh_info->lx_ls_token->token = INP;
	while (sh_info->input[finish] == ' ')
		finish ++;
	while (sh_info->input[finish] != ' ')
		finish++;
	sh_info->lx_ls_token->str = ft_strndup(sh_info->input, start, finish);

}
// con questa funzione mi vado a creare una lista per sapere se il coomando iserito e concettualmente giusto
void	lx_list_token(t_shell_info *sh_info)
{
	int	i;

	i = -1;
	while(sh_info->input[++i])
	{
		if (sh_info->input[i] == '&')
			lx_insert_AND(sh_info, &i);
		else if (sh_info->input[i] == '|')
			lx_insert_OR_PIPE(sh_info, &i);
		else if (sh_info->input[i] == '>')
			lx_insert_OUT_APP(sh_info, &i);
		else if (sh_info->input[i] == '<')
			lx_insert_INP_HDOC(sh_info, &i);
		else if (sh_info->input[i] != ' ')
			lx_insert_CMD_ARG(sh_info, &i);
	}
	sh_info->lx_ls_token = sh_info->lx_ls_token_h;
	while(sh_info->lx_ls_token->next != NULL)
	{
		printf("%s -- %c\n", sh_info->lx_ls_token->str, sh_info->lx_ls_token->token);
		sh_info->lx_ls_token = sh_info->lx_ls_token->next;
	}
}
