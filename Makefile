all:
	rm -rf dist
	mkdir -p dist
	clang src/main.c -o dist/game -lSDL2 -lSDL2_image
