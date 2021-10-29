/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onapoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:15:43 by onapoli-          #+#    #+#             */
/*   Updated: 2021/10/14 11:14:10 by onapoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	filler(char const *s1, char const *s2, char *p)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (j < ft_strlen(s1))
	{
		p[i] = (char)s1[j];
		j++;
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		p[i] = (char)s2[j];
		i++;
		j++;
	}
	p[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	p = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!p)
		return (NULL);
	filler(s1, s2, p);
	return (p);
}
