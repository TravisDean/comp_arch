#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUF_SIZE 100

int main() {
    int i;
    int pID;
    char buf[BUF_SIZE];

    for (i = 0; i < 4; i++) {
        pID = fork();
        if (pID != -1) {
            sprintf(buf, "this process %i at i=%d spawned a pID=%d\n", getpid(), i, pID);
            write(1, buf, strlen(buf));
        }
    }
    return 0;
}
