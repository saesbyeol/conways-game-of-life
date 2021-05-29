#pragma once
#include <string>
#include <sstream>
#include <vector>
//using namespace std;

class game
{
private:
	int rowSize;
	int columnSize;
	char cellAlive = 'O';
	char cellDead = '.';

	std::vector<std::vector<char>> matrix;
public:

	game& operator=(const game&) = delete;
	game();
	game(char cellAlive, char cellDead);
	std::string startGame(int rowSize, int columnSize);
	std::string playArea(std::vector<std::vector<char>> const& mat);
	bool genRnd();
	std::string updateGame();
	int neighboorNumber(int i, int j);
};

