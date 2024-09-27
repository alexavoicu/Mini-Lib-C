#ifndef __TIME_H__
#define __TIME_H__

typedef int time_t;

//time_t type https://man7.org/linux/man-pages/man3/time_t.3type.html
//implementarea timespec din https://man7.org/linux/man-pages/man3/timespec.3type.html

struct timespec {
    time_t tv_sec;
    long tv_nsec;
};

int nanosleep(const struct timespec *rqtp, struct timespec *rmtp);

#endif
