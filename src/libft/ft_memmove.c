/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onapoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:09:58 by onapoli-          #+#    #+#             */
/*   Updated: 2020/01/22 12:57:25 by onapoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == NULL && src == NULL)
		return (NULL);
	if (len == 0)
		return (dst);
	if (dst > src)
		while (len-- > 0)
			*(unsigned char *)(dst + len) = *(const unsigned char *)(src + len);
	else if (dst < src)
		ft_memcpy(dst, src, len);
	return (dst);
}
