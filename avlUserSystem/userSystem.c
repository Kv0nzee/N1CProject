#include "projectHeader.h"
#include "avltree.h"
#include "validationUtil.h"
#include "storeandretrieve.h"
#include "transactionUtil.h"
#include "stdio.h"
#include "windows.h"

int main(){

    // Get the console handle
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Save the current text color
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    WORD saved_attributes = consoleInfo.wAttributes;

    // Change the text color to green
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
//    char first[30]={'a','b','c','d'};

    retrieveUserDataFromFile();
    printf( "Welcome to our Program!\n");
    //SetConsoleTextAttribute(hConsole, saved_attributes);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);

    SetConsoleTextAttribute(hConsole, saved_attributes);
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
    menu();
    SetConsoleTextAttribute(hConsole, saved_attributes);

    return 0;
}