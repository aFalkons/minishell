/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_ck_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:52:02 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/12 13:10:15 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ex_create_path(char **env)
{
	int	i;

	i = -1;
	while(env[++i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' && env[i][3] == 'H')
			return(env[i]);
	}
	return(NULL);
}

char	*ex_ck_cmd(struct s_lx_list_token *cmd,  struct s_minitree *node)
{
	char	*path;
	char	**paths;

	path = NULL;
	path = ex_create_path(node->env)
	// paths = ft_split(path, '');
}
