//Készítette:   Podlovics Péter
//Dátum:        2016.05.06
//Neptun-kód:   D0W5T4
//E-mail:       peterdavidpodlovics@gmail.com
//Csoport:      1.csoport
//Feladat:      2.beadandó/7.feladat
//              A menü megjelenítésért felelős programrész headerje.


#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

enum Commands {READ_FROM_FILE = 1, READ_FROM_CONSOLE = 2, QUIT = 3};

template<class T>
bool returnTrue (T a)
{
    return true;
}

int checkedReadLine(const std::string &msg, const std::string &errorMsg, bool cond(int) = returnTrue);
void displayMenu();
bool checkCommand(int a);
int readCommand();
void quit();

#endif // MENU_H_INCLUDED
