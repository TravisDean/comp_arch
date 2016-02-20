#include <stdio.h>
int main() {
    char* test = "hello";
    test[0] = 103;
    test[1] = 111;
    test[2] = 111;
    test[3] = 100;
    printf("%s\n", test);

    return 0;
}
