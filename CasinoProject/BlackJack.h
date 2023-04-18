#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>


int BlackJack(int& playermoney) {
	
	srand(time(0));
	int randnumplayer = rand() % 13 + 1;
	int randnumhouse = rand() % 13 + 1;
	int randsuiteplayer = rand() % 4 + 1;
	int randsuitehouse = rand() % 4 + 1;



}