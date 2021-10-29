/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onapoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:54:42 by onapoli-          #+#    #+#             */
/*   Updated: 2021/10/12 22:16:55 by onapoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*pd;
	const unsigned char	*ps;
	unsigned char		u;

	i = 0;
	pd = dst;
	ps = src;
	u = c;
	while (i < n)
	{
		pd[i] = ps[i];
		if (ps[i] == u)
		{
			pd[i] = ps[i];
			return (&(pd[i + 1]));
		}
		i++;
	}
	return (NULL);
}
