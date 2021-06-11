/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 10:01:00 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/06/11 13:52:01 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>


/*  file descriptors  */
#define STDIN 0
#define STDOUT 1
#define STDERR 2

/*  exit  */
#define FAILURE 1
#define SUCCESS 0

typedef struct s_pipex
{
	char	**path;
	char	*f1;
	char	**cmd1;
	char	*p1;
	char	**cmd2;
	char	*p2;
	char	*f2;
	int		pipe[2];
	
}              t_pipex;


/*  my_lib  */
int		len(char *s);
void	print(char *s, int fd);
void	err(char *s , int ext);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_substr(char *s, int start, int lenght);
char	*ft_strdup(char *s1);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
void	d_print(char **s);

#endif