#include <stdio.h>
#include <emscripten.h>

int main()
{
    printf("init circles\n");
    emscripten_run_script("render()");
    return 0;
}
