#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

//assumes little endian
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = b[i] & (1<<j);
            byte >>= j;
            printf("%u", byte);
        }
        printf(" ");
    }
    puts("");
}

int main(int argc, char* argv[]) {
    unsigned int x = 1;
    printf ("little or big?\n");
    printf ("%d\n", (int) (((char *)&x)[0]));


    int n = 180482;
    printBits(sizeof(n), &n);
    int m = n >> 16;
    m |= n >> 8;
    m |= n >> 4;
    m |= n >> 2;
    m |= n >> 1;
    m &= 1;
    printBits(sizeof(m), &m);

    return 0;
}
