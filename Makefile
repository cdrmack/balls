all:
	emcc lib/demo.c -s WASM=1 -s EXPORTED_FUNCTIONS="['_foo']" -o public/demo.js
