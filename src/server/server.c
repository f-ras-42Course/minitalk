/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/05 20:40:08 by fras          #+#    #+#                 */
/*   Updated: 2023/07/06 23:46:00 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mt_server.h"

int	main(void)
{
	printf("Server PID:\n%d\n\n", getpid());
	printf("Running and waiting for signal...\n\n");
	while (1);
	return (0);
}
