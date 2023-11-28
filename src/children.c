/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:40:30 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/28 11:28:02 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*
	@brief		Returns a dynamically allocated path to the command.
	@brief		It's on the caller to free the path.
	@brief		Expects cleaned up command, so no flags, params, etc
*/
static char	*get_command_path(char **envp, char *command)
{
	char	**split_paths;
	char	*path;
	char	*path_temp;
	int		counter;

	while (ft_strncmp(envp[0], "PATH", 4) != 0)
		envp++;
	split_paths = ft_split(envp[0], ':');
	if (split_paths == NULL)
		exit_error("Problem splitting command paths.\n");
	counter = 0;
	while (split_paths[counter])
	{
		path_temp = ft_strjoin(split_paths[counter], "/");
		path = ft_strjoin(path_temp, command);
		free (path_temp);
		if (!path || access(path, F_OK) == 0)
			return (pex_free_rec((void **)split_paths), path);
		free (path);
		counter++;
	}
	pex_free_rec((void **)split_paths);
	exit_error("ERROR finding command path.\n");
	return (NULL);
}

t_cmd_path	*create_cmd_struct(char	**envp, char	*cmd)
{
	t_cmd_path	*path;
	char		**split_cmd;

	path = malloc(sizeof(t_cmd_path));
	if (!path)
		exit_error("Problem allocating for command path.\n");
	split_cmd = ft_split(cmd, ' ');
	if (!split_cmd)
		exit_error("Problem allocating cmd for command path.\n");
	path->path = get_command_path(envp, split_cmd[0]);
	path->args = split_cmd;
	return (path);
}

// @brief		Children nowadays only ever redirect stdout to pipe write end.\n
// @brief		Handles children created by execute_command function
void	children_routine(int pipefd[2], t_cmd_path *cmd, int in_fd, int out_fd)
{
	close(pipefd[0]);
	dup2(in_fd, STDIN_FILENO);
	if (out_fd == -1)
	{
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
			exit_error("ERROR redirecting cmd output to pipe.\n");
	}
	else
	{
		if (dup2(out_fd, STDOUT_FILENO) == -1)
			exit_error("ERROR redirecting cmd output to output file.\n");
	}
	close(in_fd);
	close(pipefd[1]);
	execve(cmd->path, cmd->args, NULL);
	free (cmd->args);
	free (cmd);
	exit_error("ERROR: Command execution failed. Is the command correct?\n");
}
