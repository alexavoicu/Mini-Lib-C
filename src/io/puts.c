#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int puts(const char *str) {
    ssize_t sum = 0, success = 0;
    size_t length = strlen(str);

    while ((size_t) sum < length) { // din documentatie https://man7.org/linux/man-pages/man2/write.2.html
        success = write(1, str + sum, strlen(str)-sum); // write nu garanteaza ca vor fi scrisi length bytes
        if (success == -1) {
            return -1;
        }
        sum = sum + success;
    }

    success = 0;
    sum = 0;

    while (sum == 0) {
        success = write(1, "\n", 1);
        if (success == -1) {
            return -1;
        }
        sum = sum + success;
    }

    return strlen(str) + 1;
}
