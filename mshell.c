#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int exec(char **av, int i, char **envp)
{
	
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