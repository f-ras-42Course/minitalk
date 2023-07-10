/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validations.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/06 21:12:50 by fras          #+#    #+#                 */
/*   Updated: 2023/07/10 15:24:43 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mt_client.h"

bool	invalid_userinput(int argc, char **argv)
{
	if (argc != 3)
		return (user_mistake(unexpected_argument_qty));
	if (!string_is_digit_only(argv[1]))
		return (user_mistake(invalid_PID_format));
	if (ft_strlen(argv[1]) > 7 || ft_atoi(argv[1]) > PID_MAX_LIMIT)
		return (user_mistake(pid_max_exceeded));
	return (false);
}

bool	user_mistake(t_user_error code)
{
	if (code == unexpected_argument_qty)
		write(STDERR_FILENO, "ERROR: expected two arguments.\n", 31);
	if (code == invalid_PID_format)
		write(STDERR_FILENO, "ERROR: expects only digits in PID format.\n", 43);
	if (code == pid_max_exceeded)
		write(STDERR_FILENO, "ERROR: MAX_PID 4194304 exceeded.\n", 34);
	ft_printf("\nusage: ./client [server PID] \"string to send\"\n");
	return (true);
}
