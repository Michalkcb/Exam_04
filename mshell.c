#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
void err(char *s)
{
	while (*s)
		write(2, s+, 1)
}

int cd(char **av, int i)
{

}
int set_pipe(int has_pipe, int *fd, int end)
{

}

int exec(char **av, int i, char **envp)
{
	int has_pipe, fd[2], pid, status;
	has_pipe = av[i] && !strcmp(av[i], "|");
	if (!has_pipe && !strcmp(*av, "cd"))
		return cd(av, i);
	if (has_pipe && pipe(fd) == -1)
		err("error: fatal\n"), exit(1);
	if ((pid = fork()) == -1)
		err("error: fatal\n"), exit(1);
	if (!pid)
	{
		av[i] = 0;
		set_pipe(has_pipe, fd, 1);
		if (!strcmp(*av, "cd"))
			exit(cd(av, i));
		execve(*av, av, envp);
		err("error: cannot execute "), err(*av), err("\n"); exit(1);
	}
	waitpid(pid, &status, 0);
	set_pipe(has_pipe, fd, 0);
	return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int ac, char **av, char **envp)
{
	(void)ac;
	int i = 0, status = 0;
	while (av[i])
	{
		av += i + 1;
		i = 0;
		while (av[i] && strcmp(av[i],"|") && strcmp(av[i], ";"))
			i++;
		if (i)
			status = exec(av, i, envp);
	}
	return status;
}