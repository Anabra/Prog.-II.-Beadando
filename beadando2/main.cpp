//Készítette:   Podlovics Péter
//Dátum:        2016.05.06
//Neptun-kód:   D0W5T4
//E-mail:       peterdavidpodlovics@gmail.com
//Csoport:      1.csoport
//Feladat:      2.beadandó/7.feladat
//              Melyik  a  leggazdagabb  bekezdés,
//              azaz  hányadik  az  a  legalább  három  soros
//              bekezdés,  ahol  a  legnagyobb  a  szavak  számának  és  a  sorok  számának  hányadosa?

#include <iostream>
#include <fstream>
#include "enor.h"
#include "paragraph.h"
#include "menu.h"

using namespace std;

template<class T>
struct QueryResult
{
    bool l;
    T result;
    //constraint: class T must have a copy ctor
    QueryResult(const bool l, const T& result) : l(l), result(result) {}
};

//A beta függvény a felt. max. ker.-hez
//True  - van min 3 sora
//False - otherwise
bool hasThreeLines(const Paragraph &p);

//A reláció a felt. max. ker.-hez
//True - az első oprandusnak magasabb a szó/sor aránya
bool compareParagraphs(const Paragraph &p1, const Paragraph &p2);


//Felt. max. ker
template<class T>
QueryResult<T> condMaxSearch(Enor<T> &e, bool beta(const T&), bool rel(const T&, const T&));


//Végrehajtja a condMaxSearch fv-t az adott istream-ről beolvasott paraméterekkel
void calcAndDisplayResult(istream& in);

int main()
{
    while (true)
    {
        displayMenu();
        int comm = readCommand();

        switch (comm)
        {
        case READ_FROM_FILE:
        {
            string path;
            cout << "Name/path of the file: ";
            cin >> path;
            ifstream in(path);
            calcAndDisplayResult(in);

            break;
        }
        case READ_FROM_CONSOLE:
        {
            cout << "Type in the input:" << endl;
            calcAndDisplayResult(cin);

            break;
        }

        case QUIT:
            quit();
            break;

        default:
            ;
        }
    }

    return 0;
}

bool hasThreeLines(const Paragraph &p)
{
    return p.getNumOfRows() > 2;
}

bool compareParagraphs(const Paragraph &p1, const Paragraph &p2)
{
    double p1Ratio = (double)p1.getNumOfWords() / p1.getNumOfRows();
    double p2Ratio = (double)p2.getNumOfWords() / p2.getNumOfRows();
    return p1Ratio < p2Ratio;
}

template<class T>
QueryResult<T> condMaxSearch(Enor<T> &e, bool beta(const T&), bool rel(const T&, const T&))
{
    T maxItem;
    bool l = false;
    e.first();

    while(!e.end())
    {
        if (beta(e.current()) && !l)
        {
            l = true;
            maxItem = e.current();
        }
        else if (beta(e.current()) && l)
        {
            if (rel(maxItem, e.current()))
            {
                maxItem = e.current();
            }
        }
        e.next();
    }

    return QueryResult<T>(l, maxItem);
}

void calcAndDisplayResult(istream& in)
{
    try
    {
        StreamEnor<Paragraph> e(in);

        QueryResult<Paragraph> qr = condMaxSearch(e, hasThreeLines, compareParagraphs);
        if (qr.l)
        {
            cout << qr.result << endl;
            cout << "Ratio: " << (double)qr.result.getNumOfWords() / qr.result.getNumOfRows();
        }
        else
        {
            cout << "NOT FOUND";
        }
    }
    catch(StreamEnorException ex)
    {
        cerr << ex;
    }
    cout << endl << endl;;
}
