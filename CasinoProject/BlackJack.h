#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "General.h"


using namespace std;

void BlackJack(int& playermoney) {
	
	srand(time(0));
	//int randnumplayer = rand() % 13 + 1;
	int randnumhouse = rand() % 13 + 1;
	int randsuiteplayer = rand() % 4 + 1;
	int randsuitehouse = rand() % 4 + 1;
	int gameturn = 0; 
	bool playerdraw = true;
	//cout << randnumplayer << "\n" << randnumhouse << "\n" << randsuiteplayer << "\n" << randsuitehouse;

	int playerhand[5]{0, 0, 0, 0 ,0};

	while (gameturn != 5) {
	

		while (playerdraw == true) {
			system("CLS");
			int sum = 0;
			int randnumplayer = rand() % 13 + 1;

			for (int i = 0; i < 5; ++i)
			{
				cout << " [" << playerhand[i] << "] ";
				
			} 
			cout << "\nBUST AFTER 5 DRAWS";
			if (playerdraw == true) {
				
				int sum = 0;
				for (int i = 0; i < 5; ++i) //For loop adding the Players hand up 
				{
					sum = sum + playerhand[i];
				}

				char intconvert = randnumplayer;
				playerhand[gameturn] = intconvert;
				gameturn++;
				cout << "\nCurrent Total = " << sum;
				cout << "\nDraw? : "; 
				cin >> playerdraw;


				
				
			}
			else if (playerdraw == false) {
			}


			

	    }		
	}
}





















/*const string blankcard = " _______\n"
							  "|       |\n"
							  "|       |\n"
							  "|       |\n"
							  "|       |\n"
							  "|_______|\n";
	string playercards[2][2] = {blankcard, blankcard, blankcard, blankcard};

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j) // columns
		{
			cout << playercards[i][j];
		}
	}
	*/