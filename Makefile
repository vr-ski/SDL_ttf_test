output := minesweeperxl

minesweeperxl: $(wildcard src/*)
	c++ src/main.cpp -lSDL2 -lSDL2_ttf -o $(output)

clean:
	rm -f "./$(output)"