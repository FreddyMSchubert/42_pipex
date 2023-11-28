/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:26:25 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/28 08:12:28 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// @brief	Exits the program, but not before printing an informative error
void	exit_error(char *message)
{
	ft_printf("\033[31m%s\033[0m", message);
	exit(EXIT_FAILURE);
}

/*
	@brief		Executes an inputted shell command. Input gets read from in_fd.
	@returns	A file descriptor to the command output. This point to a pipe if
				out_fd is -1, otherwise it will simply be out_fd.
				Returns -1 (invalid fd) if it encounters an error
*/
int	execute_command(int in_fd, char *command, int out_fd)
{
	(void)in_fd;
	(void)command;
	(void)out_fd;
	return (1);
}

/*
	@brief		Main function.
	@brief		Used to loop through input.
*/
int	main(int argc, char **argv)
{
	int		in_fd;
	int		out_fd;
	int		counter;

	if (argc < 4 || access(argv[1], R_OK) != 0 || \
					access(argv[argc - 1], W_OK) != 0)
		exit_error("ERROR: Invalid inputs, check args & file permissions.\n");
	in_fd = open(argv[1], O_RDONLY);
	out_fd = open(argv[argc - 1], O_RDWR);
	if (in_fd < 0 || out_fd < 0)
		exit_error("ERROR trying to read from input or output files.\n");
	counter = 2;
	while (counter < argc - 2)
	{
		in_fd = execute_command(in_fd, argv[counter], -1);
		if (in_fd < 0)
			exit_error("ERROR executing one of the inputted commands.\n");
		counter++;
	}
	in_fd = execute_command(in_fd, argv[counter], out_fd);
	if (in_fd < 0)
		exit_error("ERROR executing last command or writing to output file.\n");
	return (0);
}
