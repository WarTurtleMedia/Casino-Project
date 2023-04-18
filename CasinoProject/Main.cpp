#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "SlotMachine.h"
#include "Blackjack.h"

using namespace std;



int main()
{
    //Menu & Play Again
    bool playagain = 1;
    //Player Money Variables 
    int playerstartmoney = 2000;
    int playermoney;
    playermoney = playerstartmoney;
    srand(time(0));
    int jackpotpool = rand() % 7777 + 3333; 
    bool continuegame = true;
   


    while (continuegame == true) {
        int gameselect;
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
    2: Roulette Wheel
    3: BlackJack
    4: Credits

    5: EXIT 
            )" << '\n'; //Creating the Menu Welcome Message & ASCII Art 
        cout << "SELECTION: ";
        cin >> gameselect;
        system("CLS");

        if (gameselect == 1) {
            SlotSpin(playermoney, jackpotpool);
            system("CLS");
        }
        else if (gameselect == 2) {
            BlackJack(playermoney);
            system("CLS");
        }
        else if (gameselect == 3) {

        }
        else if (gameselect == 4) {
            cout << "Created by Patrick Gleeson\n";
            Sleep(700);
            cout << "       April 2023\n";
            Sleep(700);
            cout << "   Thanks for Playing!\n";
            Sleep(2000);
            system("CLS");
        }
        else if (gameselect == 5) {
        
            return 0;
        }
        else {
            cout << "Invalid Selection Please Enter an Option from the list \n";
            for (int i = 5; i >= 0; --i) { //Countdown Timer to ensure the player reads the message (5 Seconds)
                cout << i << " ";
                Sleep(1000);
               
                if (i == 0) {
                    system("CLS"); //Clears the screen once the timer hits 0 
                }
            }
        }
        
    }
    return 0;
}