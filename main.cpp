#include <stdio.h>
#include <assert.h>

#include "colour.hpp"
#include "stack_functions.hpp"

int main()
{
    size_t a = 0;
    Stack_stucture my_stack;
    stack_initialiser (15, &my_stack);
    Stack_print(&my_stack);
    push (&my_stack, 10);
    a = pop(&my_stack);
    push (&my_stack, 13);
    push (&my_stack, 12);
    push (&my_stack, 11);
    Stack_print(&my_stack);
    printf ("%lu", a);
    destructor (&my_stack);
    return 0;
}




