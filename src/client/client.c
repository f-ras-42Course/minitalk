/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/05 20:40:12 by fras          #+#    #+#                 */
/*   Updated: 2023/07/13 20:53:43 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mt_client.h"

int	main(int argc, char **argv)
{
	if (invalid_userinput(argc, argv))
		return (EXIT_FAILURE);
	send_string_to_server_using_signals(atoi(argv[1]), argv[2]);
	ft_printf("Signals sent to process %d.\n", atoi(argv[1]));
	return (EXIT_SUCCESS);
}

void	send_string_to_server_using_signals(int server_pid, char *str)
{
	while (*str)
	{
		convert_char_to_bitsignals(server_pid, *str);
		str++;
	}
}

void	convert_char_to_bitsignals(int server_pid, char c)
{
	char	bit_check;

	bit_check = 0x1;
	while (bit_check)
	{
		if (c & bit_check)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		bit_check <<= 1;
		usleep(100);
	}
}
