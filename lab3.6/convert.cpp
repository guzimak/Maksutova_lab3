#include "sdt.h"
#include "convert.h"

double convert(double temp, char from, char to)
{
    //перевод в шкалу —
    double tempC;
    switch (from)
    {
        case 'C': tempC=temp;
             break;
        case 'K': tempC=temp-273.15;
             break;
        case 'F': tempC=5/9.0*(temp-32);
             break;
        default: throw invalid_argument("Unknow scale.\n");
                 return 0;
    }
    if (tempC<-273.15)
    {
        throw logic_error("Temperature less than absolute zero!\n");
        return 0;
    }
    //перевод в нужную шкалу
    switch (to)
    {
        case 'C': return tempC;
             break;
        case 'K': return tempC+273.15;
             break;
        case 'F': return 1.8*tempC+32;
             break;
        default: throw invalid_argument("Unknow scale.\n");
                         return 0;
    }
}
