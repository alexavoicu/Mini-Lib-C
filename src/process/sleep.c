#include <time.h>
#include <unistd.h>

unsigned int sleep(unsigned int seconds) {
    struct timespec rqtp, rmtp;

    rqtp.tv_sec = (long) seconds;
    rqtp.tv_nsec = 0;
    rmtp.tv_sec = 0;
    rmtp.tv_nsec = 0;

    int res = nanosleep(&rqtp, &rmtp);

    if (res == 0) {
        return 0;
    }

    return rmtp.tv_sec;
}
