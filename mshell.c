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

int exec(char **av, int i, char **envp)
{
	int has_pipe, fd[2], pid, status;
	has_pipe = av[i] && !strcmp(av[i], "|");
	if (!has_pipe && !strcmp(*av, "cd"))
		return cd(av, i);
	if (has_pipe && pipe(fd) == -1)
		err("error: fatal\n"), exit(1);
	
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