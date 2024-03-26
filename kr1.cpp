#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	double frequency = sysconf(_SC_CLK_TCK) / 1e9;
	printf("proc freq: %.9f GHz\n", frequency);

	printf("autor: Feofilactov KE-217\n");

	sleep(frequency);

	pid_t pid = fork();
	
	if (pid == 0)
	{
	double sum = 0.0;
	int sign = 1;
	for (int i = 1 ;; i++)
		{
		sum += 1.0 / i * sign;
		printf("cur sum:%.6f\n", sum );
		sign = -sign;
		usleep(100000); 
		}	
	} 
	else if (pid > 0 )
	{
	printf("Parent proc ID: %d\n", getpid());
	printf("Child proc ID: %d\n", pid);
	wait(NULL);
	}
return 0;
}
