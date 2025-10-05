#include "stack_functions.hpp"

Error stack_initialiser (size_t capacity, Stack_stucture *structure)
{
    if (structure == NULL) return struct_nullptr;
    structure->capacity = capacity;
    structure->size = 0;
    structure->Stack = (size_t*)calloc (capacity + 2, sizeof (int));
    structure->Stack[0] = cannary_contraception;
    structure->Stack[capacity + 1] = cannary_contraception;
    
    if (structure->Stack == NULL) return stack_nullptr;
    return OK;
}

Error verify (Stack_stucture *structure)
{ 
    if (structure == NULL)
    {
        printf (red "Structure pointer is nullptr" normal "\n");
        return struct_nullptr;
    }
    if (structure->capacity < structure->size) 
    {
        printf (red "Error : capacity < size" normal "\n");
        return bigger_size;
    }
    if (structure->Stack == NULL)
    {
        printf (red "Stack ptr is nullptr" normal "\n");
        return stack_nullptr;
    }
    if (structure->Stack[0] != cannary_contraception)
    {
        printf (red "Cannary shield's first ellement has been changed" normal "\n");
        return cannary_spoiled_beg;
    }
    if (structure->Stack[structure->capacity + 1] != cannary_contraception)
    {
        printf (red "Cannary shield's last ellement has been changed" normal "\n");
        return cannary_spoiled_end;
    }


    return OK;
}

void push (Stack_stucture *structure, size_t a)
{
    Error err = verify (structure);
    if (err == OK)
    {
        if (structure->size < structure->capacity)
        {
            structure->size ++;
            structure->Stack[structure->size + 1] = a;
        }
        else 
        {
            structure->capacity *= 2;
            structure->Stack = (size_t *)realloc (structure->Stack, structure->capacity);
            structure->size ++;
            structure->Stack[structure->size] = a;
        }
        err = verify (structure);
    }
    if (err != OK) 
    {
        print_error (err);
    }
}


size_t pop (Stack_stucture *structure)
{
    Error err = verify (structure);
    if (err == OK)
    {
        structure->size --;
        err = verify (structure);
    }
    if (err != OK) 
    {
        print_error (err);
        return 0xDEADDEAD;
    }
    return structure->Stack[structure->size + 1];
}

Stack_stucture* destructor (Stack_stucture *structure)
{
    free(structure->Stack);
    structure->Stack = NULL;
    return NULL;
}
void Dump (Stack_stucture *structure, Error err)
{
    print_error (err);
    printf (blue "Capacity = %lu" normal "\n", structure->capacity);
    printf (blue "Size = %lu" normal "\n", structure->size);
    printf (blue "StackPtr = %p" normal "\n", structure->Stack);
    Stack_print (structure);
}

void print_error (Error err)
{
    printf (red "Error code is %d" normal "\n"
        cyan "Error codes :" normal "\n"
        magenta "struct_nullptr = 1" normal "\n"
        magenta "stack_nullptr = 2" normal "\n"
        magenta "bigger_size = 3" normal "\n"
        magenta "cannary_spoiled_beg = 4" normal "\n"
        magenta "cannary_spoiled_end = 5" normal "\n", (int)err);
}

void Stack_print (Stack_stucture *structure)
{
for (size_t i = 1; i <= structure->size; i++)
{
    printf ("%lu ", structure->Stack[i]);
}
}


