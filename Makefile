# -O3

all:
	emcc lib/canvas.c -s WASM=1 -s EXPORTED_FUNCTIONS=_main,_get_circles -s EXPORTED_RUNTIME_METHODS=ccall,cwrap -o public/canvas.js

demo:
	emcc lib/demo.c -s WASM=1 -s EXPORTED_FUNCTIONS=_main,_foo,_hello -s EXPORTED_RUNTIME_METHODS=ccall,cwrap -o public/demo.js

imports:
	emcc lib/imports.c -s WASM=1 -o public/imports.js

# doesn't work on FreeBSD
emrun:
	emcc lib/demo.c -s WASM=1 --emrun -o public/index.html
	emrun --port 8888 --hostname localhost --no_browser public/index.html
