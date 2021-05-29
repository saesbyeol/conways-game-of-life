#include <time.h>
#include <random>
#include <chrono>
#include "game.h"

game::game()
{
	srand(time(NULL));
}

game::game(char cellAlive, char cellDead)
{
	srand(time(NULL));
	this->cellDead = cellDead;
	this->cellAlive = cellAlive;
}

std::string game::startGame(int rowSize, int columnSize)
{
	this->rowSize = rowSize;
	this->columnSize = columnSize;

	for (int i = 0; i < rowSize; i++)
	{
		std::vector<char> pomocniV;
		for (int j = 0; j < columnSize; j++)
		{
			pomocniV.push_back((genRnd() == 1) ? (this->cellAlive) : (this->cellDead));
		}
		this->matrix.push_back(pomocniV);
	}

	return playArea(matrix);
}

std::string game::playArea(std::vector<std::vector<char>> const& mat)
{
	std::stringstream cont;

	for (std::vector<char> row : mat) {
		for (char value : row) {
			cont << value << " ";
		}
		cont << '\n';
	}

	return cont.str();
}

bool game::genRnd()
{
	auto funkcija1 = []() -> int {return rand() & 1; };
	auto funkcija2 = [&]() -> bool {return (funkcija1() | funkcija1()); };

	return 1 - (funkcija2());
}

std::string game::updateGame()
{
	std::stringstream cont;

	for (int i = 0; i < this->matrix.size(); i++)
	{
		for (int j = 0; j < this->matrix[i].size(); j++)
		{

			int brojac = neighboorNumber(i, j);

			if ((this->matrix[i][j] == this->cellAlive) && (brojac < 2))
			{
				this->matrix[i][j] = this->cellDead;
			}

			if ((this->matrix[i][j] == this->cellAlive) && (brojac > 3)) {
				this->matrix[i][j] = this->cellDead;
			}

			if ((this->matrix[i][j] == this->cellAlive) && (brojac == 2 || brojac == 3)) {
				this->matrix[i][j] = this->cellAlive;
			}

			if ((this->matrix[i][j] == this->cellDead) && (brojac == 3)) {
				this->matrix[i][j] = this->cellAlive;
			}

			cont << this->matrix[i][j] << " ";
		}
		cont << '\n';
	}



	return cont.str();
}

int game::neighboorNumber(int i, int j)
{
	int brojac = 0;

	if (i != (matrix.size() - 1))
	{
		if (this->matrix[i + 1][j] == this->cellAlive)
		{
			brojac += 1;
		}
	}

	if (i != (matrix.size() - 1) && j != (matrix.size() - 1))
	{
		if (this->matrix[i + 1][j + 1] == this->cellAlive)
		{
			brojac++;
		}
	}

	if (j != (matrix.size() - 1))
	{
		if (this->matrix[i][j + 1] == this->cellAlive)
		{
			brojac++;
		}
	}

	if ((i != 0) && (j != (matrix.size() - 1)))
	{
		if (this->matrix[i - 1][j + 1] == this->cellAlive)
		{
			brojac++;
		}
	}

	if ((i != 0))
	{
		if (this->matrix[i - 1][j] == this->cellAlive)
		{
			brojac++;
		}
	}

	if ((i != 0) && (j != 0))
	{
		if (this->matrix[i - 1][j - 1] == this->cellAlive)
		{
			brojac++;
		}
	}

	if ((j != 0))
	{
		if (this->matrix[i][j - 1] == this->cellAlive)
		{
			brojac++;
		}
	}

	if (i != (matrix.size() - 1) && (j != 0))
	{
		if (this->matrix[i + 1][j - 1] == this->cellAlive)
		{
			brojac++;
		}
	}


	return brojac;
}
