```c
int foo()
{
    return 42;
}
```

```shell
_foo()
ccall('foo')
```

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

```shell
ccall('hello', 'string', ['string'], ['Bob'])
```

```js
const hello = cwrap('hello', 'string', ['string'])
```

```shell
hello('Bob')
```
