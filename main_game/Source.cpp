#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include "game.h"

int main() {
	game newInstance;
	std::cout << newInstance.startGame(50, 50);

	for (;;)
	{
		system("CLS");
		std::cout << newInstance.updateGame();
		Sleep(25);
	}

	return 0;
}