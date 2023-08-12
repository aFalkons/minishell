/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_ck_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:52:02 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/12 16:16:15 by afalconi         ###   ########.fr       */
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

static char	**ex_create_paths(char *path, char *cmd)
{
	char *tmp;
	char **ret;
	char **paths;
	int i;

	tmp = NULL;
	ret = NULL;
	paths = NULL;
	i = -1;
	paths = ft_split(path, ':');
	while(paths[++i])
		;
	tmp = ft_strjoin("/", cmd);
	ret = ft_calloc(8 * (i + 1), 1);
	i = -1;
	while(paths[++i])
		ret[i] = ft_strjoin(paths[i], tmp);
	free(tmp);
	return(ret);
}

static int	ex_ck_exist_cmd(char **path)
{
	int i;

	i = -1;
	while(path[++i])
	{
		if (access(path[i], X_OK) == 0)
			return(1);
	}
	return(-1);
}

char	*ex_ck_cmd(struct s_lx_list_token *cmd,  struct s_minitree *node)
{
	char	*path;
	char	**paths_cmd;

	path = NULL;
	if (access(cmd->str, X_OK) == 0)
		return(ft_strdup(cmd->str));
	path = ex_create_path(node->env);
	paths_cmd = ex_create_paths(path, cmd->str);
	if (ex_ck_exist_cmd(paths_cmd) == -1)
		node->exit_status = -1;
	printf("%d\n", node->exit_status);
	return(NULL);
}
