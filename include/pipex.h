/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 07:39:06 by fschuber          #+#    #+#             */
/*   Updated: 2023/12/01 09:46:48 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

#include "../submodules/42_ft_printf/ft_printf.h"
#include "../submodules/42_libft/libft.h"
#include "../submodules/42_get_next_line/get_next_line.h"

// 1 -> detailed logging
// 0 -> limited login / handin logging
#define VERBOSE 1

typedef struct s_cmd_path {
	char	*path;
	char	**args;
}				t_cmd_path;

// MAIN COMMON STUFF
int			execute_command(int in_fd, char *cmd, int out_fd, char **envp);

// HERE DOC FUNCTIONALITY
int			here_doc(int argc, char **argv, char **envp);

// UTILS

void		exit_error(char *message);
void		pex_free_rec(void **blob);

// PARENT

int			parent_routine(pid_t pid, int pipefd[2], int out_fd);

// CHILDREN

void		children_routine(int pipefd[2], t_cmd_path *cmd, int in_fd, \
																int out_fd);
t_cmd_path	*create_cmd_struct(char	**envp, char	*cmd);