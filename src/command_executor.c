/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_executor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 06:54:36 by fschuber          #+#    #+#             */
/*   Updated: 2023/12/01 06:54:45 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*
	@brief		Executes an inputted shell command. Input gets read from in_fd.
	@returns	A file descriptor to the command output. This point to a pipe if
				out_fd is -1, otherwise it will simply be out_fd.
*/
int	execute_command(int in_fd, char *cmd, int out_fd, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (VERBOSE == 1)
		ft_printf("LOGGER: Executing command %s.\n", cmd);
	if (pipe(pipefd) == -1)
		exit_error("ERROR: Creating of pipe failed.\n");
	pid = fork();
	if (pid == 0)
		children_routine(pipefd, create_cmd_struct(envp, cmd), in_fd, out_fd);
	else if (pid > 0)
		return (parent_routine(pid, pipefd, out_fd));
	else
		exit_error("ERROR: Forking failed.\n");
	return (0);
}
