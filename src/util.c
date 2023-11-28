/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:12:00 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/28 10:41:22 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// @brief	Exits the program, but not before printing an informative error
void	exit_error(char *message)
{
	int		counter;

	counter = 0;
	while (message[counter] != '\0')
		if (write(STDERR_FILENO, &message[counter++], 1) == -1)
			if (write(STDERR_FILENO, "Writing failed!", 16) == -1)
				write(STDERR_FILENO, "Errm... Houston? HOUSTON!", 26);
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
