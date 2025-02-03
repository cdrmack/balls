all:
	emcc lib/demo.c -s WASM=1 -s EXPORTED_FUNCTIONS=_main,_foo,_hello -s EXPORTED_RUNTIME_METHODS=ccall -o public/demo.js
