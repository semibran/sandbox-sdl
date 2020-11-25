all:
	rm -rf dist
	mkdir -p dist
	clang src/main.c -lSDL2 -o dist/game
