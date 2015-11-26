enum Scale
 {
   Celsius,
   Kelvin,
   Fahrenheit
 };
double convert(double t, Scale from, Scale to);
Scale change_format_scale(char scale);
