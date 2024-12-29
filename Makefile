SHELL=/bin/bash

output := minesweeperxl

minesweeperxl: $(wildcard src/*)
	@printf "Building $(output)\n"
	@c++ src/main.cpp -lSDL2 -lSDL2_ttf -o $(output)
	@printf "Successfully built $(output)\n"

test: $(wildcard src/*)
	@printf "Building $(output)\n"
	@c++ src/Test.cpp -lSDL2 -lSDL2_ttf -o $(output)
	@printf "Successfully built $(output)\n"

clean:
	@rm -f "./$(output)"
	@printf "Successfully deleted $(output)\n"
