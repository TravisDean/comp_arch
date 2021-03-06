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

int lengthOf(node *list) {
    int i = 0;
    while (list) {
        list = list->next;
        i++;
    }
    return i;
}

TYPE *convert(node *list) {
    int i = 0;
    int length = lengthOf(list);
    TYPE *ans = malloc(sizeof(TYPE) * (length+1));
    
    while (list) {
        ans[i] = list->payload;
        list = list->next;
        i++;
    }
    ans[i] = sentinel;
    return ans;
}

