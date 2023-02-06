#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

char *global_str = "This is a string";
int global_int;
int foo(int);

int main()
{
    int integer = 0;
    char **heap_str = (char **) malloc(sizeof(char) * 100);
    *heap_str = "This is a string in the heap";
    printf("The content of the string in the heap:   %s\n", *heap_str);
    printf("The address of the string in the heap:   %p\n", heap_str);
    printf("The address of the pointer in the stack: %p\n\n", &heap_str);

    printf("The content of the global string:        %s\n", global_str);
    printf("The address of the global string:        %p\n", global_str);
    printf("The address of the global var in .data:  %p\n\n", &global_str);

    printf("Is             (NULL == 0)? => The expression returned %d\n", (NULL == 0));
    printf("Is ((uintptr_t) NULL == 0)? => The expression returned %d\n\n", ((uintptr_t) NULL == 0));

    foo(1);
    // scanf("%s", *heap_str); // For gdb
    return 0;
}

int foo(int flag)
{
    int (*foo_ptr) (int) = foo;
    if (flag) {
        foo_ptr(0);
    } else {
    }

    printf("This is in the function body of foo(), the value of passed argument: %d\n", flag);
    return 0;
}
