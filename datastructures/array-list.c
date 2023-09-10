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

int set(ArrayList *arrl, size_t i, int value){
    if(arrl == NULL || i >= arrl->length) {
        fprintf(stderr, "Invalid access\n");
        return -1;
    }

    arrl->array[i] = value;

    return 0;
}

int main()
{
    ArrayList *list = init();
    if (list != NULL)
    {
        set(list, 0, 420);
        int head = get(list, 0);
    
        printf("Element: %d\n", head);

        free(list->array);
        free(list);
    }
    return 0;
}