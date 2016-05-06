//Készítette:   Podlovics Péter
//Dátum:        2016.05.06
//Neptun-kód:   D0W5T4
//E-mail:       peterdavidpodlovics@gmail.com
//Csoport:      1.csoport
//Feladat:      2.beadandó/7.feladat
//              A Paragraph típus megvalósítása.

#include <iostream>
#include <sstream>
#include "paragraph.h"

using namespace std;

//Egy adott streamről beolvas egy Paragraph-ot.
//
//Először a stream elejéről beolvassa az üres sorokat (ezeket figyelmen kívül hagyni)
//Majd beolvassa a Paragraph-ot. Az olvasás az első üres sorig történik.
//A beolvasás biztonságos: ha sikertelen lenne, akkor nem korruptálja a paraméterül kapott Paragraph adatait.
istream& operator>>(istream& in, Paragraph &item)
{
    //we copy the the paragraph we want to read into
    //this will make reading safe --> it won't corrupt the state of the original object
    Paragraph p = item;
    p.id++;
    p.numOfWords = 0;
    p.numOfRows = 0;

    bool isEndOfFile;
    string tmpString;
    stringstream line;

    //reads all empty lines before the paragraph
    for (getline(in, tmpString); tmpString == "" && !(isEndOfFile = in.fail()); getline(in, tmpString));
    //we have a valid line in tmpString (it will be processed by the next loop)
    //OR we reached eof or the reading operation failed
    //in this case the original object is left untouched

    if (!isEndOfFile)
    {
        while (tmpString.size() > 0)
        {
            p.numOfRows++;
            //the next two lines use tmpString in a different manner
            //the first one reads out its contentn and transforms it into a sstream
            //the second one uses it to count the num of words in the line
            line << tmpString;

            while (line >> tmpString)
            {
                p.numOfWords++;
            }
            //if an error flag (failbit/badbit) is set, getline() won't read from the stream
            //so we override those flags with the current state by calling the clear() function
            //this way we will get an eofbit, so we can process the last line of the stream

            //the first time it reads the last line with an eof at the end
            //it will will clear the flag, and the store the string, so we can process it the next time we enter the loop
            //then it will read an empty string with an eof => it won't enter the loop

            getline(in, tmpString);
            line.clear();
            in.clear();
        }
        //we have an empty line in tmpString

        //copying the values from the temporary object
        item = p;
    }

    return in;
}


ostream& operator<<(ostream& out, const Paragraph &item)
{
    out << "id: " << item.id << endl;
    out << "Number of rows: " << item.numOfRows << endl;
    out << "Number of words: " << item.numOfWords;

    return out;
}
