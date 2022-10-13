#include "Player.h"

//SETTERS
void Player::SetPosX(int pX)
{
	playerX = pX;
}
void Player::SetPosY(int pY)
{
	playerY = pY;
}

void Player::moveUp(int pX, int pY, vector<vector<char>> map)
{
    if (map[pX][pY - 1] != 'X') {
        playerY--;
    }
}

void Player::moveDown(int pX, int pY, vector<vector<char>> map)
{
    if (map[pX][pY - 1] != 'X') {
        playerY++;
    }
}

void Player::moveLeft(int pX, int pY, vector<vector<char>> map)
{
    if (map[pX][pY - 1] != 'X') {
        playerX--;
    }
}

void Player::moveRight(int pX, int pY, vector<vector<char>> map)
{

    if (map[pX][pY - 1] != 'X') {
        playerX++;
    }
}