all:
	emcc lib/demo.c -s WASM=1 -o public/demo.js
