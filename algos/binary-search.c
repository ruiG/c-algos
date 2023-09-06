#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Array Array;

struct Array
{
    size_t length;
    int values[];
};

int binarySearch(int v[], size_t len, int n)
{
    size_t l = 0;
    size_t h = len;
    size_t m;
    do
    {
        m = (size_t)floor(l + (h - l) / 2);

        printf("l: %lu, m: %lu, h: %lu -> v[m]: %d \n", l, m, h, v[m]);
        
        if (v[m] == n)
        {   
            return v[m];
        }
        else if (v[m] < n)
        {
            l = m + 1;
        }
        else
        {
            h = m;
        };
    } while (l < h);

    return -1; // not found
};

int binarySearchArray(Array *h, int n)
{
    if (h == NULL)
    {
        return -1;
    }

    return binarySearch(h->values, h->length, n);
}

int main()
{
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
        printf("Initial Array: { ");
        for (size_t i = 0; i < *length; i++)
        {
            arr->values[i] = i;
            printf("%d ", arr->values[i]);
        }
        printf("}\n");

        int result = binarySearchArray(arr, *input_n);
        printf("Result: %d\n", result);

        free(arr); // 🫡
    }

    return 1;
}