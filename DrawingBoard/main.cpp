#include <graphics.h>
#include "drawingBoard.h"

int main()
{
	DrawingBoard db;
	db.initialize();
	db.chooseOperations();
	closegraph();
	return 0;
}