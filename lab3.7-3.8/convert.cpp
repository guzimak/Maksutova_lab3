#include "sdt.h"
#include "convert.h"

Scale change_format_scale(char scale)
{   switch (scale)
      {
       case 'C': return Celsius;
                 break;
       case 'F': return Fahrenheit;
                 break;
       case 'K': return Kelvin;
                 break;
       default: throw invalid_argument("Unknow scale.\n");
       }
}

double convert(double temp, Scale from, Scale to)
{
    //перевод в шкалу —
    double tempC;
    switch (from)
    {
        case Celsius: tempC=temp;
             break;
        case Kelvin: tempC=temp-273.15;
             break;
        case Fahrenheit: tempC=5/9.0*(temp-32);
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
        case Celsius: return tempC;
             break;
        case Kelvin: return tempC+273.15;
             break;
        case Fahrenheit: return 1.8*tempC+32;
             break;
        default: throw invalid_argument("Unknow scale.\n");
                 return 0;
    }
}
