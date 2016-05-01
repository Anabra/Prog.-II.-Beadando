#ifndef ENOR_H_INCLUDED
#define ENOR_H_INCLUDED

#include <sstream>
#include <iostream>
//include "enor.hpp" at the end of definitions

enum Status {ABNORM, NORM};

template<class T>
class Enor
{
public:
    virtual void first() = 0;
    virtual T current() const = 0;
    virtual void next() = 0;
    virtual bool end() const = 0;
};

struct StreamEnorException
{
    const int errorCode;
    const std::string errorMsg;
    StreamEnorException(const int errorCode, const std::string errorMsg);

    friend std::ostream& operator<<(std::ostream& out, const StreamEnorException& e);
};

template<class T>
class StreamEnor : public Enor<T>
{
public:
    std::istream& stream;
    T data;
    Status status;

public:
    StreamEnor(std::istream& in);
    void first()        {status = (Status)!(bool)(stream >> data);}
    void next()         {status = (Status)!(bool)(stream >> data);}
    T current() const   {return data;}
    bool end() const    {return status;}
};

//definitions
#include "enor.hpp"

#endif // ENOR_H_INCLUDED
