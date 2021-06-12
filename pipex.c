/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 10:00:40 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/06/12 13:08:34 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	char	*make_path(char **path, char	*cmd)
{
	int		i;
	char	*file;
	char	*tmp;

	i = -1;
	if (!cmd)
		return(ft_strdup(""));
	file = ft_strjoin("/", cmd);
	while (path[++i] && path[i][0])
	{
		tmp = ft_strjoin(path[i], file);
		if (open(tmp, O_RDONLY) > 0)
		{
			free(file);
			return (tmp);
		}
		free(tmp);
	}
	free(file);
	return (ft_strdup(cmd));
}

static void get_path(t_pipex *pip, char **env)
{
	char *p;
	int i;
	
	i = -1;
	p = ft_strdup("");
	while (env && env[++i])
	{
		if (!ft_strncmp("PATH=", env[i], 5))
			p = ft_substr(env[i], 5, len(env[i]));
	}
	pip->path = ft_split(p, ':');
	free(p);
}

static  void    init(t_pipex *pip,char **argv, char **env)
{
	int error;
	
	get_path(pip, env);
	pip->env = env;
	pip->f1 = ft_strdup(argv[1]);
	pip->cmd1 = ft_split(argv[2], ' ');
	pip->p1 = make_path(pip->path, pip->cmd1[0]);
	pip->cmd2 = ft_split(argv[3], ' ');
	pip->p2 = make_path(pip->path, pip->cmd2[0]);
	pip->f2 = ft_strdup(argv[4]);
	error = pipe(pip->pipe);
	if (error)
		err(strerror(errno), 1, NULL);
}

int main(int argc, char **argv, char **env)
{
	t_pipex pipex;
	int		pid1;
	int		pid2;

	if (argc != 5)
		err("input in wrong format", 1, NULL);
	init(&pipex, argv, env);
	pid1 = fork();
	one(pid1, &pipex);
	pid2 = fork();
	two(pid2, &pipex);
	close_wait(&pipex, pid1, pid2);
	return (pipex.ext);
}