/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onapoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:40:37 by onapoli-          #+#    #+#             */
/*   Updated: 2021/10/14 11:06:09 by onapoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_start(char const *s, char c, int word)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (word_count != word && s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			word_count++;
			while (s[i] && s[i] != c && word_count != word)
				i++;
		}
	}
	return (i);
}

static int	ft_word_len(char const *s, char c, int word)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (word_count != word && s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			word_count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (i);
}

static int	ft_get_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (words);
}

int	loop(int const words, char **pt, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < words)
	{
		j = ft_word_start(s, c, i + 1);
		k = 0;
		pt[i] = malloc((ft_word_len(s, c, i + 1) + 1) * sizeof(char));
		if (!pt[i])
			return (1);
		while (s[j] && s[j] != c)
			pt[i][k++] = s[j++];
		pt[i][k] = 0;
		i++;
	}
	pt[i] = 0;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**pt;

	if (!s)
		return (0);
	words = ft_get_words(s, c);
	pt = malloc((words + 1) * sizeof(char *));
	if (!pt)
		return (0);
	if (loop(words, pt, s, c))
		return (0);
	return (pt);
}
