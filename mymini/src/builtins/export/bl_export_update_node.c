/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_export_update_node.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 01:04:59 by matteo            #+#    #+#             */
/*   Updated: 2023/11/29 14:51:13 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_name_exists_so_update_value(t_node *current, char *name, char *value)
{
	char	*temp;

	if (current->value != NULL)
		free(current->value);
	current->value = ft_strdup(value);
	temp = ft_strjoin(name, "=");
	if (current->full_info != NULL)
		free(current->full_info);
	current->full_info = ft_strjoin(temp, value);
	if (temp)
		free(temp);
}

void	ft_name_exists_add_value(t_node *current, char *name, char *value)
{
	char	*temp;

	if (current->value != NULL)
		free(current->value);
	current->value = ft_strdup(value);
	temp = ft_strjoin(name, "=");
	if (current->full_info != NULL)
		free(current->full_info);
	current->full_info = ft_strjoin(temp, value);
	if (temp)
		free(temp);
}

void	ft_name_exists_no_value(t_node *current, char *name)
{
	char	*temp;

	if (current->value != NULL)
		free(current->value);
	current->value = ft_strdup("\"\"");
	temp = ft_strjoin(name, "=");
	if (current->full_info != NULL)
		free(current->full_info);
	current->full_info = ft_strjoin(temp, "\"\"");
	if (temp)
		free(temp);
}
