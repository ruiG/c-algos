#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct List List;

struct Node
{
    void *value;
    Node *next;
};

struct List
{
    size_t length;
    Node *head;
};

size_t length(List *l)
{
    return l->length;
}

void push(List *l, void *value)
{
    Node *n = malloc(sizeof(Node));

    // initialize the node
    n->value = value;
    n->next = NULL;

    if (l->head == NULL)
    {
        l->head = n;
        l->length = l->length + 1;
        return;
    }

    // find the tail
    Node *t = l->head;
    do
    {
        if (t->next == NULL)
        {
            t->next = n; // set the node
        }
        t = t->next;
    } while (t->next != NULL);

    l->length = l->length + 1;
    return;
}

int main()
{
    List *list;
    list->length = 0;
    list->head = NULL;

    struct Stuff
    {
        int value;
    };

    struct Stuff *things;
    things->value = 420;
    struct Stuff *otherStuff;
    otherStuff->value = 69;

    push(list, things);
    push(list, otherStuff);

    Node *n = list->head;
    while (n != NULL)
    {
        printf("Entry: %d \n", ((struct Stuff *)n->value)->value);
        n = n->next;
    }

    return 0;
}
