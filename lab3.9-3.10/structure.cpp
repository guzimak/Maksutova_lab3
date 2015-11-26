#include "convert.h"
#include "sdt.h"
Temperature::Temperature()
{
    this->value=-38.83;
    this->scale='C';
}

Temperature::Temperature(double value, char scale)
{
    this->value=value;
    this->scale=scale;
}
