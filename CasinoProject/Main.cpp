#include <iostream>
#include <cstdlib>
#include <ctime>
#define NOMINMAX
#include <Windows.h>
#include "SlotMachine.h"
#include "Blackjack.h"

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


    while (continuegame == true) {
     
        cout << R"(
    --WELCOME TO PATRICKS TOTALLY LEGAL C++ CASINO--
                  ____
                 /\' .\    _____
                /: \___\  / .  /\
                \' / . / /____/..\
                 \/___/  \'  '\  /
                          \'__'\/     

               -PLEASE SELECT A GAME- 
    1: Slot Machine
    2: BlackJack
    3: Credits

    4: EXIT 
            )" << '\n'; //Creating the Menu Welcome Message & ASCII Art 
        cout << "\n    SELECTION: ";

        while (!(cin >> gameselect)) { 
            cin.clear();    
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "\n    PLEASE ENTER A NUMBER NOT WORDS OR SPECIAL CHARACTERS\n";
            cout << "\n    SELECTION: ";
        }

        if (gameselect == 1) {
            //Loadbar();
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
            system("CLS");
            cout << "Created by Patrick Gleeson\n";
            Sleep(700);
            cout << "       April 2023\n";
            Sleep(700);
            cout << "   Thanks for Playing!\n";
            Sleep(2000);
            system("CLS");
        }
        else if (gameselect == 4) {
            return 0;
        }
        else if (gameselect > 4 or gameselect < 1) {
            cout << "    PLEASE ENTER A VALID NUMBER BETWEEN 1 & 4\n";
            cout << "\n    SELECTION: ";
            cin >> gameselect; 
            system("CLS");
        }
    }
    return 0;
}