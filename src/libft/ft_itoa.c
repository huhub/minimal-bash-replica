/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onapoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:17:52 by onapoli-          #+#    #+#             */
/*   Updated: 2021/10/14 10:53:20 by onapoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_filler(char *result, int sign, int len, long num)
{
	len += sign;
	result[len] = '\0';
	while (len > 0 + sign)
	{
		len--;
		result[len] = (num % 10) + '0';
		num = num / 10;
	}
	if (sign != 0)
		result[0] = '-';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	num;
	int		i;
	int		sign;

	i = 1;
	num = n;
	sign = 0;
	while (num > 9 || num < -9)
	{
		num = num / 10;
		i++;
	}
	num = n;
	if (num < 0)
	{
		sign = 1;
		num *= -1;
	}
	result = malloc(sizeof(char) * i + 1 + sign);
	if (result == NULL)
		return (NULL);
	return (ft_filler(result, sign, i, num));
}
