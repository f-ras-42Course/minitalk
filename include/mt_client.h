/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mt_client.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/05 20:42:09 by fras          #+#    #+#                 */
/*   Updated: 2023/07/06 23:10:50 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MT_CLIENT_H
# define MT_CLIENT_H

# define PID_MAX_LIMIT			4194304
# define PID_MAX_LIMIT_DIGITS	7

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"
# include "ft_printf.h"
# include "lib42-extended.h"

typedef enum e_user_error
{
	unexpected_argument_qty,
	invalid_PID_format,
	pid_max_exceeded
}	t_user_error;

bool	invalid_userinput(int argc, char **argv);
bool	user_mistake(t_user_error code);

#endif