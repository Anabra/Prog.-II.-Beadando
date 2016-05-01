#ifndef ENOR_HPP_INCLUDED
#define ENOR_HPP_INCLUDED


StreamEnorException::StreamEnorException(const int errorCode, const std::string errorMsg)
 : errorCode(errorCode), errorMsg(errorMsg) {}

std::ostream& operator<<(std::ostream& out, const StreamEnorException& e)
{
    std::cout << "***StreamEnorException:" << std::endl
    << "Error Code: " << e.errorCode << std::endl
    << "Error Message: " << e.errorMsg << std::endl;
    return out;
}

template<class T>
StreamEnor<T>::StreamEnor(std::istream& in)
 : stream(in) { if (stream.fail()) {throw StreamEnorException(1,"Not valid stream");} }

#endif // ENOR_HPP_INCLUDED
