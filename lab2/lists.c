// void free(void *ptr);
// void *malloc(int size);
// int printf(const char *format, ...);
#include <stdio.h>

/* The following #ifdef and its contents need to remain as-is. */
#ifndef TYPE
#define TYPE short
TYPE sentinel = -1234;
#else
extern TYPE sentinel;
#endif

/* typedefs needed for this task: */
typedef struct node_t { TYPE payload; struct node_t *next; } node;
typedef struct range_t { unsigned int length; TYPE *ptr; } range;

int lengthOf(node *list) {
    int i=0;
    while(list) {
        list = list->next;
        i++;
    }
    return i;
}

range convert(node *list) {
    int i = 0;
    int length = lengthOf(list);
    range ans;
    ans.length = length;
    ans.ptr = malloc(sizeof(TYPE) * length);

    while (list) {
        ans.ptr[i] = list->payload;
        list = list->next;
        i++;
    }

    return ans;



    
}

