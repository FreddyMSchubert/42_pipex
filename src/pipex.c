/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:26:25 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/29 10:33:35 by fschuber         ###   ########.fr       */
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

/*
	@brief		Main function.
	@brief		Used to loop through input.
*/
int	main(int argc, char **argv, char **envp)
{
	int		in_fd;
	int		out_fd;
	int		counter;

	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		return (here_doc(argc, argv, envp));
	if (argc < 4 || access(argv[1], R_OK) != 0)
		exit_error("ERROR: Invalid inputs, check args & file permissions.\n");
	in_fd = open(argv[1], O_RDONLY);
	out_fd = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (in_fd < 0 || out_fd < 0)
		exit_error("ERROR trying to access input or output files.\n");
	counter = 1;
	while (++counter < argc - 2)
		in_fd = execute_command(in_fd, argv[counter], -1, envp);
	in_fd = execute_command(in_fd, argv[counter], out_fd, envp);
	close(in_fd);
	close(out_fd);
	return (0);
}
