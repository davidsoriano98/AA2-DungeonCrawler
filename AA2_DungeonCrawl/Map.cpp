#include "Map.h"
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>
#include "Player.h"
using namespace std;

void Map::initMap()
{
	Player player;

	ifstream configFile("Config.txt");
	rows = 0;
	cols = 0;

	configFile >> noskipws;

	configFile >> rows;
	cin.ignore(';');
	configFile >> cols;
	cin.ignore(';');

	std::vector<vector<char>> map;
	map.resize(rows, std::vector<char>(cols));

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			char tile;
			configFile >> tile;
			switch (tile)
			{
			case 'J':
			{
				player.SetPosX(j);
				player.SetPosY(i);
				break;
			}
		
			case ' ':
			{
				break;
			}
			default:
			{
				break;
			}
			}
			map[i][j] = tile;
		}
	}

	//Map::mapHeader = map;
}

void Map::printMap()
{
	for (int i = 0, j = 0; i < rows, j < cols; j++)
	{
		cout << mapHeader[i][j];
		if (i == rows - 1)
		{
			cout << "\n";
			j = 0;
			i++;
		}
	}
}