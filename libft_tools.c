/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 10:19:59 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/06/12 12:33:38 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int				i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || !s1[i] || !s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = (char *)malloc((len(s1) + 1) * sizeof(char));
	if (!s2)
		err("allocation failed", FAILURE, NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(char *s, int start, int lenght)
{
	int		i;
	char	*s2;
	
	if (!s)
		return(NULL);
	s2 = (char *)malloc((lenght + 1) * sizeof(char));
	if (!s2)
		err("allocation failed", FAILURE, NULL);
	i = 0;
	if (start < len(s))
	{
		while (s[start] && i < lenght)
		{
			s2[i] = s[start];
			start++;
			i++;
		}
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc((len(s1) + len(s2) + 1) * sizeof(char));
	if (!s3)
		err("allocation failed", FAILURE, NULL);
	i = 0;
	while (*s1)
	{
		s3[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		s3[i] = *s2++;
		i++;
	}
	s3[i] = '\0';
	return (s3);
}