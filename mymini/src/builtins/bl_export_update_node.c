/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_export_update_node.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <matteo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 01:04:59 by matteo            #+#    #+#             */
/*   Updated: 2023/10/09 17:09:01 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_name_exists_so_update_value(t_node *current, char *name, char *value)
{
	char	*temp;

	free(current->value);
	current->value = strdup(value);
	free(current->full_info);
	current->full_info = ft_strjoin(name, "=");
	temp = current->full_info;
	current->full_info = ft_strjoin(temp, value);
	free(temp);
}

void	ft_name_exists_add_value(t_node *current, char *name, char *value)
{
	char	*temp;

	current->value = strdup(value);
	current->full_info = ft_strjoin(name, "=");
	temp = current->full_info;
	current->full_info = ft_strjoin(temp, value);
	free(temp);
}

void	ft_name_exists_no_value(t_node *current, char *name)
{
	char	*temp;

	free(current->value);
	current->value = strdup("\"\"");
	free(current->full_info);
	current->full_info = ft_strjoin(name, "=");
	temp = current->full_info;
	current->full_info = ft_strjoin(temp, "\"\"");
	free(temp);
}
