#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std; 

int SlotSpin(int& playermoney, int& jackpotpool) {
    
    // Creating the Random Numbers 
    srand(time(0));
    int randnum1 = (rand() % 99) + 1;
    int randnum2 = (rand() % 99) + 1;
    int randnum3 = (rand() % 99) + 1;

    bool slotplayagain = true; 

    const int slotstwo = 2;
    const int slotsthree = 3;
    const int slotsfour = 4;
    const int slotsfive = 5;
    const int slotssix = 6;
    const int slots10x = 7;
    const string slotsjackpot = "! ! - JACKPOT - ! !";

    int outputleft = 0;
    int outpoutmid = 0;
    int outputright = 0;
    
    int playerbet = 0;

    while(slotplayagain == true )
    {
        cout << "CURRENT JACKPOT :" << jackpotpool << "\n";
        cout << "Remaining Balance : " << playermoney << "\nPlease Enter a Bet : ";
        cin >> playerbet;
       
        if (playerbet > 0 && playerbet <= playermoney) {
            playermoney = playermoney - playerbet; //Removing players bet from their total balance 
       
            if (randnum1 >= 1 && randnum1 <= 19) //19% Chance to output '2'
            {
                randnum1 = 2; 
                cout << slotstwo << " ";
            }
            else if (randnum1 >= 20 && randnum1 <= 38) //19% Chance to output '3'
            {
                randnum1 = 3;
                cout << slotsthree << " ";
            }
            else if (randnum1 >= 39 && randnum1 <= 57) //19% Chance to output '4'
            {     
                randnum1 = 4;
                cout << slotsfour << " ";
            }
            else if (randnum1 >= 58 && randnum1 <= 76) //19% Chance to output '5'
            {      
                randnum1 = 5;
                cout << slotsfive << " ";
            }
            else if (randnum1 >= 77 && randnum1 <= 95) //19% Chance to output '6'
            {
                randnum1 = 6;
                cout << slotssix << " ";
            }
            else if (randnum1 >= 96 && randnum1 <= 99) //19% Chance to output '7'
            {
                randnum1 = 7;
                cout << slots10x << " ";
            }
            else if (randnum1 == 100) //1% Chance to output '7'
            {
                randnum1 = 100;
                cout << slotsjackpot << " ";
            }


            if (randnum2 >= 1 && randnum2 <= 19) 
            {
                randnum2 = 2;
                cout << slotstwo << " ";
            }
            else if (randnum2 >= 20 && randnum2 <= 38) 
            {
                randnum2 = 3;
                cout << slotsthree << " ";
            }
            else if (randnum2 >= 39 && randnum2 <= 57) 
            {
                randnum2 = 4;
                cout << slotsfour << " ";
            }
            else if (randnum2 >= 58 && randnum2 <= 76) 
            {
                randnum2 = 5;
                cout << slotsfive << " ";
            }
            else if (randnum2 >= 77 && randnum2 <= 95) 
            {
                randnum2 = 6;
                cout << slotssix << " ";
            }
            else if (randnum2 >= 96 && randnum2 <= 99) 
            {
                randnum2 = 7;
                cout << slots10x << " ";
            }
            else if (randnum2 == 100) 
            {
                randnum2 = 100;
                cout << slotsjackpot << " ";
            }


            if (randnum3 >= 1 && randnum3 <= 19) 
            {
                randnum3 = 2;
                cout << slotstwo << " ";
            }
            else if (randnum3 >= 20 && randnum3 <= 38) 
            {
                randnum3 = 3;
                cout << slotsthree << " ";
            }
            else if (randnum3 >= 39 && randnum3 <= 57) 
            {
                randnum3 = 4;
                cout << slotsfour << " ";
            }
            else if (randnum3 >= 58 && randnum3 <= 76) 
            {
                randnum3 = 5;
                cout << slotsfive << " ";
            }
            else if (randnum3 >= 77 && randnum3 <= 95) 
            {
                randnum3 = 6;
                cout << slotssix << " ";
            }
            else if (randnum3 >= 96 && randnum3 <= 99) 
            {
                randnum3 = 7;
                cout << slots10x << " ";
            }
            else if (randnum3 == 100) 
            {
                randnum3 = 100;
                cout << slotsjackpot << " ";
            }

            if (randnum1 == 7 && randnum1 == randnum2 && randnum1 == randnum3) //If three numbers are Equal to 7 then player earns back 10x their bet
            {
                cout << "\n\n++WIN++\n\n";
                cout << "++! TRIPLE SEVENS !++\n";
                cout << "BET 10X: " << playerbet * 10 << "\n";
                playermoney = playermoney + (playerbet * 10);
                cout << "Balance: " << playermoney << "\n";
                cout << "Spin Again?: ";
                cin >> slotplayagain;
                system("CLS");
            }
            else if (randnum1 == 100 && randnum1 == randnum2 && randnum1 == randnum3) //If three numbers are Equal to 100 then player wins the jackpot 
            {
                cout << "\n\n++WIN++\n\n";
                cout << "++! ! - JACKPOT - ! !++\n";
                cout << "JACKPOT: " << jackpotpool << "\n";
                playermoney = playermoney + jackpotpool;
                cout << "Balance: " << playermoney << "\n";
                cout << "Spin Again?: ";
                cin >> slotplayagain;
                system("CLS");
            }
            else if (randnum1 == randnum2 && randnum1 == randnum3 && randnum1 != 7 && randnum1 != 100) //If three numbers are Equal then player earns back 5x their bet
            {
                cout << "\n\n++WIN++\n";
                cout << "BET 5X:" << playerbet * 5 << "\n";
                playermoney = playermoney + (playerbet * 5);
                cout << "Balance: " << playermoney << "\n";
                cout << "Spin Again?: ";
                cin >> slotplayagain;
                system("CLS");
            }
  
            else if (randnum1 == randnum2 or randnum1 == randnum3 or randnum3 == randnum2) //If two numbers are Equal then player earns back 3x their bet
            {
                cout << "\n\n++WIN++\n\n";
                cout << "BET 3X: " << playerbet * 3 << "\n";
                playermoney = playermoney + (playerbet * 3);
                cout << "Balance: " << playermoney << "\n";
                cout << "Spin Again?: ";
                cin >> slotplayagain;         
                system("CLS");
            }
            else 
            {
                system("CLS");
                jackpotpool = jackpotpool + playerbet; 
                cout << "LOSS\n";
                cout << jackpotpool;
                cout << "\nRemaining Balance : " << playermoney << "\nSpin Again?: ";
                
                cin >> slotplayagain; 
                system("CLS");
            }
        }
        else {
        
        cout << "--ERROR--\n" << playerbet << " Is a invalid ammount\n";
        cout << "Please enter a valid ammount between 0 & " << playermoney << "\n";
        cout << "Procced in ";

        for (int i = 5; i >= 0; --i) { //Countdown Timer to ensure the player reads the message (5 Seconds)
            cout << i << " "; 
            Sleep(1000); 
            
            if (i == 0) {
                system("CLS"); //Clears the screen once the timer hits 0 
               playerbet;
            }
        }
        }
    }
    return playermoney, jackpotpool; 
}



