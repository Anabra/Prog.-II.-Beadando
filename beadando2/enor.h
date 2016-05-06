//Készítette:   Podlovics Péter
//Dátum:        2016.05.06
//Neptun-kód:   D0W5T4
//E-mail:       peterdavidpodlovics@gmail.com
//Csoport:      1.csoport
//Feladat:      2.beadandó/7.feladat
//              Egyedi felsoroló header-je


#ifndef ENOR_H_INCLUDED
#define ENOR_H_INCLUDED

#include <sstream>
#include <iostream>
//include "enor.hpp" at the end of definitions

enum Status {ABNORM, NORM};

//Absztrakt Enor osztály
template<class T>
class Enor
{
public:
    virtual void first() = 0;
    virtual T current() const = 0;
    virtual void next() = 0;
    virtual bool end() const = 0;
};

//Kivétel a StreamEnor típushoz
struct StreamEnorException
{
    const int errorCode;
    const std::string errorMsg;
    StreamEnorException(const int errorCode, const std::string errorMsg);

    friend std::ostream& operator<<(std::ostream& out, const StreamEnorException& e);
};

//Egyedi felsoroló
//A függvényei a megeygeznek a szekvenciális input file felsorolójának a függvényeivel
//Annyiban egyedi, hogy az olvasás nem sorokat olvas, hanem tetszőleges típust (az operator>>-t overloadolni kell egyedi típusok esetén)
template<class T>
class StreamEnor : public Enor<T>
{
public:
    std::istream& stream;
    T data;
    Status status;

public:
    //please note that by copying a StreamEnor, we also copy the stream reference
    //thus we can override the state of the same stream from a copied object
    //solution: use unique_ptr
    StreamEnor(std::istream& in);
    void first()        {status = (Status)!(bool)(stream >> data);}
    void next()         {status = (Status)!(bool)(stream >> data);}
    T current() const   {return data;}
    bool end() const    {return status;}
};

//definitions
#include "enor.hpp"

#endif // ENOR_H_INCLUDED
