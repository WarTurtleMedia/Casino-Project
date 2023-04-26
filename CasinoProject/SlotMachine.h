using namespace std;

int CheckSlotLogic(int& randnum1, int& randnum2, int& randnum3) 
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
    else if (randnum1 == 100) //1% Chance to output 'JACKPOT'
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

    bool slotplayagain = true; 

    int playerbet = 0;
   
    int SpinCounterTemp = 0;
                 
    //PLAYER STATS
    int spincounter = 0; //MOVE TO MAIN 
    int PlayerTotalLoss = 0;
    int PlayerTotalWin = 0; 
    int PlayerTotalBetLifetime = 0;
    int PlayerBagelsBought = 0; 
    
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);

    while (slotplayagain == true)
    {

       // Creating the Random Numbers 
       srand(time(0)); 
       int randnum1 = (rand() % 99) + 1; //Slot Machine Numbers 
       int randnum2 = (rand() % 99) + 1;
       int randnum3 = (rand() % 99) + 1;

       int animationrand1 = (rand() % 7) + 2; //Slot Machine randomly generated numbers for Spinning effect
       int animationrand2 = (rand() % 7) + 2;
       int animationrand3 = (rand() % 7) + 2;

      //int randnum1 = 100; 
      //int randnum2 = 100;
      //int randnum3 = 100;

       
       if (SpinCounterTemp < 1) {
           DrawSlotMachine(5, 3, playermoney, jackpotpool); //Draws the Slot Machine 
           //Sets the starting screen Numbers for the spin animation
           AnimateSpinStart(7, 7, animationrand1); //Left Slot
           AnimateSpinStart(20, 7, animationrand2); //Middle SLot 
           AnimateSpinStart(33, 7, animationrand3); //Right Slot
       }
      

       SetPos(21, 16); //Sets the Cursor postion to the correct placement for the player to enter their bet 
       SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); //GOLD TEXT 
        
       while (!(cin >> playerbet)) { //Error Checking for characters and strings
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            DrawBoxErrorCheck(4, 8); //Starts the procces to output a message to the user they need to enter a number
            SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_INTENSITY);
            SetPos(17, 10);
            cout << "PLEASE ENTER A NUMBER";
            SetPos(12, 11);
            cout << "NOT WORDS OR SPECIAL CHARACTERS";
            Sleep(2000); //Delay to ensure player can read the message box
            DrawSlotMachine(5, 3, playermoney, jackpotpool);
            SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); //GOLD TEXT
            AnimateSpinStart(7, 7, animationrand1); //Left Slot
            AnimateSpinStart(20, 7, animationrand2); //Middle SLot 
            AnimateSpinStart(33, 7, animationrand3); //Right Slot
            SetPos(21, 16);
        }

        if (playerbet > 0 && playerbet <= playermoney) { //Error Checking to ensure players bet is a valid number bewteen 0 and their Max Chip ammount 
           
            playermoney = playermoney - playerbet; //Removing players bet from their total balance 

            DrawSlotMachine(5, 3, playermoney, jackpotpool); //Redraws the Slot Machine with updated Playmoney after their bet
            
            CheckSlotLogic(randnum1, randnum2, randnum3); // Checks to see if the players numbers match 
            
           //End Numbers for spin animation to detirmine results 
            AnimateSpinEnd(7, 7, randnum1); //Left Slot
            AnimateSpinEnd(20, 7, randnum2); //Middle SLot 
            AnimateSpinEnd(33, 7, randnum3); //Right Slot

            //Checking Win Conditions - If none are met Sets result to loss
            if (randnum1 == 7 && randnum1 == randnum2 && randnum1 == randnum3) //If three numbers are Equal to 7 then player earns back 10x their bet
            {
                for (int l = 0; l < 3; ++l) 
                {
                    DrawWinScroll(6, 13);
                }
                SpinCounterTemp++;
                //cout << "\n++! TRIPLE SEVENS !++\n";
                //cout << "BET 10X: " << playerbet * 10 << "\n";
                playermoney = playermoney + (playerbet * 10);
            }

            else if (randnum1 == 100 && randnum1 == randnum2 && randnum1 == randnum3) //If three numbers are Equal to 100 then player wins the jackpot 
            {
                for (int l = 0; l < 3; ++l)
                {
                    DrawWinScroll(6, 13);
                }
                SpinCounterTemp++;
                //cout << "  +! - JACKPOT - !+\n\n\n";
                playermoney = playermoney + jackpotpool;
                jackpotpool = 0; 
            }

            else if (randnum1 == randnum2 && randnum1 == randnum3 && randnum1 != 7 && randnum1 != 100) //If three numbers are Equal then player earns back 5x their bet
            {
                for (int l = 0; l < 3; ++l)
                {
                    DrawWinScroll(6, 13);
                }
                SpinCounterTemp++;
                //cout << "BET 5X:" << playerbet * 5 << "\n";
                playermoney = playermoney + (playerbet * 5);
                
            }
  
            else if (randnum1 == randnum2 or randnum1 == randnum3 or randnum3 == randnum2) //If two numbers are Equal then player earns back 3x their bet
            {
                for (int l = 0; l < 3; ++l)
                {
                    DrawWinScroll(6, 13);
                }
                SpinCounterTemp++;
                //cout << "BET 3X: " << playerbet * 3 << "\n";
                playermoney = playermoney + (playerbet * 3);
            }
            
            else 
            {
                for (int l = 0; l < 3; ++l)
                {
                    DrawLossScroll(6, 13);
                }
                SpinCounterTemp++;
                jackpotpool = jackpotpool + playerbet; 
           
            }

            DrawSlotMachine(5, 3, playermoney, jackpotpool); //Updates PlayerMoney and Jackpot to the visuals
            AnimateSpinEnd(7, 7, randnum1); //Left Slot
            AnimateSpinEnd(20, 7, randnum2); //Middle SLot 
            AnimateSpinEnd(33, 7, randnum3); //Right Slot

            if (playermoney > 0) {
                //cout << "\nYour Bet: ";
                SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                DrawBoxErrorCheck(4, 8); //Starts the procces to output a message to the user they need to enter a number
                SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_INTENSITY);
                SetPos(22, 10);
                cout << "PLAY AGAIN ?";
                SetPos(22, 11);
                cout << "Y / N : ";
                cin >> slotplayagain;
                DrawSlotMachine(5, 3, playermoney, jackpotpool);
                AnimateSpinEnd(7, 7, randnum1); //Left Slot
                AnimateSpinEnd(20, 7, randnum2); //Middle SLot 
                AnimateSpinEnd(33, 7, randnum3); //Right Slot
                SetPos(21, 16);
              
            }
            else {
                cout << "YOU ARE OUT OF MONEY PLEASE COME AGAIN";
                Sleep(10000);
                system("CLS");
                return playermoney, jackpotpool;
            }

        }
        else { //Error Checking to ensure players bet is a valid number bewteen 0 and their Max Chip ammount 
       
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
    return playermoney, jackpotpool;

}



