Function written in C can be called from js.

```c
int foo()
{
    return 42;
}
```

```js
_foo()
ccall('foo')
```

When working with strings, js displays the memory location.
Emscripten provides useful functions that help with that.

```c
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
```

```js
ccall('hello', 'string', ['string'], ['Bob'])
const hello = cwrap('hello', 'string', ['string'])
hello('Bob')
```

We can trigger debugger on JS level from C code with `emscripten_debugger();`.
For debugging `emscripten_log(EM_LOG_WARN, "foo");` can also be useful (it includes stack trace).
