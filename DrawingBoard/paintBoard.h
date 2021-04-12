#ifndef PAINT_BOARD_H
#define PAINT_BOARD_H
#include <filesystem>
#include "shape.h"

//画板类，包含着画板的各种操作
class PaintBoard
{
private:
	static size_t cancelCount;
	static size_t graphCount;
public:
	void initialize();
	void initGraph();
	void initText();
	void setGraphCount(size_t graphCount_);
	void clearPaint();
	void paintGraph(Shape& shape, bool isFill_);
	void paintData(size_t graphCount);
	int cancel();
	int restore();
	void writeToFile();
	void writeToFile(Shape& shape, const std::filesystem::path& path);
	void readFromFile(); 
	void setGraphColor(const Color& color);
	void deleteCancelGraph();
	void clearFile(const std::filesystem::path& path);
};

extern const std::filesystem::path tempFilePath;
extern const std::filesystem::path filePath;

#endif // PAINT_BOARD_H