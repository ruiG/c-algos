#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define READ 0
#define WRITE 1

int main()
{
	int pipe1[2];
	int pipe2[2];

	char fixed_str[] = "Rui";
	char *input_str = malloc(100);
	pid_t p;

	// setup the pipes
	if (pipe(pipe1) == -1)
	{
		fprintf(stderr, "Pipe 1 failed to open\n");
		return -1;
	}

	if (pipe(pipe2) == -1)
	{
		fprintf(stderr, "Pipe 2 failed to open\n");
		return -1;
	}
	printf("Pipe 1 opened successfully: %i %d \n", pipe1[0], pipe1[1]);
	printf("Pipe 2 opened successfully: %d %d \n", pipe2[0], pipe2[1]);

	scanf("%s", input_str);

	// fork the process
	p = fork();
	
	if (p < 0)
	{
		fprintf(stderr, "fork failed! \n");
		return -1;
	}

	if (p == 0)
	{
		printf("I\'m the child! 🤯: %d \n", p);

	}
	else
	{
		printf("I\'m the Parent: %d \n", p);
	}


	free(input_str);
}
