#include <emscripten.h>
#include <stdio.h>

int main()
{
    printf("Hello from C!\n");

    // call JS function
    emscripten_run_script("console.log('js log called from C')");

    // call JS function async
    emscripten_async_run_script("alert('js alert called from C - async')",
                                2000); // 2000ms

    // get return value from the JS function
    int jsValInt = emscripten_run_script_int("getNum()");
    printf("Called js getNum(), it returned: %d\n", jsValInt);

    char *jsValStr = emscripten_run_script_string("getStr()");
    printf("Called js getStr(), it returned: %s\n", jsValStr);

    return 0;
}
