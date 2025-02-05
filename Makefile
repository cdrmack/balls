all:
	emcc lib/demo.c -s WASM=1 -s EXPORTED_FUNCTIONS=_main,_foo,_hello -s EXPORTED_RUNTIME_METHODS=ccall,cwrap -o public/demo.js

demo:
	emcc lib/demo.c -s WASM=1 -s EXPORTED_FUNCTIONS=_main,_foo,_hello -s EXPORTED_RUNTIME_METHODS=ccall,cwrap -o public/demo.js

imports:
	emcc lib/imports.c -s WASM=1 -o public/imports.js
