/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 10:18:13 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/06/12 13:14:12 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	err(char *s, int ext, char *cmd)
{
	print("pipex : ", STDERR);
	if (cmd)
	{
		print(cmd, STDERR);
		print(": ", STDERR);
	}
	print(s, STDERR);
	print("\n", STDERR);
	exit(ext);
}

int		len(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

void	print(char *s, int fd)
{
	if (s)
		write(fd, s, len(s));
}