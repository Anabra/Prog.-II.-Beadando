//Készítette:   Podlovics Péter
//Dátum:        2016.05.06
//Neptun-kód:   D0W5T4
//E-mail:       peterdavidpodlovics@gmail.com
//Csoport:      1.csoport
//Feladat:      2.beadandó/7.feladat
//              Egyedi felsoroló header-je (itt van az implementáció is)


#ifndef ENOR_HPP_INCLUDED
#define ENOR_HPP_INCLUDED


StreamEnorException::StreamEnorException(const int errorCode, const std::string errorMsg)
 : errorCode(errorCode), errorMsg(errorMsg) {}

//Kiíró operátor a StreamEnorException típushoz.
std::ostream& operator<<(std::ostream& out, const StreamEnorException& e)
{
    std::cout << "***StreamEnorException:" << std::endl
    << "Error Code: " << e.errorCode << std::endl
    << "Error Message: " << e.errorMsg;
    return out;
}

//A ctor exception-t dob, ha a paraméterül kapott stream failbit-je igaz.
template<class T>
StreamEnor<T>::StreamEnor(std::istream& in)
 : stream(in) { if (stream.fail()) {throw StreamEnorException(1,"Not valid stream");} }

#endif // ENOR_HPP_INCLUDED
