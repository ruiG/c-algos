#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 0;
    long long unsigned int prev[2] = {1, 1};

    system("clear"); // clear screen

    printf("how long of a fibonacci sequence? > ");
    scanf("%d", &size);

    for (size_t count = 0; count <= size; count++)
    {
        long long unsigned int fib = prev[0] + prev[1];
        prev[1] = prev[0];
        prev[0] = fib;

        printf("%llu\n", fib);
    }
    printf("\n");
    return 0;
}