#include <emscripten.h>
#include <stdio.h>

int main()
{
    printf("Hello from C!\n");

    // call JS function
    emscripten_run_script("console.log('js log called from C')");

    // call JS function async
    emscripten_async_run_script("alert('js alert called from C - async')", 2000); // 2000ms

    return 0;
}
