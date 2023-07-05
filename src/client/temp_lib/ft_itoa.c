/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/04 14:09:15 by fras          #+#    #+#                 */
/*   Updated: 2023/07/05 21:35:18 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mt_client.h"

void		*ft_memcpy(void *dest, const void *src, size_t n);
static int	numsize(int n);

char	*ft_itoa(int n)
{
	char	*ret;
	int		len;

	len = numsize(n);
	ret = malloc((len + 1) * sizeof(*ret));
	if (!ret)
		return (NULL);
	if (n == -2147483648)
		return (ft_memcpy(ret, "-2147483648", 12));
	if (n == 0)
		return (ft_memcpy(ret, "0", 2));
	if (n < 0)
	{
		ret[0] = '-';
		n *= -1;
	}
	ret[len] = '\0';
	while (n)
	{
		ret[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (ret);
}

static int	numsize(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len += 1;
	if (n == 0)
		return (len + 1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}