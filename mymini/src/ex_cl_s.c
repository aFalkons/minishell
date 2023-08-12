/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_cl_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 07:56:46 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/12 11:34:36 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ex_update_env(t_minitree *node, void *env)
{
	if (node->next)
		ex_update_env(node->next, env);
	node->env = env;
}

void	ex_po_s(t_minitree *node)
{
	char	**tmp;

	tmp = ft_matrixdup(node->env);
	node->env = tmp;
	ex_update_env(node, tmp);
}
