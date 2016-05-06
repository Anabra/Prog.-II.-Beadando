//Készítette:   Podlovics Péter
//Dátum:        2016.05.06
//Neptun-kód:   D0W5T4
//E-mail:       peterdavidpodlovics@gmail.com
//Csoport:      1.csoport
//Feladat:      2.beadandó/7.feladat
//              A menü megjelenítésért felelős programrész implementációja.

#include <iostream>
#include <stdlib.h>
#include "menu.h"

using namespace std;

//Feladat:      Megadott feltételnek megfelelő egész számot olvas be a konzolról.
//Input:        string msg - kiírandó üzenet
//              string errorMsg - kiírandó hibaüzenet
//              bool cond(int) - boolean értéket visszaadó, integer paraméterű függvény (ez felel majd a feltételért)
//Output:       int n (visszatérési érték)  - beolvasott egész szám: visszatérési érték
//Tevékenység:	Billentyûzetrõl olvas be egy a cond() feltételnek megfelelõ
//		        egész számot. A  cond() feltétel alapértelmezés szerint
//		        mindent elfogad, azaz bool c(int) { return true;}
int checkedReadLine(const string &msg, const string &errorMsg, bool cond(int))
{
    string s;
    int num = 0;
    bool isNotValid = false;

    cin.clear();

    do
    {
        cout << msg;
        cin >> num;
        isNotValid = cin.fail();
        cin.clear();
        getline(cin, s);
        isNotValid = isNotValid || !cond(num) || s != "";
        if(isNotValid)
        {
            cout << errorMsg << endl;
        }
    }
    while (isNotValid);

    return num;
}

//Feladat:  Kirajzolja a menüpontokat a konzolra
void displayMenu()
{
    cout << "1. Read from file\n2. Read from console\n3. Quit" << endl;
}

//Feladat:  Eldönti egy int típusú adatról, hogy szerepel-e, a commandok között.
//Input:    int a - bemenő egész
//Output:   bool b - kimenő logikai érték (True, ha "a" szerepel a commandok között)
bool checkCommand(int a)
{
    return 1 <= a && a <= 3;
}

//Feladat:      Beolvas egy commandot a konzolról
//Tevékenység:  A beolvasást a checkedReadLine() függvény segítségével végzi.
int readCommand()
{
    return checkedReadLine("Select the desired option: ", "---There is no such option\n", checkCommand);
}

//Feladat:      A körbejárásból való kilépésre szolgál.
//Tevékenység:  A program sikeresen befejezi futását.
void quit()
{
    exit(0);
}
