// Kishlay Singh
// 201ME229
// CS252 Assignment
// Question No. 3.21

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int n=0;
	int k=0;
	
	pid_t pid;

		do
		{
			printf("Enter a positive integer to run the Collatz Conjecture.\n"); 
  			scanf("%d", &k);	
		}while (k <= 0);

		pid = fork();

		if (pid == 0)
		{
			printf("Pid = %d enters if block\n" , pid);
			printf("Child is working...\n");
			printf("%d\n",k);
			while (k!=1)
			{
				if (k%2 == 0)
				{
					k = k/2;
				}
				else if (k%2 == 1)
				{
					k = 3 * (k) + 1;
				}	
			
				printf("%d\n",k);
			}
		
			printf("Value of k in child process = %d\n", k);
			printf("Child process (%d) is done.\n", pid);
		}
		else
		{
			printf("Pid = %d enters else block\n", pid);
			printf("Parent process is waiting on child process...\n");
			wait();
			printf("Parent process (%d) is done.\n", pid);
			printf("Value of k in parent process = %d\n", k);
		}
	return 0; 
}
