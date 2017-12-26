#include <stddef.h>

#include "commands.h"
#include "libunwind_wrapper.h"

static void cmd_backtrace(size_t argc, char **argv)
{
    (void)argc;

    (void)argv;

    print_backtrace();
}

register_command(backtrace,
                 cmd_backtrace,
                 "Print backtrace",
                 "backtrace");
