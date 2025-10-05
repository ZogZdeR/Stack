#include <stdio.h>
#include <assert.h>

#include "colour.hpp"
#include "stack_functions.hpp"

int main()
{
    Stack_stucture my_stack;
    stack_initialiser (15, &my_stack);
    Stack_print(&my_stack);
    push (&my_stack, 10);
    Stack_print(&my_stack);
    return 0;
}




