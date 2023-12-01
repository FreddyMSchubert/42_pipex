/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 06:26:25 by fschuber          #+#    #+#             */
/*   Updated: 2023/12/01 06:56:31 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*
	@brief		Main function.
	@brief		Used to loop through input.
*/
int	main(int argc, char **argv, char **envp)
{
	int		in_fd;
	int		out_fd;

	if (argc != 5 || access(argv[1], R_OK) != 0)
		exit_error("ERROR: Invalid inputs, check args & file permissions.\n");
	in_fd = open(argv[1], O_RDONLY);
	out_fd = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (access(argv[4], W_OK) != 0)
		exit_error("ERROR trying to access output file.\n");
	if (in_fd < 0)
		exit_error("ERROR trying to access input or output files.\n");
	in_fd = execute_command(in_fd, argv[2], -1, envp);
	in_fd = execute_command(in_fd, argv[3], -1, envp);
	close(in_fd);
	close(out_fd);
	return (0);
}
