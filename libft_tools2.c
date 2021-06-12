/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tools2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:27:51 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/06/12 13:41:49 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	wordcount(char *s, char chr, int i, int c)
{
	while (s[i] && s[i] == chr)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != chr)
			i++;
		c++;
		while (s[i] && s[i] == chr)
			i++;
	}
	return (c);
}

static char	*wordnext(char *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static int	wordlen(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char *s, char c)
{
	char	**sp;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = wordcount(s, c, 0, 0);
	sp = (char **)malloc((words + 1) * sizeof(char *));
	if (!sp)
		err("allocation failed", FAILURE, NULL);
	i = 0;
	while (i < words)
	{
		s = wordnext(s, c);
		sp[i] = ft_substr(s, 0, wordlen(s, c));
		i++;
		s += wordlen(s, c);
	}
	sp[words] = NULL;
	return (sp);
}
