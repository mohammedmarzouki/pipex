/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:59:27 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/06/12 13:11:58 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	one(int pid, t_pipex *pip)
{
	int input;
	
	if (pid)
		return ;
	input = open(pip->f1, O_RDONLY, 0644);
	if (input < 0)
		err(strerror(errno), 1, pip->f1);
	dup2(input, STDIN);
	close(input);
	dup2(pip->pipe[1], STDOUT);
	close(pip->pipe[0]);
	close(pip->pipe[1]);
	execve(pip->p1, pip->cmd1, pip->env);
	err(": command not found", 127, pip->cmd1[0]);
}

void	two(int pid, t_pipex *pip)
{
	int output;
	
	if (pid)
		return ;
	output = open(pip->f2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output < 0)
		err(strerror(errno), 1, pip->f2);
	dup2(output, STDOUT);
	close(output);
	dup2(pip->pipe[0], STDIN);
	close(pip->pipe[0]);
	close(pip->pipe[1]);
	execve(pip->p2, pip->cmd2, pip->env);
	err(": command not found", 127, pip->cmd2[0]);
}

void	close_wait(t_pipex *pip, int pid1, int pid2)
{
	close(pip->pipe[0]);
	close(pip->pipe[1]);
	waitpid(pid1, &pip->ext, 0);
	waitpid(pid2, &pip->ext, 0);
	pip->ext = WEXITSTATUS(pip->ext);
}