/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_token_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:54:47 by afalconi          #+#    #+#             */
/*   Updated: 2023/09/06 09:20:04 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// con questa vado a inserire un nodo differenzaiando
// se e una pipe "|" o un or "||"
static void	lx_insert_or_pipe(t_shell_info *sh_info, int *i)
{
	if (sh_info->input[*i + 1] == '|')
	{
		lx_create_or_insert(sh_info, ft_strdup("||"), OR);
		*i = *i + 2;
	}
	else
	{
		lx_create_or_insert(sh_info, ft_strdup("|"), PIPE);
		*i = *i + 1;
	}
	if (sh_info->input[*i] != ' ')
		*i = *i - 1;
}

// qui vado a inserire un nodo se trovo un and "&&"
static void	lx_insert_and(t_shell_info *sh_info, int *i)
{
	if (sh_info->input[*i + 1] == '&')
	{
		lx_create_or_insert(sh_info, ft_strdup("&&"), AND);
		*i = *i + 2;
		if (sh_info->input[*i] != ' ')
			*i = *i - 1;
	}
}

// con questa vado a inserire un nodo
// differenzaiando se e output ">" o append ">>"
void	lx_insert_out_app(t_shell_info *sh_info, int *i)
{
	int		fi;
	int		st;
	char	token;

	fi = *i + 1;
	st = *i;
	while(ft_isnumeric(sh_info->input[st - 1]))
		st --;
	if (sh_info->input[*i + 1] == '>')
	{
		*i = *i + 1;
		fi = *i;
		token = APP;
	}
	else
		token = OUT;
	fi ++;
	while (sh_info->input[fi] == ' ')
		fi ++;
	while (sh_info->input[fi] != ' ')
	{
		if (sh_info->input[fi] == PIPE || sh_info->input[fi] == INP
			|| sh_info->input[fi] == OUT || sh_info->input[fi] == '&'
			|| sh_info->input[fi] == 0 || sh_info->input[fi] == OP_S || sh_info->input[fi] == CL_S)
			break ;
		fi++;
	}
	lx_create_or_insert(sh_info, ft_strndup(sh_info->input, st, fi), token);
	fi --;
	*i = fi;
}

// con questa vado a inserire un nodo
//  differenzaiando se e input "<" o heredoc "<<"
void	lx_insert_inp_hdoc(t_shell_info *sh_info, int *i)
{
	int		fi;
	int		st;
	char	token;

	fi = *i + 1;
	st = *i;
	while(ft_isnumeric(sh_info->input[st - 1]))
		st --;
	if (sh_info->input[*i + 1] == '<')
	{
		*i = *i + 1;
		fi = *i;
		token = HDOC;
	}
	else
		token = INP;
	fi ++;
	while (sh_info->input[fi] == ' ')
		fi ++;
	while (sh_info->input[fi] != ' ')
	{
		if (sh_info->input[fi] == PIPE || sh_info->input[fi] == INP
			|| sh_info->input[fi] == OUT || sh_info->input[fi] == '&'
			|| sh_info->input[fi] == 0 || sh_info->input[fi] == OP_S || sh_info->input[fi] == CL_S)
			break ;
		fi++;
	}
	lx_create_or_insert(sh_info, ft_strndup(sh_info->input, st, fi), token);
	fi --;
	*i = fi;
}

void	lx_list_token(t_shell_info *sh_info)
{
	int	i;

	i = -1;
	while (sh_info->input[++i])
	{
		lx_skip_space(sh_info, &i);
		if (sh_info->input[i] == '&')
			lx_insert_and(sh_info, &i);
		else if (sh_info->input[i] == '|')
			lx_insert_or_pipe(sh_info, &i);
		else if (sh_info->input[i] == '>')
			lx_insert_out_app(sh_info, &i);
		else if (sh_info->input[i] == '<')
			lx_insert_inp_hdoc(sh_info, &i);
		else if (sh_info->input[i] == '(')
			lx_create_or_insert(sh_info, ft_strdup("("), OP_S);
		else if (sh_info->input[i] == ')')
			lx_create_or_insert(sh_info, ft_strdup(")"), CL_S);
		else if (sh_info->input[i] != ' ' && sh_info->input[i] != '\0')
			lx_insert_cmd_arg(sh_info, &i);
	}
	sh_info->lx_ls_token = sh_info->lx_ls_token_h;
	lx_remove_usleschar(sh_info->lx_ls_token_h);

	lx_set_redirection(sh_info->lx_ls_token_h);
	lx_ck_list_token(sh_info);
}
