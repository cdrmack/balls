#include <stdio.h>
#include <string.h>

int main()
{
    printf("Hello from C!\n");
    return 0;
}

int foo()
{
    return 42;
}

char buffer[50];
char* hello(char *name)
{
    if (strlen(name) > 40)
    {
        return "Name is too long";
    }

    strcpy(buffer, "Hello ");
    return strcat(buffer, name);
}
