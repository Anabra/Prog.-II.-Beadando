//Készítette:   Podlovics Péter
//Dátum:        2016.05.06
//Neptun-kód:   D0W5T4
//E-mail:       peterdavidpodlovics@gmail.com
//Csoport:      1.csoport
//Feladat:      2.beadandó/7.feladat
//              A Paragraph típus header-je.

#ifndef PARAGRAPH_H_INCLUDED
#define PARAGRAPH_H_INCLUDED

class Paragraph
{
private:
    int id;
    int numOfWords;
    int numOfRows;

public:
    //has default ctor / copy ctor / dtor --> these are appropriate for us
    Paragraph() : id(0) {};

    int getID() const           {return id;}
    int getNumOfWords() const   {return numOfWords;}
    int getNumOfRows() const    {return numOfRows;}

    friend std::istream& operator>>(std::istream& in, Paragraph &p);
    friend std::ostream& operator<<(std::ostream& out, const Paragraph &p);
};


#endif // PARAGRAPH_H_INCLUDED
