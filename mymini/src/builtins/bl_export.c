/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:17:08 by matteo            #+#    #+#             */
/*   Updated: 2023/10/11 19:03:18 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	bl_export(t_shell_info *sh_info, char **env, int argc, char **split)
{
	int		i;
	int		index_egual_sign;
	int		return_value;

	i = 0;
	index_egual_sign = 0;
	return_value = 1;
	if (argc == 1)
	{
		ft_sort_list(&sh_info->var->head);
		ft_print_list(sh_info->var);
		return_value = 1;
	}
	if (ft_check_exclamation_mark(split) == -1)												// SE C'É UN PUNTO ESCLAMATIVO - STAMPA MSG ERRORE
		return_value = -1;
	while (split[++i])
	{
		index_egual_sign = ft_find_char_index_str(split[i], '=');
		if (index_egual_sign > -1)															// SE C'è IL SEGNO DELL'UGUALE
		{
			if (ft_egual_sign_exists(sh_info, env, split[i],
					index_egual_sign) == -1)
				return_value = -1;
		}
		else																				// SE NON C'É IL SEGNO DELL'UGUALE
		{
			if (ft_add_arg_without_egual_sign(sh_info, split[i]) == -1)
				return_value = -1;
		}
	}
	return (return_value);
}

int	ft_egual_sign_exists(t_shell_info *sh_info, char **env, char *arg,
	int index_egual_sign)
{
	int		return_value;
	char	*value;

	if (arg[0] == '=')
	{
		printf("minishell: export: `%s': not a valid identifier\n", arg);
		return (-1);
	}
	return_value = 1;
	value = ft_substr(arg, (index_egual_sign + 1), ft_strlen(arg));
	if (arg[index_egual_sign - 1] == '+')													// SE C'è IL "+="
	{
		if (ft_arg_has_plus_sign_and_value(sh_info, env, arg, value) == -1)
			return_value = -1;
	}
	else if (arg[index_egual_sign - 1] == '+' && !arg[index_egual_sign + 1]) 				// ES. "CIAO+= ", NON FA NULLA
	{
		if (ft_arg_has_plus_sign_and_no_value(sh_info, env, arg) == -1)
			return_value = -1;
	}
	else 																					// SE C'è IL SEGNO DELL'UGUALE
	{
		if (ft_arg_has_egual_sign(sh_info, env, arg, value) == -1)
			return_value = -1;
	}
	free(value);
	return (return_value);
}

bool	ft_check_name_is_correct(char *name)
{
	int	i;

	i = 0;
	while (name[i])
	{
		if ((name[i] >= 'a' && name[i] <= 'z')
			|| (name[i] >= 'A' && name[i] <= 'Z')
			|| (name[i] >= '0' && name[i] <= '9') || (name[i] == '_'))
		{
			i++;
		}
		else
		{
			return (false);
		}
	}
	return (true);
}

int	ft_arg_has_plus_sign_and_value(t_shell_info *sh_info, char **env,
	char *arg, char *value)
{
	char	*name;
	int		index_egual_sign;
	int		return_value;

	return_value = 1;
	index_egual_sign = ft_find_char_index_str(arg, '=');
	name = ft_substr(arg, 0, index_egual_sign - 1);
	if (ft_check_name_is_correct(name) == false || ft_isdigit(name[0]) == true)
	{
		printf("minishell: export: `%s': not a valid identifier\n", arg);
		return_value = -1;
	}
	if (return_value != -1)
	{
		if (ft_check_if_variable_name_exists(sh_info, name) == 1)		// SE ESITE GIÁ LA VARIABILE, ES. "CIAO+=MAMMA", CONCATENA CON IL VALORE PRECEDENTE DI CIAO
		{
			ft_attach_string_to_array(env, name, value);
			ft_attach_string_to_list(sh_info, name, value);
		}
		else															// SE NON ESITE GIÁ LA VARIABILE, ES. "CIAO+=MAMMA", CREA NUOVA VARIABILE
		{
			ft_add_element_to_array(env, name, value);
			ft_add_or_update_node_in_list(&sh_info->var->node, name, value);
		}
	}
	free(name);
	return (return_value);
}

int	ft_arg_has_plus_sign_and_no_value(t_shell_info *sh_info,
	char **env, char *arg)
{
	int		index_egual_sign;
	int		return_value;
	char	*name;

	index_egual_sign = ft_find_char_index_str(arg, '=');
	return_value = 1;
	name = ft_substr(arg, 0, index_egual_sign);
	if (ft_check_name_is_correct(name) == false || ft_isdigit(name[0]) == true)
	{
		printf("minishell: export: `%s': not a valid identifier\n", arg);
		return_value = -1;
	}
	if (return_value != -1)
	{
		if (ft_check_if_variable_name_exists(sh_info, name) == 1)			// SE LA VARIABILE ESISTE E HA UN VALORE, ES. "CIAO+= ", NON FA NULLA
		{
			return (1);
		}
		else if (ft_check_if_variable_name_exists(sh_info, name) == 2)		// SE LA VARIABILE ESISTE MA NON HA VALORE, CREA LA NUOVA VARIABLE export-> CIAO="" / env CIAO=
		{
			ft_add_element_to_array(env, name, NULL);
			ft_add_or_update_node_in_list(&sh_info->var->node, name, NULL);
		}
		else																// SE LA VARIABILE NON ESISTE, ES. "CIAO+= ", CREA LA NUOVA VARIABLE export-> CIAO="" / env CIAO=
		{
			ft_add_element_to_array(env, name, NULL);
			ft_add_or_update_node_in_list(&sh_info->var->node, name, NULL);
		}
	}
	free(name);
	return (return_value);
}

int	ft_arg_has_egual_sign(t_shell_info *sh_info, char **env,
	char *arg, char *value)
{
	int		return_value;
	int		index_egual_sign;
	char	*name;

	return_value = 1;
	index_egual_sign = ft_find_char_index_str(arg, '=');
	name = ft_substr(arg, 0, index_egual_sign);
	if (ft_check_name_is_correct(name) == false || ft_isdigit(name[0]) == true)
	{
		printf("minishell: export: `%s': not a valid identifier\n", arg);
		return_value = -1;
	}
	if (return_value != -1)
	{
		if (ft_check_if_variable_name_exists(sh_info, name) == 1			// SE ESITE GIÁ LA VARIABILE
			|| ft_check_if_variable_name_exists(sh_info, name) == 2)		// ES. "CIAO=MAMMA", SOVRASCRIVE IL VALORE PRECEDENTE DI CIAO
		{
			ft_edit_value_in_array(sh_info, env, name, value);
			ft_add_or_update_node_in_list(&sh_info->var->head, name, value);
		}
		else												// SE NON ESITE GIÁ LA VARIABILE, ES. "CIAO=MAMMA", SOVRASCRIVE IL VALORE PRECEDENTE DI CIAO
		{
			ft_add_element_to_array(env, name, value);
			ft_add_or_update_node_in_list(&sh_info->var->head, name, value);
		}
	}
	free(name);
	return (return_value);
}
