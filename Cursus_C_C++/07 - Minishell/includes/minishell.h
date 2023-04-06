/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:11:31 by masebast          #+#    #+#             */
/*   Updated: 2022/11/17 20:30:38 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

# define TRUE 1
# define FALSE 0

int	*g_exit_status;

typedef struct s_command {
	char	*current_shell_level;
	char	**envp_copy;
	char	*command_string;
	char	**pipe_matrix;
	char	**word_matrix;
	int		total_pipes;
	int		pipes[2];
	int		write_fd;
	int		read_fd;
	char	*operator;
}	t_command;

// INIT
void		ft_init_struct(t_command *command_struct, char **envp);
char		*ft_getenv_copy(char *key, char **envp_copy);
char		**ft_expand_dollar(char **word_matrix, t_command *c_s);

// ERRORS
void		ft_error(void);
void		ft_syntax_error(char c);
void		ft_command_not_found(char *str);
void		ft_arg_not_found(char *str);
void		ft_unexpected_token(void);
void		ft_export_error(char *identifier);

// CYCLE
void		ft_history_pipe_matrix(t_command *c_s);
void		ft_error_in_history(t_command *c_s);
void		ft_add_and_free(t_command *c_s);
void		ft_execute_cycle(t_command *c_s, char **envp);

// UTILITY
int			ft_check_quotes(char *str);
void		ft_free_matrix(char **m);
int			ft_parsing(char *input, t_command *command_struct);
int			ft_pipe_total(char *input);
int			ft_count_pipes(char *str);
int			ft_check_equal_presence(char *string);
void		ft_remove_quotes(char *command);
void		ft_manage_signals(void);
int			ft_modify_var(char *new_couple, char **envp);
void		ft_exit_on_signal(void);

// EXPANDER
char		*ft_return_expanded(char *string, t_command *c_s);

// CHECK SYNTAX
int			ft_check_syntax(char *command);

// CD
int			ft_cd(t_command *command_struct);
int			ft_find_dest_len(char *path);
int			ft_find_home_len(char *path);

// PIPES
void		ft_manage_pipes(t_command *c_s, char **envp);
char		**ft_split_pipes(const char *s, char c);
int			count_strings_pipes(const char *s, char c);
void		ft_quote_control(const char *s, int *i, char *word);
int			skip_quotes(const char *s, char quote);
int			ft_check_redirection(char **word_struct);
void		ft_dup_and_close(int *stdin_cpy, int *stdout_cpy);
void		ft_wait_and_free(int *index, t_command *c_s, int *pid);

// REDIRECTIONS
int			ft_check_redirection(char **word_struct);
void		ft_redirect(t_command *c_s, int p_i, char **envp);
int			ft_find_quotes(char *word);
void		ft_redirect_output(t_command *c_s, int p_i, \
	char **envp, int *index);
void		ft_trunc(t_command *c_s, int p_i, char **envp, int *i);
void		ft_append(t_command *c_s, int p_i, char **envp, int *i);
void		ft_redirect_input(t_command *c_s, int p_i, char **envp, int *index);
int			ft_input_redirect(t_command *c_s, int *fd, int *i);
int			ft_check_token(t_command *c_s, int *i);
void		ft_heredoc(t_command *c_s, int p_i, char **envp, int *i);
char		*ft_remove_heredoc(char *pipe);
void		ft_new_matrix(char **w_m, int *i, char **temp_matrix, \
	int *temp_index);
char		**ft_decrease_word_matrix(char **word_matrix);
char		*ft_update_pipe_text(char *pipe);
void		ft_red_exe(t_command *c_s, int p_i, char **envp, int fd);
int			ft_find_quotes(char *word);

// ECHO
int			ft_echo(t_command *c_s, int p_i);
int			ft_print_doll(char *str, int fd, char **env_copy);
char		*ft_adjust_pipe(char *pipe);
int			ft_check_quote(char *str);
void		ft_print_exit(void);
int			ft_print_double(char *string, int fd, char **env_copy);
int			ft_print_single(char *string, int fd);

// BUILTINS
int			ft_pwd(void);
void		ft_exit(t_command *c_s);
int			ft_env(t_command *command_struct, char **envp);
int			ft_unset(t_command *command_struct, char **envp);

// EXPORT
int			ft_export(t_command *command_struct, char **envp);
int			ft_buble_sort_env(char **envp);
int			ft_check_char(char *str);
void		ft_print_envp2(char **envp2);
char		**ft_create_envp2(char **envp);
void		ft_export_error(char *identifier);
int			ft_check_special(char *var);

// OTHER COMMANDS
int			ft_other_commands(t_command *command_struct, char **envp);
int			ft_recognize_command(t_command *c_s, int p_i, char **envp);

// RLS
extern void	rl_replace_line(const char *text, int clear_undo);

// SIGNALS
void		ft_ctrl_c(char **envp);

#endif
