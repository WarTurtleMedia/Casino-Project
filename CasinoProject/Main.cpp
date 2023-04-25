#include <iostream>
#include <cstdlib>
#include <ctime>
#define NOMINMAX
#include <Windows.h>
#include "General.h"
#include "SlotMachine.h"
#include "Blackjack.h"
using namespace std;
using namespace std;

int main()
{
    

    //Menu & Play Again
    //bool playagain = 1;
    //Player Money Variables 
    int playerstartmoney = 2000;
    int playermoney;
    playermoney = playerstartmoney;
    srand(time(0));
    int jackpotpool = rand() % 7777 + 3333; 
    
    
    bool continuegame = true;
    int gameselect;
    //Loadbar();
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);

    while (continuegame == true) {
        
        SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_INTENSITY); //Sets the Text to Light Red
        DrawMainMenu(); //Function to Draw the Main Menu

        while (!(cin >> gameselect)) { //Error checking for strings or characters 
            cin.clear();    
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            DrawBoxErrorCheck(4, 8); //Starts the procces to output a message to the user they need to enter a number
            SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_INTENSITY);
            SetPos(17, 10);
            cout << "PLEASE ENTER A NUMBER";
            SetPos(12, 11);
            cout << "NOT WORDS OR SPECIAL CHARACTERS";
            Sleep(2000); //Delay to ensure player can read the message box
            SetPos(0, 0);
            DrawMainMenu(); //Removes the Message box by drawing main menu over it 
            
        }

        if (gameselect == 1) {
            
           
            //Loadbar(9,8);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Sleep(100);
            system("CLS");
            SlotSpin(playermoney, jackpotpool);
            system("CLS");
        }

        else if (gameselect == 2) {
            //Loadbar();
            system("CLS");
            BlackJack(playermoney);
            system("CLS");
        }

        else if (gameselect == 3) {  
            SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            DrawBoxMedium(9,8);
            SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_INTENSITY);
            SetPos(13, 11);
            cout << "Created by Patrick Gleeson";
            Sleep(700);
            SetPos(20, 12);
            cout << "April 2023";
            Sleep(700);
            SetPos(13, 14);
            cout << "First Year Game Dev Student";
            SetPos(16, 15);
            SetConsoleTextAttribute(Console, FOREGROUND_RED);
            cout << "@ Media Design School";
            Sleep(2000);
            DrawMainMenu();
        }

        else if (gameselect == 4) 
        {

            system("CLS");

            //DrawSlotMachine(5, 3);
            Sleep(200000);
            return 0;
        }

        else if (gameselect > 4 or gameselect < 1)
        {
            SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            DrawBoxErrorCheck(4, 8);
            SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_INTENSITY);
            SetPos(7, 10);
            cout << "PLEASE ENTER A VALID NUMBER BETWEEN ";
            SetConsoleTextAttribute(Console, FOREGROUND_RED);
            cout << "1";
            SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << " & ";
            SetConsoleTextAttribute(Console, FOREGROUND_RED);
            cout << "4";
            SetPos(16, 11);
            cout << gameselect; 
            SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << " Is not a valid option";
            Sleep(2000);
            DrawMainMenu();
        }
    }
    return 0;
}