/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/05 20:40:12 by fras          #+#    #+#                 */
/*   Updated: 2023/07/06 23:10:37 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mt_client.h"

int	main(int argc, char **argv)
{
	if(invalid_userinput(argc, argv))
		return(EXIT_FAILURE);
	ft_printf("MAX PID: %d", PID_MAX_LIMIT);
	return(EXIT_SUCCESS);
}