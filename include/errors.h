#ifndef ERRORS_H
# define ERRORS_H

void ptrace_error(void);

void wait_error(void);

void sscanf_error(void);

void printf_error(void);

void io_error(void);

void memory_error(void);

void elf_error(void);

void disasm_error(void);

void unwind_error(void);

void dwarf_error(void);

#endif /* ERRORS_H */
