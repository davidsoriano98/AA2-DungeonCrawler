#pragma once
#include <vector>

class Map
{
private:
	int rows;
	int cols;
public:
	std::vector <vector<char>> mapHeader;
	void initMap();
	void printMap();
};