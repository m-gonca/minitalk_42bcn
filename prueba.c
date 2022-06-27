#include <stdio.h>
#include <unistd.h>

int show_pid()
{
	pid_t	pid;

	pid = getpid();
	printf("PID: %d\n", pid);
	while(1)
	{
		printf("waiting for signs\n");
		sleep(2);
	}
	return(0);
}

int main()
{
	show_pid();
	return(0);
}