#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "SlotMachine.h"

using namespace std;



int main()
{
    //Menu & Play Again
    bool playagain = 1;
    int gameselect; 
    //Player Money Variables 
    int playerstartmoney = 2000;
    int playermoney;
    int playermoney1; 
    playermoney = playerstartmoney;
    int jackpotpool = rand() % 7777 + 3333; 
    bool continuegame = true;


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
    2: Roulette Wheel
    3: BlackJack
    4: Credits

    5: EXIT 
            )" << '\n'; //Creating the Menu Welcome Message & ASCII Art 
        cout << "SELECTION: ";
        cin >> gameselect;
        cout << flush; // "Flushing" the console to avoid hundreds of lines of text and provide a better end user experience 
        system("CLS");

        if (gameselect == 1) {
            SlotSpin(playermoney, jackpotpool);
        }
        else if (gameselect == 2) {

        }
        else if (gameselect == 3) {

        }
        else if (gameselect == 4) {

        }
        else if (gameselect == 5) {

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


        return 0;
    }
    
}