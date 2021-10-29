/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onapoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 19:49:20 by onapoli-          #+#    #+#             */
/*   Updated: 2021/10/14 10:55:22 by onapoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	count;

	count = 0;
	while (*(str + count))
	{
		if (*(char *)(str + count) == (char)c)
			return ((char *)(str + count));
		count++;
	}
	if ((char)c == 0)
		return ((char *)(str + count));
	return (0);
}
