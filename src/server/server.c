/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/05 20:40:08 by fras          #+#    #+#                 */
/*   Updated: 2023/07/10 20:03:35 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mt_server.h"

void	signal_handler(int mode)
{
	static int	bit_position = 0x1;
	static char	char_to_print;

	if (mode == SIGUSR2)
		char_to_print |= bit_position;
	bit_position <<= 1;
	if (bit_position == 0x100)
	{
		ft_putchar_fd(char_to_print, STDOUT_FILENO);
		bit_position = 0x1;
		char_to_print = 0x0;
		return ;
	}
}

int	main(void)
{
	ft_printf("Server PID:\n%d\n\n", getpid());
	ft_printf("Running and waiting for signal...\n\n");
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
