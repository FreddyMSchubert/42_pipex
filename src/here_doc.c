/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:34:45 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/30 18:36:09 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// @brief		adds the "ft_heredoc> " at the beginning of each here doc line
void	add_heredoc(void)
{
	char	*message;

	message = "ft_heredoc> ";
	if (VERBOSE == 1)
		write(STDIN_FILENO, "\033[33m", 5);
	write(STDIN_FILENO, message, ft_strlen(message));
	if (VERBOSE == 1)
		write(STDIN_FILENO, "\033[0m", 4);
}

/*
	@brief	Checks if theres a limiter. If there isn't, it appends the message
	@brief	to the inputted pipe. If there is, it stops data input.
*/
static int	write_to_pipe_until_limiter(int pipe_write_fd, \
										char *limiter, \
										char *message)
{
	size_t		counter;

	counter = 0;
	while (message[0] == limiter[0] && counter < ft_strlen(limiter))
	{
		if (message[counter] != limiter[counter])
			break ;
		if (counter == ft_strlen(limiter) - 1)
			return (free(message), 1);
		counter++;
	}
	write(pipe_write_fd, message, ft_strlen(message));
	free (message);
	return (0);
}

/*
	@brief	This handles the input. It gets the data inputted and sends it to
	@brief	the write_to_pipe_until_limiter function to save it.
*/
static int	read_from_input_until_limiter(char	*limiter)
{
	int			pipefd[2];
	char		*gnl_return;

	if (VERBOSE == 1)
		ft_printf("LOGGER: Now reading from input until delimiter.\n");
	if (pipe(pipefd) == -1)
		exit_error("ERROR: Creation of pipe failed.\n");
	add_heredoc();
	gnl_return = get_next_line(STDIN_FILENO);
	while (gnl_return != NULL)
	{
		if (write_to_pipe_until_limiter(pipefd[1], limiter, gnl_return) == 1)
		{
			close(pipefd[1]);
			get_next_line(-1);
			return (pipefd[0]);
		}
		add_heredoc();
		gnl_return = get_next_line(STDIN_FILENO);
	}
	close(pipefd[1]);
	return (pipefd[0]);
}

/*
	@brief	Similar to main but for when here_doc is activated.
	@brief	e.g. takes input from stdin instead of file.
*/
int	here_doc(int argc, char **argv, char **envp)
{
	int		out_fd;
	int		in_fd;
	int		counter;

	if (VERBOSE == 1)
		ft_printf("LOGGER: here_doc recognized!\n");
	if (argc < 4)
		exit_error("ERROR: Invalid inputs, check args & file permissions.\n");
	out_fd = open(argv[argc - 1], O_RDWR | O_APPEND | O_CREAT, 0777);
	if (out_fd < 0)
		exit_error("ERROR trying to access output file.\n");
	in_fd = read_from_input_until_limiter(argv[2]);
	counter = 2;
	while (++counter < argc - 2)
		in_fd = execute_command(in_fd, argv[counter], -1, envp);
	in_fd = execute_command(in_fd, argv[counter], out_fd, envp);
	close(in_fd);
	close(out_fd);
	return (0);
}
