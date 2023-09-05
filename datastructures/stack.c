#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Stack Stack;

struct Node
{
  int value; // make it generic? 
  Node *prev;
};

struct Stack
{
  size_t length;
  Node *top;
};

size_t length(Stack *stk)
{
  return stk->length;
}

void push(Stack *stk, int value)
{
  Node *nt = malloc(sizeof(Node));

  // intialize the Node
  nt->value = value;
  nt->prev = stk->top;

  stk->top = nt; // set as the new top

  stk->length = ++stk->length;
  return;
}

// pop
int pop(Stack *stk)
{
  Node *top = stk->top;

  if (stk->length <= 0 || top == NULL)
  {
    return 0; // derp
  }

  // update the stack
  stk->top = top->prev;
  stk->length = --stk->length;

  // get the value to return
  int val = top->value;

  // free the memory
  free(top);
  return val;
}

int main()
{
  Stack *stk;
  stk->length = 0;
  stk->top = NULL;

  push(stk, 1);
  push(stk, 2);
  push(stk, 3);
  push(stk, 69);

  for (size_t i = 0; i < 10; ++i)
  {
    printf("[%zu] top of stack is: %d\n", i, pop(stk));
    printf("[%zu] length is: %zu\n", i, stk->length);
  }

  return 0;
}