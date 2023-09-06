#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 0
#define FALSE 1

typedef struct Array Array;

struct Array
{
    size_t length;
    int values[];
};

int linearSearch(Array *h, int n)
{
    for (size_t i = 0; i < h->length; ++i)
    {
        if (h->values[i] == n)
        {
            return i;
        }
    }

    return -1;
}

int randomGen(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int main()
{
    srand(time(NULL));
    system("clear");

    size_t *length;
    int *input_n;
    
    printf("How big of an array? ");
    scanf("%lu", length);

    size_t arrSize = sizeof(Array) + sizeof(int) * *length;
    Array *arr = (Array *)malloc(arrSize);

    printf("Search for: ");
    scanf("%d", input_n);

    if (arr != NULL)
    {
        arr->length = *length;

        // fill
        printf("Array: { ");
        for (size_t i = 0; i < *length; i++)
        {
            arr->values[i] = randomGen(1, 25);
            printf("%d ", arr->values[i]);
        }
        printf("}\n");

        int result = linearSearch(arr, *input_n);
        printf("Result: %d\n", result);

        free(arr); // 🫡
    }

    return 1;
}