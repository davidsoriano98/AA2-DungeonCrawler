#pragma once
#include <vector>
#include <map>
#include <stdio.h>
using namespace std;

class Player
{
public:
	int playerX;
	int playerY;

	void SetPosX(int pX);
	void SetPosY(int pY);

	void moveUp(int pX, int pY, vector<vector<char>> map);
	void moveDown(int pX, int pY, vector<vector<char>> map);
	void moveLeft(int pX, int pY, vector<vector<char>> map);
	void moveRight(int pX, int pY, vector<vector<char>> map);
};

