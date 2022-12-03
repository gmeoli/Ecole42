#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int	error(char *str, char *err)
{
	while (*str)
		write(2, str++, 1);
	if (err)
		while (*err)
			write(2, err++, 1);
	write(2, "\n", 1);
	return (1);
}

int	exec(char **args, int len, int fd, char **env)
{
	args[len] = NULL;
	dup2(fd, 0);
	close(fd);
	execve(args[0], args, env);
	return (error("error: cannot execute ", args[0]));
}

int	main(int argc, char **argv, char **env)
{
	int	i;
	int	pid;
	int	tmp;
	int	fd[2];

	i = 0;
	pid = 0;
	tmp = dup(0);
	(void)argc;
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (!strcmp(argv[0], "cd"))
		{
			if (i != 2)
				error("error: cd: bad arguments", NULL);
			else if (chdir(argv[1]) != 0)
				error("error: cd: cannot change directory to ", argv[1]);
		}
		else if (i != 0 && (argv[i] == NULL || !strcmp(argv[i], ";")))
		{
			pid = fork();
			if (!pid)
			{
				if (exec(argv, i, tmp, env))
					return (1);
			}
			else
			{
				close(tmp);
				while (waitpid(-1, NULL, WUNTRACED) != -1)
					;
				tmp = dup(0);
			}
		}
		else if (i != 0 && !strcmp(argv[i], "|"))
		{
			pipe(fd);
			pid = fork();
			if (!pid)
			{
				dup2(fd[1], 1);
				close(fd[1]);
				close(fd[0]);
				if (exec(argv, i, tmp, env))
					return (1);
			}
			else
			{
				close(tmp);
				close(fd[1]);
				tmp = fd[0];
			}
		}
	}
	close(tmp);
	return (0);
}
