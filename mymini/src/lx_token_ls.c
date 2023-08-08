/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_token_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:54:47 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/07 22:43:22 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// con questa vado a inserire un nodo differenzaiando se e una pipe "|" o un or "||"
static void	lx_insert_OR_PIPE(t_shell_info *sh_info, int *i)
{
	if (sh_info->input[*i + 1] == '|')
	{
		lx_create_or_insert(sh_info, ft_strdup("||"), OR);
		*i = *i + 2;
	}
	else
	{
		lx_create_or_insert(sh_info,  ft_strdup("|"), PIPE);
		*i = *i + 1;
	}
	if (sh_info->input[*i] != ' ')
		*i = *i - 1;
}

// qui vado a inserire un nodo se trovo un and "&&"
static void	lx_insert_AND(t_shell_info *sh_info, int *i)
{
	if (sh_info->input[*i + 1] == '&')
	{
		lx_create_or_insert(sh_info, ft_strdup("&&"), AND);
		*i = *i + 2;
		if (sh_info->input[*i] != ' ')
			*i = *i - 1;
	}
}

// con questa vado a inserire un nodo differenzaiando se e output ">" o append ">>"
static void	lx_insert_OUT_APP(t_shell_info *sh_info, int *i)
{
	int		finish;
	int		start;
	char	token;

	finish = *i + 1;
	start = *i;
	if (sh_info->input[*i + 1] == '>')
	{
		*i = *i + 1;
		token = APP;
	}
	else
		token = OUT;
	while (sh_info->input[finish] == ' ')
		finish ++;
	while (sh_info->input[finish] != ' ')
	{
		if (sh_info->input[finish] == PIPE || sh_info->input[finish] == INP || sh_info->input[finish] == OUT || sh_info->input[finish] == '&' || sh_info->input[finish] == 0)
			break ;
		finish++;
	}
	lx_create_or_insert(sh_info, ft_strndup(sh_info->input, start, finish), token);
	*i = finish;
}

// con questa vado a inserire un nodo differenzaiando se e input "<" o heredoc "<<"
static void	lx_insert_INP_HDOC(t_shell_info *sh_info, int *i)
{
	int		finish;
	int		start;
	char	token;

	finish = *i + 1;
	start = *i;
	if (sh_info->input[*i + 1] == '<')
	{
		*i = *i + 1;
		token = HDOC;
	}
	else
		token = INP;
	while (sh_info->input[finish] == ' ')
		finish ++;
	while (sh_info->input[finish] != ' ')
	{
		if (sh_info->input[finish] == PIPE || sh_info->input[finish] == INP || sh_info->input[finish] == OUT || sh_info->input[finish] == '&' || sh_info->input[finish] == 0)
			break ;
		finish++;
	}
	lx_create_or_insert(sh_info, ft_strndup(sh_info->input, start, finish), token);
	*i = finish;
}

static void	print_list(t_shell_info *sh_info)
{
	t_list_token *tmp;


	tmp = sh_info->lx_ls_token_h;
	while(tmp != NULL)
	{
		printf("%s\n", tmp->str);
		printf("%c\n", tmp->token);
		tmp = tmp->next;
	}
}
// con questa funzione mi vado a creare una lista per sapere se il coomando iserito e concettualmente giusto
void	lx_list_token(t_shell_info *sh_info)
{
	int	i;

	i = -1;
	while(sh_info->input[++i])
	{
		lx_skip_space(sh_info, &i);
		if (sh_info->input[i] == '&')
			lx_insert_AND(sh_info, &i);
		else if (sh_info->input[i] == '|')
			lx_insert_OR_PIPE(sh_info, &i);
		else if (sh_info->input[i] == '>')
			lx_insert_OUT_APP(sh_info, &i);
		else if (sh_info->input[i] == '<')
			lx_insert_INP_HDOC(sh_info, &i);
		else if (sh_info->input[i] == '(')
			lx_create_or_insert(sh_info, ft_strdup("("), OP_S);
		else if (sh_info->input[i] == ')')
			lx_create_or_insert(sh_info, ft_strdup(")"), CL_S);
		else if (sh_info->input[i] != ' ')
			lx_insert_CMD_ARG(sh_info, &i);
	}
	print_list(sh_info);
	sh_info->lx_ls_token = sh_info->lx_ls_token_h;
	ck_list_token(sh_info);
}
