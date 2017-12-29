#include "memory.h"

#include <err.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "binary.h"
#include "format_utils.h"

char *read_memory(void *addr, size_t size)
{
    char *mem_path = get_proc_path("mem");

    int fd = open(mem_path, O_RDONLY);

    if (fd == -1)
    {
        warn("%s", mem_path);

        return NULL;
    }

    /*
    * Manual malloc error management here to prevent program stopping
    * if read_memory fails because user asked for too large memory
    * page using examine command.
    */
    char *buf = calloc((size / sizeof(size_t)
                        + ((size % sizeof(size_t)) ? 1 : 0))
                       * sizeof(size_t), 1);

    if (!buf)
    {
        warn("malloc failed");

        close(fd);

        return NULL;
    }

    ssize_t ret = pread(fd, buf, size, (off_t) addr);

    if (ret == -1)
        warn("pread failed");

    else if ((size_t) ret == size)
    {
        close(fd);

        return buf;
    }

    else
        warnx("Cannot read the whole requested memory");

    free(buf);

    close(fd);

    return NULL;
}
