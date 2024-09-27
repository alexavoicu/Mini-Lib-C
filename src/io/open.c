// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	if (flags & O_CREAT || flags & O_TMPFILE) {
		va_list argument;
    	va_start(argument, flags);

		mode_t mode = va_arg(argument, mode_t);
		va_end(argument);

		int ret = syscall(2, filename, flags, mode);

		if (ret < 0) {
			errno = -ret;
			return -1;
		}

		return ret;
	}

	int ret = syscall(2, filename, flags);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}
