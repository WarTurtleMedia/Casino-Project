#include <iostream>
#include <cstdlib>
#include <ctime>
//#include <Windows.h>
#include "General.h"


using namespace std;

void BlackJack(int& playermoney) {
	
	srand(time(0));
	//int randnumplayer = rand() % 13 + 1;
	//int randnumhouse = rand() % 13 + 1;
	//int randsuiteplayer = rand() % 4 + 1;
	//int randsuitehouse = rand() % 4 + 1;
	int gameturn = 0; 
	bool playerdraw;
	//cout << randnumplayer << "\n" << randnumhouse << "\n" << randsuiteplayer << "\n" << randsuitehouse;
	const int king = 11;
	const int queen = 12; 
	const int jack = 13;
	const int ace = 1;
	int sumover21;



	int playerhand[5]= {0, 0, 0, 0 ,0};
	int sum = 0; 
	int test; //remove at some point 
	while (gameturn < 5)
	{
		
		
		int randnumplayer = rand() % 13 + 1; // Generates a new card value for the player if they choose to draw 
		//SETTING CARD LOGIC

		sumover21 = sum + 11; //Adds the Sum of Cards and the value of ace if it was 11

		cout << randnumplayer << "\n\n\n\n";
		
		if (randnumplayer == king or randnumplayer == jack or randnumplayer == queen) {
			randnumplayer = 10;
		}
		else if (randnumplayer == ace and sumover21 >= 21) { // If players Ace (11) card + their currents cards sum is more than 21 the ace is worth 1
			randnumplayer = 1;
		}
		else if (randnumplayer == ace and sumover21 <= 21) { // If players Ace (11) card + their currents cards sum is less than 21 the ace is worth 11
			randnumplayer = 11;
		}

		for (int i = 0; i < 5; ++i) //Prints the players current cards to the screen 
		{
			cout << " [" << playerhand[i] << "] ";
			
		}
		
		cout << "\nCurrent Total = " << sum; 
		
		if (gameturn > 0) {
			cout << "\nDraw? : ";
			cin >> playerdraw; //Player Decides if they want to draw 

		}
		
		playerhand[gameturn] = randnumplayer; //Assigns the Array postions that corlates with the gameturn a random value for the players card 
		sum = sum + playerhand[gameturn]; //Players total card value

											  //Add dealers card here 

		if (gameturn == 4) {
			system("CLS");
			for (int i = 0; i < 5; ++i) //Prints the players current cards to the screen 
			{
				cout << " [" << playerhand[i] << "] ";

			}
		}
		
		if (sum > 21) {
			cout << "\nLOSE\n";
			cout << sum; 
			cin >> test;
		}
		else if (sum == 21) {
			cout << "\nWIN\n";
			cout << sum;
			cin >> test;
		}

		//if playerdraw 

		system("CLS");
		gameturn++; //Increases the game turns 
		
		

	}














	/*
	while (gameturn < 6) {
		//system("CLS");
		int sum = 0;
		int randnumplayer = rand() % 13 + 1;
		
		

		for (int i = 0; i < 5; ++i)
		{
			cout << " [" << playerhand[i] << "] ";	
		} 
		for (int j = 0; j < 5; j++) //For loop adding the Players hand up 
		{
			sum = sum + playerhand[j];
		}

		
		cout << "\nCurrent Total = " << sum;
		cout << "\nDraw? : ";
		gameturn++;
		cin >> playerdraw;
		cout << "\nBUST AFTER 5 DRAWS";

		if (playerdraw == true) {
				
			char intconvert = randnumplayer;
			playerhand[gameturn] = intconvert;
			
		}
		else if (playerdraw == false) {
			for (int i = 0; i < 5; ++i)
			{
				cout << " [" << playerhand[i] << "] ";
			}
			cout << "\nYour Total = " << sum;
			if (sum > 21) // CHANGE CHECKING WIN T0 A FUNCTION
			{
				cout << "YOU LOSE";
			}

			else if (sum == 21) {
				cout << "BLACKJACK";
			}

			else  {
				cout << "BLACKJACK 22";
			}

		} 	

	
		 

	}
			*/
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