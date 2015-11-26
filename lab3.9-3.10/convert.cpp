#include "sdt.h"
#include "convert.h"

Temperature convert(Temperature temp, Scale to)
{
    //перевод в шкалу —
    double tempC;
    Temperature answer;
    switch (temp.scale)
    {
        case 'C': tempC=temp.value;
             break;
        case 'K': tempC=temp.value-273.15;
             break;
        case 'F': tempC=5/9.0*(temp.value-32);
             break;
        default: throw invalid_argument("Unknow scale.\n");
    }
    if (tempC<-273.15)
        throw logic_error("Temperature less than absolute zero!\n");
    //перевод в нужную шкалу
    switch (to)
    {
        case Celsius: answer.value=tempC;
                      answer.scale='C';
                      break;
        case Kelvin:  answer.value=tempC+273.15;
                      answer.scale='C';
                      break;
        case Fahrenheit:  answer.value=1.8*tempC+32;
                          answer.scale='C';
                          break;
        default: throw invalid_argument("Unknow scale.\n");
    }
    return answer;
}
