/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/05 20:40:12 by fras          #+#    #+#                 */
/*   Updated: 2023/07/05 21:44:58 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mt_client.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("INVALID NUMBER OF ARGUMENTS\n");
		return(0);
	}
	int i;

	i = 0;
	while (argv[1][i])
		i++;
	if (i > 7 || ft_atoi(argv[1]) > PID_MAX_LIMIT)
	{
		printf("MAX_PID reached: 4194304 | enter valid PID.\n");
		return(0);
	}
	printf("MAX PID: %d", PID_MAX_LIMIT);
}