/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onapoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:34:23 by onapoli-          #+#    #+#             */
/*   Updated: 2021/10/12 22:21:34 by onapoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	u;

	i = 0;
	p = (unsigned char *)s;
	u = c;
	while (i < n)
	{
		if (p[i] == u)
			return (&p[i]);
		i++;
	}
	return (NULL);
}
