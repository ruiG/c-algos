#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 5

typedef struct ArrayList ArrayList;

struct ArrayList
{
    size_t length;
    size_t cap;
    int *array;
};

ArrayList *init()
{
    ArrayList *arrl = malloc(sizeof(ArrayList));
    if (arrl == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    arrl->cap = CAPACITY;
    arrl->array = malloc(arrl->cap * sizeof(int));

    arrl->length = 0;

    if (arrl->array == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(arrl);
        return NULL;
    }

    return arrl;
}

int get(ArrayList *arrl, size_t i)
{
    if (arrl == NULL || i >= arrl->length)
    {
        fprintf(stderr, "Invalid access\n");
        return -1;
    }

    return arrl->array[i];
}

int set(ArrayList *arrl, size_t i, int value)
{
    if (arrl == NULL || i >= arrl->cap)
    {
        fprintf(stderr, "Invalid access\n");
        return -1;
    }
    arrl->length++;
    arrl->array[i] = value;

    return 0;
}

void resize(ArrayList *arrl, size_t newCapacity)
{
    if (arrl == NULL || newCapacity <= arrl->cap)
    {
        return;
    }

    int *newArray = malloc(newCapacity * sizeof(int));
    if (newArray == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    for (size_t i = 0; i < arrl->length; i++)
    {
        newArray[i] = arrl->array[i];
    }

    arrl->cap = newCapacity;
    free(arrl->array);
    arrl->array = newArray;
}

int main()
{
    ArrayList *list = init();
    if (list != NULL)
    {

        for (size_t i = 0; i < list->cap; i++)
        {
            set(list, i, i * 10);
        }

        for (size_t i = 0; i < list->cap; i++)
        {
            int el = get(list, i);
            printf("Element at [%zu]: %d\n", i, el);
        }
        
        resize(list, 200);
        
        for (size_t i = 0; i < list->cap; i++)
        {
            set(list, i, i * 10);
        }

        for (size_t i = 0; i < list->cap; i++)
        {
            int el = get(list, i);
            printf("Element at [%zu]: %d\n", i, el);
        }

        free(list->array);
        free(list);
    }
    return 0;
}