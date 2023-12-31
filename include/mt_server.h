/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mt_server.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/05 20:42:12 by fras          #+#    #+#                 */
/*   Updated: 2023/07/10 20:04:41 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MT_SERVER_H
# define MT_SERVER_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

void	signal_handler(int mode);

#endif