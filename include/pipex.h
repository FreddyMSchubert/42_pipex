/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 07:39:06 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/28 11:13:12 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include "../submodules/42_ft_printf/ft_printf.h"
#include "../submodules/42_libft/libft.h"

typedef struct s_cmd_path {
	char	*path;
	char	**args;
}				t_cmd_path;

// UTILS

void		exit_error(char *message);
void		pex_free_rec(void **blob);

// PARENT

int			parent_routine(pid_t pid, int pipefd[2], int out_fd);

// CHILDREN

void		children_routine(int pipefd[2], t_cmd_path *cmd, int in_fd, \
																int out_fd);
t_cmd_path	*create_cmd_struct(char	**envp, char	*cmd);