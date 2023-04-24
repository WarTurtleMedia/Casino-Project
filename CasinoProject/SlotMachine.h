#include <iostream>
#include <cstdlib>
#include <ctime>
//#include <Windows.h>
using namespace std; 

int CheckSlotWin(int& randnum1, int& randnum2, int& randnum3) 
{
    if (randnum1 >= 1 && randnum1 <= 19) //19% Chance to output '2'
    {
        randnum1 = 2;
    }
    else if (randnum1 >= 20 && randnum1 <= 38) //19% Chance to output '3'
    {
        randnum1 = 3;
    }
    else if (randnum1 >= 39 && randnum1 <= 57) //19% Chance to output '4'
    {
        randnum1 = 4;
    }
    else if (randnum1 >= 58 && randnum1 <= 76) //19% Chance to output '5'
    {
        randnum1 = 5;
    }
    else if (randnum1 >= 77 && randnum1 <= 95) //19% Chance to output '6'
    {
        randnum1 = 6;
    }
    else if (randnum1 >= 96 && randnum1 <= 99) //19% Chance to output '7'
    {
        randnum1 = 7;
    }
    else if (randnum1 == 100) //1% Chance to output '7'
    {
        randnum1 = 100;
    }


    if (randnum2 >= 1 && randnum2 <= 19)
    {
        randnum2 = 2;
    }
    else if (randnum2 >= 20 && randnum2 <= 38)
    {
        randnum2 = 3;
    }
    else if (randnum2 >= 39 && randnum2 <= 57)
    {
        randnum2 = 4;
    }
    else if (randnum2 >= 58 && randnum2 <= 76)
    {
        randnum2 = 5;
    }
    else if (randnum2 >= 77 && randnum2 <= 95)
    {
        randnum2 = 6;
    }
    else if (randnum2 >= 96 && randnum2 <= 99)
    {
        randnum2 = 7;
    }
    else if (randnum2 == 100)
    {
        randnum2 = 100;
    }


    if (randnum3 >= 1 && randnum3 <= 19)
    {
        randnum3 = 2;
    }
    else if (randnum3 >= 20 && randnum3 <= 38)
    {
        randnum3 = 3;
    }
    else if (randnum3 >= 39 && randnum3 <= 57)
    {
        randnum3 = 4;
    }
    else if (randnum3 >= 58 && randnum3 <= 76)
    {
        randnum3 = 5;
    }
    else if (randnum3 >= 77 && randnum3 <= 95)
    {
        randnum3 = 6;
    }
    else if (randnum3 >= 96 && randnum3 <= 99)
    {
        randnum3 = 7;
    }
    else if (randnum3 == 100)
    {
        randnum3 = 100;
    }

    return randnum1, randnum2, randnum3; 
}

int SlotSpin(int& playermoney, int& jackpotpool) {
    
    // Creating the Random Numbers 

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
    char playwin[7] = { '+','+','W','I','N','+','+'};
    
    int spinerresult[3]; //Arrays for the Slot spinner 
    int spinneranimation[3]; 
    
    int spincounter = 0; //Keeps Track Of spins the player has had
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    while (slotplayagain == true){
        
       
       
       srand(time(0));
       int randnum1 = (rand() % 99) + 1;
       int randnum2 = (rand() % 99) + 1;
       int randnum3 = (rand() % 99) + 1;

       int animationrand1 = (rand() % 7) + 2;
       int animationrand2 = (rand() % 7) + 2;
       int animationrand3 = (rand() % 7) + 2;
       spinneranimation[1] = animationrand1;
       spinneranimation[2] = animationrand2;
       spinneranimation[3] = animationrand3;

      //int randnum1 = 100; 
      //int randnum2 = 100;
      //int randnum3 = 100;

        cout << " [" << spinneranimation[1] << "] ";
        cout << " [" << spinneranimation[2] << "] ";
        cout << " [" << spinneranimation[3] << "] \n";
        cout << "\n\n\n\n\n\n\n";
        cout << "CURRENT JACKPOT :" << jackpotpool << "\n";
        cout << "Remaining Balance : " << playermoney << "\nYour Bet: ";
        //cin >> playerbet;
        
        while (!(cin >> playerbet)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("CLS");
            cout << " [" << spinneranimation[1] << "] ";
            cout << " [" << spinneranimation[2] << "] ";
            cout << " [" << spinneranimation[3] << "] \n";
            cout << "CURRENT JACKPOT :" << jackpotpool << "\n";
            cout << "\n\nPLEASE ENTER A NUMBER NOT WORDS OR SPECIAL CHARACTERS\n";
            cout << "Remaining Balance : " << playermoney << "\nYour Bet: ";
            
        }

        system("CLS");
       
        if (playerbet > 0 && playerbet <= playermoney) {
            playermoney = playermoney - playerbet; //Removing players bet from their total balance 
            
            for (int i = 0; i < 3; ++i)
            {
                animationrand1 = (rand() % 7) + 2;
                animationrand2 = (rand() % 7) + 2;
                animationrand3 = (rand() % 7) + 2;
                spinneranimation[1] = animationrand1;
                spinneranimation[2] = animationrand2;
                spinneranimation[3] = animationrand3;
                cout << " [" << spinneranimation[1] << "] ";
                cout << " [" << spinneranimation[2] << "] ";
                cout << " [" << spinneranimation[3] << "] \n";
                cout << "\n\n\n\n\n\n\n";
                cout << "CURRENT JACKPOT :" << jackpotpool << "\n";
                cout << "Remaining Balance : " << playermoney << "\nYour Bet: " << playerbet << "\n\n";
                Sleep(1000);
                system("CLS");
            }
            

            CheckSlotWin(randnum1, randnum2, randnum3); // Checks if the players spin matches any win conditions or if they lost 

            spinerresult[1] = randnum1;
            spinerresult[2] = randnum2;
            spinerresult[3] = randnum3;
            cout << " [" << spinerresult[1] << "] ";
            cout << " [" << spinerresult[2] << "] ";
            cout << " [" << spinerresult[3] << "] \n";

            if (randnum1 == 7 && randnum1 == randnum2 && randnum1 == randnum3) //If three numbers are Equal to 7 then player earns back 10x their bet
            {
                cout << "\n";
                for (int i = 0; i < 7; ++i)
                {
                    Sleep(750);
                    cout << playwin[i];
                }

                cout << "\n++! TRIPLE SEVENS !++\n";
                cout << "BET 10X: " << playerbet * 10 << "\n";
                playermoney = playermoney + (playerbet * 10);
                
            }
            else if (randnum1 == 100 && randnum1 == randnum2 && randnum1 == randnum3) //If three numbers are Equal to 100 then player wins the jackpot 
            {
                cout << "\n       ++WIN++\n";
                cout << "  +! - JACKPOT - !+\n\n\n";
                playermoney = playermoney + jackpotpool;
                jackpotpool = 0; 
            }
            else if (randnum1 == randnum2 && randnum1 == randnum3 && randnum1 != 7 && randnum1 != 100) //If three numbers are Equal then player earns back 5x their bet
            {
                cout << "\n    ++WIN++\n\n\n";
                cout << "BET 5X:" << playerbet * 5 << "\n";
                playermoney = playermoney + (playerbet * 5);
                
            }
  
            else if (randnum1 == randnum2 or randnum1 == randnum3 or randnum3 == randnum2) //If two numbers are Equal then player earns back 3x their bet
            {
                cout << "\n    ++WIN++\n\n\n";
                cout << "BET 3X: " << playerbet * 3 << "\n";
                playermoney = playermoney + (playerbet * 3);
              
            }
            else 
            {
        
                jackpotpool = jackpotpool + playerbet; 
                cout << "\n     LOSS\n\n\n\n";
                
            }
            
            cout << "\n\n";
            cout << "CURRENT JACKPOT : " << jackpotpool << "\n";
            cout << "Remaining Balance : " << playermoney;
            if (playermoney > 0) {
                cout << "\nYour Bet: ";
                cin >> slotplayagain;
                system("CLS");
            }
            else {
                cout << "YOU ARE OUT OF MONEY PLEASE COME AGAIN";
                Sleep(10000);
                system("CLS");
                return playermoney, jackpotpool;
            }



        }
        else {
       
        cout << "--ERROR--\n" << playerbet << " Is a invalid ammount\n";
        cout << "Please enter a valid ammount between 1 & " << playermoney << "\n";
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
    //return playermoney, jackpotpool; 
}



