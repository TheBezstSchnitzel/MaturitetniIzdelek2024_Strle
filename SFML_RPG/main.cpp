#include"stdafx.h"
#include"Game.h"
#include<Windows.h>

int main(){
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	
	Game game;

	game.run();

	return 0;
}