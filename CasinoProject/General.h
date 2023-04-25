#include <iostream>
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
	return;
}

void DrawBoxMedium(int XPostion, int YPostion) //Draws a box and takes input for X and Y cordinates to help it all be aligned when prinited 
{
	int BottomX, TopX, WallX;
	BottomX = XPostion;
	TopX = XPostion;
	WallX = XPostion;


	int BottomY, TopY, WallY;
	BottomY = YPostion;
	TopY = YPostion;
	WallY = YPostion;

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

void DrawBoxErrorCheck(int XPostion, int YPostion) //Draws a box and takes input for X and Y cordinates to help it all be aligned when prinited 
{
	int BottomX, TopX, WallX;
	BottomX = XPostion;
	TopX = XPostion;
	WallX = XPostion;


	int BottomY, TopY, WallY;
	BottomY = YPostion;
	TopY = YPostion;
	WallY = YPostion;

	SetPos(TopX, TopY);
	cout << " ";
	for (int r = 0; r < 45; ++r) // Roof of Box
	{
		cout << "_";
	}
	TopY = TopY + 1; //Adds 1 to the Y value to help set pos
	SetPos(TopX, TopY);
	//cout << "\n";
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

void Loadbar() //Function for loadbar animation 
{ 
	char loadbarblock = 254;
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

