#include <stdio.h>

int main()
{
    for (int i = 0; i <= 100; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            printf("\n %i - FizzBuzz\n", i);
        }
        else if (i % 3 == 0)
        {
            printf("%i - Fizz\n", i);
        }
        else if (i % 5 == 0)
        {
            printf("%i - Buzz\n", i);
        }
        else
        {
            printf("%i - NOPE\n", i);
        }
    }
    return 0;
}
