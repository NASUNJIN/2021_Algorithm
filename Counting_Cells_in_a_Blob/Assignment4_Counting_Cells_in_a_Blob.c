#include <stdio.h>
#define BACKGROUND_PIXEL 0
#define IMAGE_PIXEL		 1
#define COUNTED			 2

int cells[][8] = {
	{0,0,1,0,0,0,0,1},
	{1,1,0,0,0,1,0,0},
	{0,0,1,0,1,0,1,0},
	{0,0,0,0,0,1,0,0},
	{0,1,0,1,0,1,0,0},
	{0,1,0,1,0,1,0,0},
	{1,0,0,0,1,1,0,0},
	{0,1,1,0,0,0,1,1}
};

int countCells(int x, int y) {
	
	if (x < 0 || x > 7 || y < 0 || y > 7)
		return 0;
	
	else if (cells[x][y] != IMAGE_PIXEL)
		return 0;

	else {
		cells[x][y] = COUNTED;
		return 1 + countCells(x, y - 1) + countCells(x + 1, y - 1) + countCells(x + 1, y)
			+ countCells(x + 1, y + 1) + countCells(x, y + 1) + countCells(x - 1, y + 1)
			+ countCells(x - 1, y) + countCells(x - 1, y - 1);
	}
}

int main() {
	printf("%d\n", countCells(3, 5));
}