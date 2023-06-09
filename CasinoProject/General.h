using namespace std;

void SetPos(int _SetX, int _SetY) //Function for setting Cursor postion 
{
	COORD TempCord;
	TempCord.X = _SetX;
	TempCord.Y = _SetY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), TempCord);
}

void GetPos(int& _GetCordx, int& _GetCordy) //Function for getting the current Cursor Postion and storing it in a variable
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
	GetConsoleScreenBufferInfo(Console, &ConsoleInfo);

	int _GetCursorPosx = ConsoleInfo.dwCursorPosition.X;
	int _GetCursorPosy = ConsoleInfo.dwCursorPosition.Y;
	_GetCordx = _GetCursorPosx;
	_GetCordy = _GetCursorPosy;
	cout << _GetCordx << "   " << _GetCordy;
	return;
}

void GetPosNoVar() //Function for getting the current Cursor Postion and storing it in a variable
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
	GetConsoleScreenBufferInfo(Console, &ConsoleInfo);

	int _GetCursorPosx = ConsoleInfo.dwCursorPosition.X;
	int _GetCursorPosy = ConsoleInfo.dwCursorPosition.Y;
	cout << _GetCursorPosx << "   " << _GetCursorPosy;
	return;
}

void DrawBoxMedium(int XPostion, int YPostion) //Draws a box and takes input for X and Y cordinates to help it all be aligned when prinited 
{
	int TopX;
	TopX = XPostion;
	int TopY;
	TopY = YPostion;

	SetPos(TopX, TopY);
	cout << " ";
	for (int r = 0; r < 33; ++r) // Roof of Box
	{
		cout << "_";
	}
	TopY = TopY + 1; //Adds 1 to the Y value to help set pos
	SetPos(TopX, TopY);
	//cout << "\n";
	for (int c = 0; c < 9; ++c) // Left and Right Wall
	{
		cout << "|" << "                                 " << "|" ;
		SetPos(TopX, TopY);
		TopY++;
	}
	cout << "|";
	for (int r = 0; r < 33; ++r) // Floor of box
	{
		cout << "_";
	}
	cout << "|";
}

void DrawOuterBox(int XPostion, int YPostion) //Draws a box and takes input for X and Y cordinates to help it all be aligned when prinited 
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_INTENSITY);
	int TopX;
	TopX = XPostion;
	int TopY;
	TopY = YPostion;

	SetPos(TopX, TopY);
	cout << " ";
	for (int r = 0; r < 38; ++r) // Roof of Box
	{
		cout << "_";
	}
	TopY = TopY + 1; //Adds 1 to the Y value to help set pos
	
	SetPos(TopX, TopY);

	for (int c = 0; c < 14; ++c) // Left and Right Wall
	{
		cout << "|" << "                                      " << "|";
		SetPos(TopX, TopY);
		TopY++;
	}
	cout << "|";
	for (int r = 0; r < 38; ++r) // Floor of box
	{
		cout << "_";
	}
	cout << "|";

	SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
	SetPos((TopX + 1), (TopY - 4));
	for (int r = 0; r < 38; ++r) // Top of Balance and Credit Chamber
	{
		cout << "_";
	}
	SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	SetPos((TopX + 1), (TopY - 6));
	for (int r = 0; r < 38; ++r) // Bottom of Slot Spinner
	{
		cout << "_";
	}
	SetPos((TopX + 1), (TopY - 13));
	for (int r = 0; r < 38; ++r) // Top of Slot Spinner
	{
		cout << "_";
	}
	TopX = XPostion;
	TopY = YPostion;
	int SlotLineY; 
	SlotLineY = TopY + 3;
	SetPos((TopX + 13), (TopY + 3));	
	for (int c = 0; c < 8; ++c) // Left Inner Wall for Spinner 
	{
		cout << "|";
		SetPos((TopX + 13), SlotLineY);
		++SlotLineY;
	}
	SlotLineY = TopY + 3;
	SetPos((TopX + 26), (TopY + 3));
	for (int c = 0; c < 8; ++c) // Right Inner Wall for Spinner 
	{
		cout << "|";
		SetPos((TopX + 26), SlotLineY);
		++SlotLineY;
	}
	int BalLineY;
	BalLineY = TopY + 12;
	SetPos((TopX + 13), (TopY + 12));
	for (int c = 0; c < 4; ++c) // Balance Area Wall
	{
		cout << "|";
		SetPos((TopX + 13), BalLineY);
		++BalLineY;
	}
	int JackPotLineY;
	JackPotLineY = TopY + -2;
	SetPos((TopX + 29), (TopY - 2));
	for (int c = 0; c < 4; ++c) // JACKPOT DISPLAY RIGHT WALL 
	{
		cout << "|";
		SetPos((TopX + 29), JackPotLineY);
		++JackPotLineY;
	}
	JackPotLineY = TopY + -2;
	SetPos((TopX + 10), (TopY - 2));
	for (int c = 0; c < 4; ++c) // JACKPOT DISPLAY LEFT WALL
	{
		cout << "|";
		SetPos((TopX + 10), JackPotLineY);
		++JackPotLineY;
	}
	TopX = XPostion;
	TopY = YPostion;
	SetPos((TopX + 11), (TopY - 3));
	for (int r = 0; r < 18; ++r) // Top of Balance and Credit Chamber
	{
		cout << "_";
	}
	int ClearLine;
	TopX = XPostion;
	TopY = YPostion;
	ClearLine = TopY;
	SetPos((TopX ), (TopY));
	for (int r = 0; r < 18; ++r) // Clearing Overlap from Popups
	{
		SetPos((TopX-3), (ClearLine));
		cout << "   " << "\n";
		ClearLine++;
	}
	TopX = XPostion;
	TopY = YPostion;
	ClearLine = TopY;
	SetPos((TopX), (TopY));
	for (int r = 0; r < 18; ++r)  // Clearing Overlap from Popups
	{
		SetPos((TopX + 40), (ClearLine));
		cout << "       " << "\n";
		ClearLine++;
	}
}

void DrawMainMenu()
{
	SetPos(4, 1);
	cout << "--WELCOME TO PATRICKS TOTALLY LEGAL C++ CASINO--";
	SetPos(15, 2);
	cout << R"(   ____
                 /\' .\    _____
                /: \___\  / .  /\
                \' / . / /____/..\
                 \/___/  \'  '\  /
                          \'__'\/     
	)";

	SetPos(0, 8);
	for (int r = 0; r < 60; ++r) // Clearing Empty Spaces
	{
		cout << " ";
	}
	SetPos(0, 9);
	for (int r = 0; r < 14; ++r) // Clearing Empty Spaces
	{
		cout << " ";
	}
	SetPos(40, 9);
	for (int r = 0; r < 46; ++r) // Clearing Empty Spaces
	{
		cout << " ";
	}
	SetPos(15, 9);
	cout << "- PLEASE SELECT A GAME -";
	SetPos(17, 10);
	for (int r = 0; r < 60; ++r) // Clearing Empty Spaces
	{
		cout << " ";
	}
	SetPos(12, 11);
	for (int r = 0; r < 60; ++r) // Clearing Empty Spaces
	{
		cout << " ";
	}
	SetPos(9, 12);
	for (int r = 0; r < 60; ++r) // Clearing Empty Spaces
	{
		cout << " ";
	}
	SetPos(14, 17);
	for (int r = 0; r < 60; ++r) // Clearing Empty Spaces
	{
		cout << " ";
	}
	SetPos(0, 13);
	for (int r = 0; r < 60; ++r) // Clearing Empty Spaces
	{
		cout << " ";
	}
	SetPos(12, 14);
	for (int r = 0; r < 60; ++r) // Clearing Empty Spaces
	{
		cout << " ";
	}
	SetPos(0, 15);
	for (int r = 0; r < 60; ++r) // Clearing Empty Spaces
	{
		cout << " ";
	}
	SetPos(0, 16);
	for (int r = 0; r < 60; ++r) // Clearing Empty Spaces
	{
		cout << " ";
	}
	SetPos(4, 10);
	cout << "1: Slot Machine";
	SetPos(4, 11);
	cout << "2: BlackJack";
	SetPos(4, 12);
	cout << "3: Credits";
	SetPos(4, 14);
	cout << "4: EXIT";
	SetPos(4, 17);
	cout << "SELECTION: ";
}

void DrawSpinnerAnimation()
{

}

void DrawSlotMachine(int XPostion, int YPostion, int PlayerBal, int JackPot) //int PlayerBal, int JackPot, int randnum1, int randnum2, int randnum3
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	DrawOuterBox(XPostion, YPostion); //Draws the outer shell of the box 
	
	int TopX;
	int TopY;
	TopX = XPostion;
	TopY = YPostion;

	//Printing the Balance Information to the screen
	SetPos((TopX + 1), (TopY + 12)); 
	SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "Balance"; 
	SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_GREEN); //GOLD TEXT
	SetPos((TopX + 1), (TopY + 13));
	cout << "$ ";
	SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << PlayerBal;

	//Printing the Jackpot Info to the screen
	SetPos((TopX + 16), (TopY -2));
	SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "JACKPOT!";
	SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_GREEN ); //GOLD TEXT
	SetPos((TopX + 16), (TopY - 1));
	cout << "$ ";
	SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << JackPot;
	
	//Printing the Place Bet Area
	SetPos((TopX + 14), (TopY + 12));
	SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "PLACE BET";
	SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_GREEN); //GOLD TEXT
	SetPos((TopX + 14), (TopY + 13));
	cout << "$ ";
	//SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

}

void DrawBoxErrorCheck(int XPostion, int YPostion) //Draws a box and takes input for X and Y cordinates to help it all be aligned when prinited 
{
	int TopX;
	TopX = XPostion;
	int TopY;
	TopY = YPostion;

	SetPos(TopX, TopY);
	cout << " ";
	for (int r = 0; r < 45; ++r) // Roof of Box
	{
		cout << "_";
	}
	TopY = TopY + 1; //Adds 1 to the Y value to help set pos
	SetPos(TopX, TopY);
	for (int c = 0; c < 4; ++c) // Left and Right Wall
	{
		cout << "|" << "                                             " << "|";
		SetPos(TopX, TopY);
		TopY++;
	}
	cout << "|";
	for (int r = 0; r < 45; ++r) // Floor of box
	{
		cout << "_";
	}
	cout << "|";
}

void Loadbar(int XPostion, int YPostion) //Function for loadbar animation 
{ 

	SetPos(XPostion, YPostion);

	const char loadbarblock = 254;
	Sleep(100);
	cout << "[";
	for (int i = 0; i < 20; i++) {
		cout << loadbarblock; 
			for (int i = 0; i < 20; i++)
		{
			Sleep(i / 10);
		}
	}
	cout << "]";
	cout << "\n" << "   LOADING COMPLETE ";
	Sleep(750);
	system("CLS");
}

void DrawNumberTwo(int XPostion, int YPostion)
{
	int _Y;
	int _X;
	_X = XPostion;
	_Y = YPostion;
	SetPos(_X, _Y);
	cout << "888888888D";
	++_Y;
	SetPos(_X, _Y);
	cout << "       888";
	++_Y;
	SetPos(_X, _Y);
	cout << "   8888   ";
	++_Y;
	SetPos(_X, _Y);
	cout << "888       ";
	++_Y;
	SetPos(_X, _Y);
	cout << "888888888D";
}

void DrawNumberThree(int XPostion, int YPostion)
{
	int _Y;
	int _X;
	_X = XPostion;
	_Y = YPostion;
	SetPos(_X, _Y);
	cout << "C88888888D";
	++_Y;
	SetPos(_X, _Y);
	cout << "        88";
	++_Y;
	SetPos(_X, _Y);
	cout << "    C8888D";
	++_Y;
	SetPos(_X, _Y);
	cout << "        88";
	++_Y;
	SetPos(_X, _Y);
	cout << "C88888888D";
}

void DrawNumberFour(int XPostion, int YPostion)
{
	int _Y;
	int _X;
	_X = XPostion;
	_Y = YPostion;
	SetPos(_X, _Y);
	cout << "      888D ";
	++_Y;
	SetPos(_X, _Y);
	cout << "   888  88 ";
	++_Y;
	SetPos(_X, _Y);
	cout << "888     88";
	++_Y;
	SetPos(_X, _Y);
	cout << "8888888888";
	++_Y;
	SetPos(_X, _Y);
	cout << "        88 ";
}

void DrawNumberFive(int XPostion, int YPostion)
{
	int _Y;
	int _X;
	_X = XPostion;
	_Y = YPostion;
	SetPos(_X, _Y);
	cout << "C88888888D";
	++_Y;
	SetPos(_X, _Y);
	cout << "88        ";
	++_Y;
	SetPos(_X, _Y);
	cout << "C88888888D";
	++_Y;
	SetPos(_X, _Y);
	cout << "        88";
	++_Y;
	SetPos(_X, _Y);
	cout << "C88888888D";
}

void DrawNumberSix(int XPostion, int YPostion)
{
	int _Y;
	int _X;
	_X = XPostion;
	_Y = YPostion;
	SetPos(_X, _Y);
	cout << " C8888888D";
	++_Y;
	SetPos(_X, _Y);
	cout << "88        ";
	++_Y;
	SetPos(_X, _Y);
	cout << "C88888888D";
	++_Y;
	SetPos(_X, _Y);
	cout << "88      88";
	++_Y;
	SetPos(_X, _Y);
	cout << " C888888D ";
}

void DrawNumberSeven(int XPostion, int YPostion)
{
	int _Y;
	int _X;
	_X = XPostion;
	_Y = YPostion;
	SetPos(_X, _Y);
	cout << "C88888888D";
	++_Y;
	SetPos(_X, _Y);
	cout << "       88 ";
	++_Y;
	SetPos(_X, _Y);
	cout << "     88   ";
	++_Y;
	SetPos(_X, _Y);
	cout << "   88     ";
	++_Y;
	SetPos(_X, _Y);
	cout << " 88       ";
}

void DrawNumberBlank(int XPostion, int YPostion)
{
	int _Y;
	int _X;
	_X = XPostion;
	_Y = YPostion;
	SetPos(_X, _Y);
	cout << "          ";
	++_Y;
	SetPos(_X, _Y);
	cout << "          ";
	++_Y;
	SetPos(_X, _Y);
	cout << "          ";
	++_Y;
	SetPos(_X, _Y);
	cout << "          ";
	++_Y;
	SetPos(_X, _Y);
	cout << "          ";
}

void DrawNumberJackPot(int XPostion, int YPostion)
{
	int _Y;
	int _X;
	_X = XPostion;
	_Y = YPostion;
	SetPos(_X, _Y);
	cout << " JACKPOT! ";
	++_Y;
	SetPos(_X, _Y);
	cout << "          ";
	++_Y;
	SetPos(_X, _Y);
	cout << " JACKPOT! ";
	++_Y;
	SetPos(_X, _Y);
	cout << "          ";
	++_Y;
	SetPos(_X, _Y);
	cout << " JACKPOT! ";

}

void AnimateSpinStart(int XPostion, int YPostion, int RandAnimationNum)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); //GOLD TEXT
	
	int _Y;
	int _X;
	_X = XPostion;
	_Y = YPostion;

	if (RandAnimationNum == 2)
	{
		DrawNumberTwo(_X, _Y);
	}
	else if (RandAnimationNum == 3)
	{
		DrawNumberThree(_X, _Y);
	}
	else if (RandAnimationNum == 4)
	{
		DrawNumberFour(_X, _Y);
	}
	else if (RandAnimationNum == 5)
	{
		DrawNumberFive(_X, _Y);
	}
	else if (RandAnimationNum == 6)
	{
		DrawNumberSix(_X, _Y);
	}
	else if (RandAnimationNum == 7)
	{
		DrawNumberSeven(_X, _Y);
	}
	else if (RandAnimationNum == 8)
	{
		DrawNumberJackPot(_X, _Y);
	}
}

void AnimateSpinEnd(int XPostion, int YPostion, int RandEndNum)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); //GOLD TEXT
	int _Y;
	int _X;
	_X = XPostion;
	_Y = YPostion;

	if (RandEndNum == 2)
	{
		DrawNumberTwo(_X, _Y);
	}
	else if (RandEndNum == 3)
	{
		DrawNumberThree(_X, _Y);
	}
	else if (RandEndNum == 4)
	{
		DrawNumberFour(_X, _Y);
	}
	else if (RandEndNum == 5)
	{
		DrawNumberFive(_X, _Y);
	}
	else if (RandEndNum == 6)
	{
		DrawNumberSix(_X, _Y);
	}
	else if (RandEndNum == 7)
	{
		DrawNumberSeven(_X, _Y);
	}
	else if (RandEndNum == 100)
	{
		DrawNumberJackPot(_X, _Y);
	}
}

void DrawWinScroll(int PosX, int PosY)
{
	int TempX = 0;
	char DrawWin[7] = { '+','+','W','I','N','+','+' };

	for (int j = 0; j < 6; ++j)
	{
		SetPos(PosX, PosY);
		TempX = PosX; //Stores the X Var to clear it after it prinits

		for (int i = 0; i < 7; ++i) //Draw Win
		{
			if (PosX < 42)
			{
				cout << DrawWin[i];
				PosX++;
			}
			else {
			}
		}
		Sleep(200);
		SetPos(TempX, PosY);
		if (PosX < 42)
		{
			for (int l = 0; l < 7; ++l)
			{
				cout << " ";
			}
		}
		else {
			cout << "  ";
		}

	}

}

void DrawLossScroll(int PosX, int PosY)
{
	int TempX = 0;
	char DrawLoss[6] = { '-','L','O','S','S','-'};

	for (int j = 0; j < 6; ++j)
	{
		SetPos(PosX, PosY);
		TempX = PosX; //Stores the X Var to clear it after it prinits

		for (int i = 0; i < 6; ++i) //Draw Win
		{
			if (PosX < 42)
			{
				cout << DrawLoss[i];
				PosX++;
			}
			else {
			}
		}
		Sleep(200);
		SetPos(TempX, PosY);
		if (PosX < 44)
		{
			for (int l = 0; l < 6; ++l)
			{
				cout << " ";
			}
		}
		else {
			cout << "  ";
		}

	}

}

void DrawWinMultiplier(int PosX, int PosY, int WinOutCome)
{
	int TempX = 0;
	char Draw3xWin[2] = {'3','x'};
	char Draw5xWin[2] = {'5','x'};
	char Draw10xWin[3] = {'1','0','x'};

	if (WinOutCome == 1) //Draws 3x Win 
	{
		for (int j = 0; j < 22; ++j)
		{
			SetPos(PosX, PosY);
			TempX = PosX; //Stores the X Var to clear it after it prinits

			for (int i = 0; i < 2; ++i) //Draw Win
			{
				if (PosX < 42)
				{
					cout << Draw3xWin[i];
					PosX++;
				}
				else {
				}
			}
			Sleep(50);
			SetPos(TempX, PosY);
			if (PosX < 42)
			{
				for (int l = 0; l < 6; ++l)
				{
					cout << " ";
				}
			}
			else {
				cout << "  ";
			}
		}
	}
	else if (WinOutCome == 2) //Draws 5x Win 
	{
		for (int j = 0; j < 22; ++j)
		{
			SetPos(PosX, PosY);
			TempX = PosX; //Stores the X Var to clear it after it prinits

			for (int i = 0; i < 2; ++i) //Draw Win
			{
				if (PosX < 42)
				{
					cout << Draw5xWin[i];
					PosX++;
				}
				else {
				}
			}
			Sleep(50);
			SetPos(TempX, PosY);
			if (PosX < 42)
			{
				for (int l = 0; l < 6; ++l)
				{
					cout << " ";
				}
			}
			else {
				cout << "  ";
			}
		}
	}
	else if (WinOutCome == 3) //Draws 10x Win 
	{
		for (int j = 0; j < 14; ++j)
		{
			SetPos(PosX, PosY);
			TempX = PosX; //Stores the X Var to clear it after it prinits

			for (int i = 0; i < 3; ++i) //Draw Win
			{
				if (PosX < 42)
				{
					cout << Draw10xWin[i];
					PosX++;
				}
				else {
				}
			}
			Sleep(50);
			SetPos(TempX, PosY);
			if (PosX < 42)
			{
				for (int l = 0; l < 3; ++l)
				{
					cout << " ";
				}
			}
			else {
				cout << "   ";
			}
		}
	}

}

void CheckPlayAgain(string _PlayAgain, bool& Loop)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	int _PlayAgainLoop = 1; 
	
	while (_PlayAgainLoop == 1)
	if (_PlayAgain == "Yes" or _PlayAgain == "YEs" or _PlayAgain == "YES" or _PlayAgain == "yES" or _PlayAgain == "yEs" or _PlayAgain == "yeS" 
		or _PlayAgain == "YeS" or _PlayAgain == "yes" or _PlayAgain == "Y" or _PlayAgain == "y")
	{
		Loop = true;
		_PlayAgainLoop = 0;
	}
	else if (_PlayAgain == "No" or _PlayAgain == "no" or _PlayAgain == "N" or _PlayAgain == "n" or _PlayAgain == "nO" or _PlayAgain == "NO") //Ends Slot Machine if 
	{
		Loop = false; 
		_PlayAgainLoop = 0;
	}
	else
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		DrawBoxErrorCheck(2, 8); //Starts the procces to output a message to the user they need to enter a number
		SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_INTENSITY);
		SetPos(5, 10);
		cout << "PLEASE ENTER A VARIATION OF 'YES' OR 'NO'";
		Sleep(2000); //Delay to ensure player can read the message box
		SetPos(5, 10);
		cout << "                                         ";
		SetPos(20, 10);
		cout << "PLAY AGAIN ?";
		SetPos(20, 11);
		cout << "Y / N : ";
		cin >> _PlayAgain;

	}
}