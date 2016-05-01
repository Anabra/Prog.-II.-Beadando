#include <iostream>
#include <sstream>
#include "paragraph.h"

using namespace std;

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
    for (getline(in, tmpString); tmpString.size() == 0 && !(isEndOfFile = in.fail()); getline(in, tmpString));
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
            //if an error flag is set, getline() won't read from the stream (probably failbit)
            //so we reset those flags by calling the clear() function
            //this way we will get an eofbit, so we can process the last line of the file
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
    out << "Number of words: " << item.numOfWords << endl;

    return out;
}
