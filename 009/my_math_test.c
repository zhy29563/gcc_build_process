#include <stdio.h>
#include "my_math_add.h"
#include "my_math_sub.h"

int main(int argc, char *argv[])
{
    printf("my_math >> my_math_add: 3 + 4 = %d\n", my_math_add(3, 4));
    printf("my_math >> my_math_sub: 3 - 4 = %d\n", my_math_sub(3, 4));
    return 0;
}