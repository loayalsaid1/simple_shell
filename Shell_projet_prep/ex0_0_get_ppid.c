#include <unistd.h>
#include <stdio.h>

int main(void)
{
	pid_t ppid = getppid();

	printf("%i\n", ppid);

	return (0);
}
