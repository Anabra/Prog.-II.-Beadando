#include <iostream>
#include <fstream>
#include "enor.h"
#include "paragraph.h"

using namespace std;

template<class T>
struct QueryResult
{
    bool l;
    T result;
    //constraint: class T must have a copy ctor
    QueryResult(const bool l, const T& result) : l(l), result(result) {}
};

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

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    try
    {
        StreamEnor<Paragraph> e(in);

        QueryResult<Paragraph> qr = condMaxSearch(e, hasThreeLines, compareParagraphs);
        if (qr.l)
        {
            cout << qr.result;
        }
        else
        {
            cout << "NOT FOUND";
        }
    }
    catch (StreamEnorException e)
    {
        cout << e;
    }

    return 0;
}
