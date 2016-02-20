#include <stdio.h>
#include <stdlib.h>

unsigned int mystrlen(char* str) {
    int length = 0;
    while (*str++) {
        length++;
    }
    return length;
}

char* mystrsep(char** stringp, char delim) {
    char* ans = *stringp;
    if (!*stringp) return NULL;

    while (**stringp != delim &&  **stringp != '\0' ) {
        (*stringp)++;
    }

    if (**stringp == delim) {
        **stringp = '\0';
        (*stringp)++;
    } else {
        *stringp = 0;
    }

    return ans;
}

int main() {
    char hello[] = "Hello";
    char parse[] = "String to parse";

    char* str_p = parse;
    char* curr_token;

    printf("%s -> %d\n", hello, mystrlen(hello));

    while (str_p) {
        curr_token = mystrsep(&str_p, ' ');
        printf("%s\n", curr_token);
    }

    return 0;
}
