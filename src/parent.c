/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:40:30 by fschuber          #+#    #+#             */
/*   Updated: 2023/12/01 09:48:58 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// @brief		Parenting is hard.
// @brief		Handles parents created by execute_command function.
int	parent_routine(pid_t pid, int pipefd[2], int out_fd)
{
	close(pipefd[1]);
	waitpid(pid, NULL, 0);
	if (VERBOSE == 1)
		ft_printf("LOGGER: Child process %d terminated.\n", pid);
	if (out_fd == -1)
		return (pipefd[0]);
	return (out_fd);
}
