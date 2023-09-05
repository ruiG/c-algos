#include <stdio.h>
#include <stdlib.h>

int main()
{
    int bar = 0;
    int *p = malloc(sizeof(int));

    *p = 100;
    // clear screen
    system("clear");

    printf("bar: %d @ %p\n", bar, &bar);

    printf("value at p:  %d\n", *p);  // value at p
    printf("pointer p:   %p\n", p);   // pointer value in hex
    printf("pointer's at: %p\n", &p); // pointer address in hex

    free(p);
    printf("after free: \n");
    printf("value at p:  %d\n", *p);  // value at p
    printf("pointer p:   %p\n", p);   // pointer value in hex
    printf("pointer's at: %p\n", &p); // pointer address in hex

    printf("Wild 🤠 pointer: \n");
    void *c;           // wild pointer
    printf("%p\n", c); // I think it defaults to 0 in cc
    
    return 0;
}
