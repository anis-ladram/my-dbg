#include <err.h>
#include <stddef.h>
#include <stdio.h>

#include "breakpoints.h"
#include "commands.h"
#include "format_utils.h"

static void cmd_tbreak(size_t argc, char **argv)
{
    if (argc <= 1)
    {
        warn("No address specified");

        return;
    }

    void *addr = read_address(argv[1]);

    size_t nb = place_breakpoint(addr, MY_BP_TEMP);

    printf("Breakpoint %zu placed at %p\n", nb, addr);
}

register_command(tbreak,
                 PROGRAM_REQUIRED,
                 cmd_tbreak,
                 "Set a temporary breakpoint at specified addresses",
                 "tbreak <address>");
