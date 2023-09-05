#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Queue Queue;

struct Node
{
  int value;
  Node *next;
};

struct Queue
{
  size_t length;
  Node *head;
  Node *tail;
};

int enque(Queue *q, int val)
{
  Node *nt = malloc(sizeof(Node));
  if (nt == NULL)
  {
    return -1; // ERROR 💥
  }
  // intialize
  nt->value = val;
  nt->next = NULL;

  // update the tail
  if(q->tail != NULL) {
    q->tail->next = nt;
  }

  q->tail = nt;

  // if Q is empty it's also the head
  if (q->length == 0)
  {
    q->head = nt;
  }

  q->length = ++q->length;

  return 0; // GREAT SUCCESS 🎉
}

int deque(Queue *q)
{
  if (q->length == 0 || q->head == NULL)
  {
    return -1;
  }
  Node *head = q->head;

  q->head = head->next;
  q->length = --q->length;

  return head->value;
}

int main()
{
  Queue *q;
  q->length = 0;
  q->head = NULL;
  q->tail = NULL;

  enque(q, 11);
  enque(q, 22);
  enque(q, 33);
  enque(q, 44);

  for (size_t i = 0; i < 10; ++i)
  {
    printf("[%zu] front of queue is: %d\n", i, deque(q));
    printf("[%zu] length is: %zu\n", i, q->length);
  }

  return 0;
}