#ifndef CAPSTONE_WRAPPER_H
# define CAPSTONE_WRAPPER_H

# include <stddef.h>

struct my_instr
{
    char *str;

    size_t size;
};

void print_instructions(void *addr, size_t count);

struct my_instr *get_instruction(void *addr);

struct my_instr *get_current_instruction(void);

#endif /* CAPSTONE_WRAPPER_H */
