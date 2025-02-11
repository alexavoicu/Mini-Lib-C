#include <time.h>
#include <errno.h>
#include <internal/syscall.h>

int nanosleep(const struct timespec *rqtp, struct timespec *rmtp) {
    int ret = syscall(35, rqtp, rmtp);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}
	return ret;
}
