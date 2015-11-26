#ifndef CONVERT_H_INCLUDED
#define CONVERT_H_INCLUDED

#endif // CONVERT_H_INCLUDED

enum Scale
 {
   Celsius,
   Kelvin,
   Fahrenheit
 };

struct Temperature
{
  Temperature(double value, char scale);
   Temperature();
  double value;
  char scale;
};

Temperature convert(Temperature tepm, Scale to);
