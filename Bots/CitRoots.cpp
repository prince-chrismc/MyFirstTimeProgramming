#include <windows.h>
#include <iostream>

using namespace std;

int main ()
{
    SetConsoleTitle("Cit Root Chopper");
    string choice;
    int x;
    int y;
    int run;
    int done = 0;

    start:

    cout << "Cit Root Chopper" ;
    cout << endl << "Version 1.0" << endl;

    cout << endl << "Insert number of roots to chop than press 'enter' to begin... ";
    cout << endl << "Note: Each root is approx 8 ressources." << endl;
    Sleep(500);

    cout << endl << "Number of roots to chop: ";
    cin >> run;

    cout << endl << "Starting in 3...";
    Sleep(1000);
    cout << endl << "Starting in 2...";
    Sleep(1000);
    cout << endl << "Starting in 1...";
    Sleep(1000);
    cout << endl << "In progress..." << endl;

    POINT p;
    SetCursorPos(609, 415);
    GetCursorPos(&p);
    x = p.x;
    y = p.y;

    while(done < run)
    {
        HDC hDC = GetDC(NULL);
        COLORREF color = GetPixel(hDC, p.x, p.y);
        BYTE redValue, greenValue, blueValue;
        redValue = GetRValue(color);
        greenValue = GetGValue(color);
        blueValue = GetBValue(color);

        if(redValue >= 109 && redValue <= 119 && greenValue >= 83 && greenValue <= 93 && blueValue >= 52 && blueValue <=62)
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
            Sleep(20000);

            done++;
        }
        else
        {
            Sleep(5000);
        }
    }

    cout << endl << "complete!";
    cout << endl << "(y/n) Again: ";
    cin >> choice;
    if (choice == "y")
    {
        system("cls");
        goto start;
    }
    return 0;
}
