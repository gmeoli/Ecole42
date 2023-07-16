#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int	error(char *str, char *err){
	while (*str)
		write(2, str++, 1);
	if (err)
		while (*err)
			write(2, err++, 1);
	write(2, "\n", 1);
	return (1);
}

int	exec(char **args, int len, int fd, char **env){
	args[len] = NULL;
	dup2(fd, 0);
	close(fd);
	execve(args[0], args, env);
	return (error("error: cannot execute ", args[0]));
}

int	main(int ac, char **av, char **env){
	int	i = 0;
	int	pid;
	int	tmp = dup(0);
	int	fd[2];
	(void)ac;
	
	while (av[i] && av[i + 1]){
		av = &av[i + 1];
		i = 0;
		while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
			i++;
		if (!strcmp(av[0], "cd")){
			if (i != 2)
				error("error: cd: bad arguments", NULL);
			else if (chdir(av[1]) != 0)
				error("error: cd: cannot change directory to ", av[1]);
		}
		else if (i != 0 && (av[i] == NULL || !strcmp(av[i], ";"))){
			pid = fork();
			if (!pid) {
				if (exec(av, i, tmp, env))
					return (1);
			}
			else {
				close(tmp);
				while (waitpid(-1, NULL, WUNTRACED) != -1)
					;
				tmp = dup(0);
			}
		}
		else if (i != 0 && !strcmp(av[i], "|")){
			pipe(fd);
			pid = fork();
			if (!pid){
				dup2(fd[1], 1);
				close(fd[1]);
				close(fd[0]);
				if (exec(av, i, tmp, env))
					return (1);
			}
			else {
				close(tmp);
				close(fd[1]);
				tmp = fd[0];
			}
		}
	}
	close(tmp);
	return (0);
}
