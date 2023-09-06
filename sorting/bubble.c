#include <stdio.h>

void printArray(int arr[], size_t arr_size)
{
    printf("Array: { ");

    for (size_t i = 0; i < 6; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("}\n");
}

void bubbleSort(int arr[], size_t n)
{
    int temp;

    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {6, 4, 5, 1, 10, 0};
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, arr_size);

    printArray(arr, arr_size);
}