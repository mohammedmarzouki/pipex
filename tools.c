/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 10:18:13 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/06/11 15:36:53 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	d_print(char **s)
{
	int i;
	
	i = 0;
	if(!s || !s[i])
		print("NULL\n", 1);
	while(s[i])
	{
		print("\nfbn",1);
		print("<|",1);
		print(s[i], 1);
		print("|>",1);
		print("\n",1);
		i++;
	}
}

void	err(char *s, int ext)
{
	print(s, STDERR);
	exit(ext);
}

int		len(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while(s[len])
		len++;
	return(len);
}

void	print(char *s, int fd)
{
	if (s)
		write(fd, s, len(s));
}