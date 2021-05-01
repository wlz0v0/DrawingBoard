#include <graphics.h>
#include "drawingBoard.h"

int main()
{
	DrawingBoard db;
	db.initialize();
	db.chooseOperations();
	db.exit();
	return 0;
}