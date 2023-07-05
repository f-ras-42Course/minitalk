/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mt_client.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/05 20:42:09 by fras          #+#    #+#                 */
/*   Updated: 2023/07/05 21:45:58 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MT_CLIENT_H
# define MT_CLIENT_H

# define PID_MAX_LIMIT			4194304
# define PID_MAX_LIMIT_DIGITS	7

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

char	*ft_itoa(int n);
int		ft_atoi(const char *str);

#endif