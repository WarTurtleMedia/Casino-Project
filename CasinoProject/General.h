#include <iostream>

using namespace std;



void Loadbar() {

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

void SetPos(int _x, int _y)
{
	COORD TempCord;
	TempCord.X = _x;
	TempCord.Y = _y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), TempCord);
}
/*int SumOfArray(int playerhand[5]) {

	int playerhand[5];
	int sum = 0;

	for (int i = 0; i < 5; ++i)
	{

		sum += playerhand[i];

	}
	cout << sum; 

	Sleep(100000);
}
*/