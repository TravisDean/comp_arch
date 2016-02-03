/* Write stand-alone ANSI C: */
#include <stdlib.h>
#include <stdio.h>

unsigned int mystrlen(const char *s) {
    int length = 0;
    while (*s++)
        length++;
    return length;
}

char *mystrsep( char **stringp, char delim ) {
    char *ans = *stringp;
    if (!*stringp) return NULL;

    while (**stringp != delim && **stringp != '\0')
        (*stringp)++;

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
    char parsethis[] = "This is a couple of words";
    
    char* str_p = parsethis;
    char* curr_token;

    printf("%s\n", hello);
    printf("%i\n", mystrlen(hello));

    while (str_p) {
        curr_token = mystrsep(&str_p, ' ');
        printf("%s\n", curr_token);
    }

    return 0;
}
