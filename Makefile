CC = gcc

CPPFLAGS =  \
-Iinclude/ \
-Iinclude/infos/ \
-Iinclude/utils/ \
-Iinclude/wrappers/ \
-Icapstone/ \
-D_GNU_SOURCE \
-MMD

CFLAGS = -Wall -Werror -Wextra -std=c99 -pedantic

LDLIBS = \
-lreadline -lhistory \
-lcapstone \
-lunwind -lunwind-ptrace -lunwind-x86_64 

VPATH = src/:src/utils/:src/commands/:src/wrappers/:src/infos/

FILES = \
my-dbg.c \
commands.c \
prompt.c \
array_utils.c \
string_utils.c \
memory_utils.c \
format_utils.c \
file_utils.c \
temp_memory_utils.c \
exceptions.c \
cmd_quit.c \
cmd_info_regs.c \
cmd_info_memory.c \
cmd_break.c \
cmd_continue.c \
cmd_step_instr.c \
cmd_examine.c \
cmd_backtrace.c \
cmd_tbreak.c \
cmd_next_instr.c \
cmd_attach.c \
cmd_breakf.c \
cmd_breaks.c \
cmd_break_list.c \
cmd_break_del.c \
cmd_disassemble.c \
cmd_finish.c \
cmd_list.c \
cmd_breakl.c \
binary.c \
breakpoints.c \
registers.c \
memory.c \
mem_mappings.c \
errors.c \
syscalls.c \
libunwind_wrapper.c \
capstone_wrapper.c \
my_syscalls.c \
my_elf.c \
gnu_hash_table.c \
my_dwarf.c \
dwarf_state_machine.c

OBJS = $(FILES:%.c=%.o)

BIN = my-dbg

all: $(BIN)

$(BIN): $(OBJS)

debug: CFLAGS += -g3
debug: CFLAGS += -O0
debug: LDFLAGS += -g3
debug: CPPFLAGS += -DMY_DEBUG
debug: all

clean-objs:
	$(RM) $(OBJS) $(OBJS:.o=.d)

clean:
	$(RM) $(BIN) $(OBJS) $(OBJS:.o=.d)

-include $(OBJS:.o=.d)
