/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onapoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:56:09 by onapoli-          #+#    #+#             */
/*   Updated: 2020/01/24 14:59:37 by onapoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*pd;
	const unsigned char	*ps;

	if (!n || src == dst)
		return (dst);
	i = 0;
	pd = dst;
	ps = src;
	while (i < n)
	{
		pd[i] = ps[i];
		i++;
	}
	return (dst);
}
