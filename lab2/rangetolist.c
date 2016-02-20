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

node *convert(range list) {
    unsigned int i = 0;
    node *ans = malloc(sizeof(node) * list.length);
    if (list.length == 0) {
        return NULL;
    }
    for (i=0; i < list.length; i++) {
        ans[i].payload = list.ptr[i];
        ans[i].next = (i+1 < list.length) ? (ans + i + 1) : NULL;
    }
   return ans; 

}

