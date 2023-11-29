/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:12:00 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/28 17:20:10 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// @brief	Exits the program, but not before printing an informative error
void	exit_error(char *message)
{
	int		counter;

	counter = 0;
	while (VERBOSE == 1 && message[counter] != '\0')
		write(STDERR_FILENO, &message[counter++], 1);
	if (VERBOSE == 0)
		write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

// @brief	frees a twodimensional array
void	pex_free_rec(void **blob)
{
	int		counter;

	counter = 0;
	if (blob != NULL)
	{
		while (blob[counter] != NULL)
		{
			free(blob[counter]);
			counter++;
		}
		free(blob);
	}
}
