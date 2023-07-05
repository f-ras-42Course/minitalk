/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 17:31:06 by fras          #+#    #+#                 */
/*   Updated: 2023/07/05 21:36:43 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mt_client.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		rtn;
	int		sign;

	i = 0;
	rtn = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		rtn *= 10;
		rtn += str[i++] - '0';
	}
	return (rtn * sign);
}