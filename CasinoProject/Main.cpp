#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

    int playyes = 1;
    int playno = 0;
    int playagain = 1;

    int xout = 0;

    int jackpot = 1000;
    int playermoney = 2000;

    const int eqaulspin = 3;


    // 
    const int slotstwo = 2;
    const int slotsthree = 3;
    const int slotsfour = 4;
    const int slotsfive = 5;
    const int slotssix = 6;
    const int slots10x = 7;
    const string slotsjackpot = "! ! - JACKPOT - ! !";



    while (playagain != playno)//Play Again Loop - Restarts the program and generates a new number whilse wiping old data
    {

        int playerbet = 0;
        cout << "Remaining Coins : " << playermoney << "\nPlease Enter a Bet : ";
        cin >> playerbet;
        playermoney = playermoney - playerbet;


        srand(time(0));
        int randnum1 = (rand() % 99) + 1;
        int randnum2 = (rand() % 99) + 1;
        int randnum3 = (rand() % 99) + 1;



        //cout << randnum1 << "\n" << randnum2 << "\n" << randnum3 << "\n"; // Test Output 





        if (randnum1 >= 1 && randnum1 <= 19) //19% Chance to output '2'
        {
            randnum1 = slotstwo;
            cout << slotstwo << " ";


        }
        else if (randnum1 >= 20 && randnum1 <= 38) //19% Chance to output '3'
        {
            randnum1 = slotsthree;

            cout << slotsthree << " ";

        }


        else if (randnum1 >= 39 && randnum1 <= 57) //19% Chance to output '3'
        {
            randnum1 = slotsfour;
            cout << slotsfour << " ";


        }

        else if (randnum1 >= 58 && randnum1 <= 76) //19% Chance to output '3'
        {
            randnum1 = slotsfive;
            cout << slotsfive << " ";


        }

        else if (randnum1 >= 77 && randnum1 <= 95) //19% Chance to output '3'
        {
            cout << slotssix << " ";


        }

        else if (randnum1 >= 96 && randnum1 <= 99) //19% Chance to output '3'
        {
            cout << slots10x << " ";


        }

        else if (randnum1 == 100) //1% Chance to output '7'
        {
            cout << slotsjackpot << " ";

        }







        if (randnum2 >= 1 && randnum2 <= 19) //19% Chance to output '2'
        {
            cout << slotstwo << " ";


        }
        else if (randnum2 >= 20 && randnum2 <= 38) //19% Chance to output '3'
        {
            cout << slotsthree << " ";

        }

        else if (randnum2 >= 39 && randnum2 <= 57) //19% Chance to output '3'
        {
            cout << slotsfour << " ";


        }

        else if (randnum2 >= 58 && randnum2 <= 76) //19% Chance to output '3'
        {
            cout << slotsfive << " ";


        }

        else if (randnum2 >= 77 && randnum2 <= 95) //19% Chance to output '3'
        {
            cout << slotssix << " ";


        }

        else if (randnum2 >= 96 && randnum2 <= 99) //19% Chance to output '3'
        {
            cout << slots10x << " ";


        }

        else if (randnum2 == 100) //1% Chance to output '7'
        {
            cout << slotsjackpot << " ";

        }





        if (randnum3 >= 1 && randnum3 <= 19) //19% Chance to output '2'
        {
            cout << slotstwo << " ";


        }
        else if (randnum3 >= 20 && randnum3 <= 38) //19% Chance to output '3'
        {
            cout << slotsthree << " ";

        }

        else if (randnum3 >= 39 && randnum3 <= 57) //19% Chance to output '3'
        {
            cout << slotsfour << " ";


        }

        else if (randnum3 >= 58 && randnum3 <= 76) //19% Chance to output '3'
        {
            cout << slotsfive << " ";


        }

        else if (randnum3 >= 77 && randnum3 <= 95) //19% Chance to output '3'
        {
            cout << slotssix << " ";


        }

        else if (randnum3 >= 96 && randnum3 <= 99) //19% Chance to output '3'
        {
            cout << slots10x << " ";


        }

        else if (randnum3 == 100) //1% Chance to output '7'
        {
            cout << slotsjackpot << " ";

        }


        if (randnum1 == randnum2 or randnum1 == randnum3 or randnum3 == randnum2)
        {
            playermoney = playermoney + (playerbet * 3);

            cout << "\n\n++WIN++\n";
            cout << "BET REFUNDED\n";
            cout << "Money; " << playermoney << "\n";
            cout << "Spin Again? : ";
            cin >> playagain;
            xout = 0;
            system("CLS");
        }
        else {

            cout << "\nNO WIN\n";
            cin >> playagain;
            xout = 0;
            system("CLS");
        }
    }
    return 0;
}