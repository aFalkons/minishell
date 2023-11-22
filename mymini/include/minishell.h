/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:16:57 by afalconi          #+#    #+#             */
/*   Updated: 2023/11/22 20:43:36 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/include/libft.h"
# include "./libraries.h"
# include "./structures.h"

# define AND	0b01000001
# define OR		0b01000010
# define PIPE	'|'
# define CMD	0b01000011
# define ARG	0b01000100
# define INP	'<'
# define HDOC	0b01000101
# define OUT	'>'
# define APP	0b01000110
# define OP_S	'('
# define CL_S	')'

extern int	g_for_sig;

void				ft_check_args(int argc, char **argv);
void				ft_init_variables(char **env, t_shell_info *sh_info);
void				ft_check_lexical_error(t_shell_info *sh_info);
void				ft_init_var_newcmd(t_shell_info *sh_info, char **env);
void				ping(void);
void				ck_tree_error(t_minitree *node);

/*	lexical	*/
void				ft_lexical(t_shell_info *sh_info);
void				lx_list_token(t_shell_info *sh_info);
void				lx_create_or_insert(t_shell_info *sh_info,
						char *str, char token);
void				lx_insert_cmd_arg(t_shell_info *sh_info, int *i);
void				lx_check_quotes(t_shell_info *sh_info, int *i);
void				lx_free_ls(t_shell_info *sh_info, int flag);
void				lx_skip_space(t_shell_info *sh_info, int *i);
void				lx_ck_list_token(t_shell_info *sh_info);
void				lx_remove_usleschar(t_lx_list_token *token);
void				lx_insert_inp_hdoc(t_shell_info *sh_info, int *i);
void				lx_insert_out_app(t_shell_info *sh_info, int *i);
void				lx_set_redirection(struct s_lx_list_token *token_list);
void				lx_free_and_join(char *to_join, char *to_free);
void				lx_ck_is_empty(t_shell_info *sh_info);
void				lx_add_redi_arg(t_shell_info *sh_info, char **str,
						int *fi, int *st);

/*	parser	*/
void				ft_parser(t_shell_info *sh_info,
						struct s_minitree *tree_node);
void				ps_recursiv_tree(t_shell_info *sh_info,
						struct s_minitree *tree_node);
void				ps_free_tree_recursiv(struct s_minitree *tree_node);
struct s_minitree	*ps_create_or_insert(t_shell_info *sh_info);
void				ps_redirection_setup(t_minitree *node, t_minitree *node_h,
						t_shell_info *sh_info);
int					ps_handler_hdoc(t_list_redirection *hdoc,
						t_shell_info *sh_info);
void				ps_set_struct_pipe(t_minitree *last, t_minitree *first,
						t_list_redirection *redire_list_h, t_minitree *node_h);
int					ps_file_befor_token(char *str);

/*	executor	*/
void				ft_executor(t_shell_info *sh_info);
int					ex_cmd(struct s_lx_list_token *cmd,
						struct s_lx_list_token *arg, struct s_minitree *node,
						t_shell_info *sh_info);
void				ex_cl_s(t_minitree *node);
char				*ex_ck_cmd(struct s_lx_list_token *cmd,
						struct s_minitree *node);
void				ex_out(struct s_list_redirection *redire, int flag);
void				ex_real_esecution(char *path_cmd,
						char **arr_cmd_arg, struct s_minitree *node,
						t_shell_info *sh_info);
void				ex_ck_redirection(t_minitree *node,
						t_shell_info *sh_info, int *exit_stat);
void				ex_app(struct s_list_redirection *redire, int flag);
int					ex_inp(struct s_list_redirection *redire,
						int flag, int *exit_stat);
void				ex_pipe(t_minitree *node, t_shell_info *sh_info);
void				ex_hdoc(struct s_list_redirection *redire, int flag);
void				ex_all_node(t_minitree *node, t_minitree *node_h,
						t_shell_info *sh_info, int *exit_stat);
/*	bultins.c	*/

int					bl_ck_builtins(int *exit, char **arr_cmd_arg, char **env,
						t_shell_info *sh_info);
int					bl_is_builtins(char *cmd);

/*	BL_CD_UTILS.C		*/

char				**ft_get_list_files(t_program *program);
char				*ft_get_home(char **env);
char				*ft_get_destination_folder(char *current_folder,
						int count_slash, char **folders, char *arg);
int					ft_change_folder(char *new_folder, char **split);

/*	BL_CD.C	*/

int					bl_cd(char **env, char **split);
int					ft_cd_absolute_path(char **split);
int					ft_cd_relative_path(char **split);
int					ft_deep_path(char **split, char **list_of_files,
						int count_slash);
int					ft_enter_in_folder(char **split, char **list_of_files);

/*	BL_ECHO.C	*/

void				bl_echo(char **split, int argc);
int					ft_echo_n_option(char **split);
int					ft_echo_no_options(char **split);

/*	BL_ENV.C	*/

int					bl_env(char **env, int argc, char **split);

/*	BL_EXIT.C	*/

void				bl_exit(char **split, int argc, int stat);
void				ft_check_exit_error(char **split);

/*	BL_EXPORT_ADD_NODE.c	*/

void				ft_name_doesnt_exists_add_new_node(t_node *new_node,
						char *name, char *value);
void				ft_name_and_value_dont_exist_add_name(t_node *new_node,
						char *name);
void				ft_value_doesnt_exists(t_node *new_node, char *name);
void				ft_add_new_node_at_the_end_of_list(t_node **head,
						t_node *current, t_node *new_node);

/*	BL_EXPORT_UPDATE_NODE.c	*/

void				ft_name_exists_so_update_value(t_node *current,
						char *name, char *value);
void				ft_name_exists_add_value(t_node *current,
						char *name, char *value);
void				ft_name_exists_no_value(t_node *current, char *name);

/*	BL_EXPORT_UTILS_ARRAY.C	*/

void				ft_add_element_to_array(char **env,
						char *name, char *value);
void				ft_edit_value_in_array(t_shell_info *sh_info,
						char **env, char *name, char *value);
int					ft_attach_string_to_array(char **env,
						char *name, char *value);

/*	BL_EXPORT_UTILS_LIST_1.C	*/

void				ft_add_or_update_node_in_list(t_node **head,
						char *name, char *value);
bool				ft_update_existing_node(t_node **head,
						char *name, char *value);
void				ft_add_node_in_list(t_node **head, char *name, char *value);
int					ft_add_arg_without_egual_sign(t_shell_info *sh_info,
						char *arg);
int					ft_attach_string_to_list(t_shell_info *sh_info, char *name,
						char *value);

/*	BL_EXPORT_UTILS_LIST_2.C	*/

t_node				*ft_get_list_head(t_list_var_env *var);
t_node				*ft_get_list_tail(t_list_var_env *var);
void				ft_swap_nodes(t_node *a, t_node *b);
void				ft_sort_list(t_node **head);
void				ft_print_list(t_list_var_env *list);

/*	BL_EXPORT_UTILS.C	*/

int					ft_find_char_index_str(char *str, char c);
int					ft_find_char_array(char **array, char c);
int					ft_check_exclamation_mark(char **split);
int					ft_check_if_variable_name_exists(t_shell_info *sh_info,
						char *name);

/*	BL_EXPORT.C	*/

int					bl_export(t_shell_info *sh_info,
						char **env, int argc, char **split);
int					ft_egual_sign_exists(t_shell_info *sh_info,
						char **env, char *arg, int index_egual_sign);
int					ft_arg_has_plus_sign_and_value(t_shell_info *sh_info,
						char **env, char *arg, char *value);
int					ft_arg_has_plus_sign_and_no_value(t_shell_info *sh_info,
						char **env, char *arg);
int					ft_arg_has_egual_sign(t_shell_info *sh_info,
						char **env, char *arg, char *value);

/*	BL_LS.C	*/

int					bl_ls(void);

/*	BL_PWD.C	*/

int					bl_pwd(void);

/*	BL_UNSET.C	*/

int					bl_unset(char **env, char **split,
						t_shell_info *sh_info, int argc);
int					ft_remove_string_from_array(char **env,
						char *name, char *value);
void				ft_free_node(t_node *node);
void				ft_remove_node_from_list(t_list_var_env *env,
						char *name, char *value);

/*	CHECK_ERRORS.C	*/

void				ft_check_args(int argc, char **argv);
void				ft_check_lexical_error(t_shell_info *sh_info);

/*	STEUP.C	*/

void				ft_init_variables(char **env, t_shell_info *sh_info);

/*	FT_FREE_ARRAY.C	*/

void				ft_free_array(char **array);

/*	EXPANSION.C	*/

int					ft_expansion(t_shell_info *sh_info, t_lx_list_token *token);
char				**ft_get_sub_str(char *str);
char				*ft_check_type_quotes(t_shell_info *sh_info, char *str);
void				ft_expand_dollar_in_input_str(char **sub_strs,
						t_lx_list_token *token);

/*	EXPANSION_UTILS.C	*/

char				*dl_dollar_expander(char **env, char *name);
char				*ft_replace_substring(char *str,
						char *sub_str, char *replace_str);

/*	QUOTES_AND_DOLLAR.C	*/

void				ft_free_exp_variables(t_expansion	*exp);
void				ft_replace_dollar_with_value(t_shell_info *sh_info,
						char **sub_str, t_expansion *exp, int k);
char				*ft_dollar_sign_without_quotes(t_shell_info *sh_info,
						char *sub_str);
char				*ft_work_on_double_quotes(t_shell_info *sh_info,
						char *sub_str);
char				*ft_work_on_all_quotes(t_shell_info *sh_info,
						char *str);

/*	WILDCARD.C	*/

char				**wc_star(char **arr_cmd_arg);

#endif
