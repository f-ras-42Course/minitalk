/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/05 20:40:12 by fras          #+#    #+#                 */
/*   Updated: 2023/07/06 21:54:00 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mt_client.h"

int	main(int argc, char **argv)
{
	if(is_invalid_userinput(argc, argv))
		return(EXIT_FAILURE);
	return(EXIT_SUCCESS);
}