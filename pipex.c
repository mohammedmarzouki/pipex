/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 10:00:40 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/06/11 16:12:23 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	char	*make_path(char **path, char	*cmd)
{
	int		i;
	char	*file;
	char	*tmp;

	i = -1;
	file = ft_strjoin("/", cmd);
	while(path[++i] && path[i][0])
	{
		tmp = ft_strjoin(path[i], file);
		if(open(tmp, O_RDONLY) > 0)
		{
			free(file);
			return (tmp);
		}
		free(tmp);
	}
	free(file);
	return(ft_strdup(cmd));
}

static void get_path(t_pipex *pip, char **env)
{
	char *p;
	int i;
	
	i = -1;
	p = ft_strdup("");
	while(env && env[++i])
	{
		if(!ft_strncmp("PATH=", env[i], 5))
			p = ft_substr(env[i], 5, len(env[i]));
	}
	pip->path = ft_split(p, ':');
	free(p);
}

static  void    init(t_pipex *pip,char **argv, char **env)
{
	get_path(pip, env);
	pip->f1 = ft_strdup(argv[1]);
	pip->cmd1 = ft_split(argv[2], ' ');
	pip->p1 = make_path(pip->path, pip->cmd1[0]);
	pip->cmd2 = ft_split(argv[3], ' ');
	print("dcjyvb",1);
	d_print(pip->cmd2);
	pip->p2 = make_path(pip->path, pip->cmd2[0]);
	pip->f2 = ft_strdup(argv[4]);
}

int main(int argc, char **argv, char **env)
{
	t_pipex pipex;

	if (argc != 5)
		err("pipex : input in wrong format\n", 1);
	init(&pipex, argv, env);
	printf("file1 ->{%s}\n",pipex.f1);
	printf("CMD1 {\n");
	d_print(pipex.cmd1);
	printf("}\n");
	printf("path ->{%s}\n",pipex.p1);
	printf("CMD2 {\n");
	d_print(pipex.cmd2);
	printf("}\n");
	printf("path ->{%s}\n",pipex.p2);
	printf("file2 ->{%s}\n",pipex.f2);
	printf("PATH {\n");
	d_print(pipex.path);
	printf("}\n");
}