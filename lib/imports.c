#include <emscripten.h>
#include <stdio.h>

int main()
{
    printf("Hello from C!\n");

    // call JS function
    emscripten_run_script("console.log('js log called from C')");

    return 0;
}
