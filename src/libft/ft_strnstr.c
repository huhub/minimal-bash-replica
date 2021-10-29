/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onapoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:33:52 by onapoli-          #+#    #+#             */
/*   Updated: 2021/10/14 11:09:51 by onapoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count;
	size_t	nlen;

	if (haystack == needle)
		return ((char *)haystack);
	if (needle[0] == '\0' || haystack == needle)
		return ((char *)haystack);
	nlen = ft_strlen(needle);
	if (nlen == 0)
		return ((char *)haystack);
	count = 0;
	while (*(haystack + count) && nlen <= len--)
	{
		if (!ft_strncmp((char *)(haystack + count), (char *)needle, nlen))
			return ((char *)(haystack + count));
		count++;
	}
	return (NULL);
}
