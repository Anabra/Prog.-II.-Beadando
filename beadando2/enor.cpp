#include <iostream>

using namespace std;

StreamEnorException::StreamEnorException(const int errorCode, const std::string errorMsg)
 : errorCode(errorCode), errorMsg(errorMsg) {}

StreamEnor<class T>::StreamEnor(std::istream& in)
 : stream(in) { if (stream.fail()) {throw StreamEnorException(1,"Not valid stream");} }
