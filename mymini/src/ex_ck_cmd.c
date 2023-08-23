/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_ck_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:52:02 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/21 13:04:49 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ex_create_path(char **env)
{
	int	i;

	i = -1;
	printf("--%p\n", env[0][0]);
	printf("GGGG\n");
	while(env[++i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' && env[i][3] == 'H')
			return(ft_strdup(env[i]));
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
	i = -1;
	while(paths[++i])
		free(paths[i]);
	free(paths);
	return(ret);
}

static int	ex_ck_exist_cmd(char **path)
{
	int i;

	i = -1;
	while(path[++i])
	{
		if (access(path[i], X_OK) == 0)
			return(i);
	}
	return(-1);
}

char	*ex_ck_cmd(struct s_lx_list_token *cmd,  struct s_minitree *node)
{
	char	*path;
	char	**paths_cmd;
	int		pos;
	int		i;

	path = NULL;
	i = -1;
	if (access(cmd->str, X_OK) == 0)
		return(ft_strdup(cmd->str));
	path = ex_create_path(node->env);
	paths_cmd = ex_create_paths(path, cmd->str);
	free(path);
	pos = ex_ck_exist_cmd(paths_cmd);
	if (pos == -1)
	{
		node->exit_status = -1;
		while(paths_cmd[++i])
			free(paths_cmd[i]);
		free(paths_cmd);
		return(NULL);
	}
	while(paths_cmd[++i] && paths_cmd[i] != paths_cmd[pos])
		free(paths_cmd[i]);
	free(paths_cmd);
	return(paths_cmd[pos]);
}
