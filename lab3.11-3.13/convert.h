#include "sdt.h"

enum Scale: char
 {
   Celsius='C',
   Kelvin='K',
   Fahrenheit='F'
 };

struct Temperature
{
  Temperature(double value, Scale scale);
  Temperature();
  double value;
  Scale scale;
};

Temperature convert(Temperature tepm, Scale to);

//операторы ввода-вывода для структуры
istream& operator>>(istream& input, Temperature& temp);
ostream& operator<<(ostream& output, const Temperature& temp);

//операторы ввода-вывода для перечисления
istream& operator>>(istream& input, Scale& scale);
ostream& operator<<(ostream& output, const Scale& scale);

//перегрузка операторов
bool operator>(const Temperature left, const Temperature right);
Temperature operator+(const Temperature& left, const Temperature& right);
Temperature operator+=(Temperature& left, const Temperature& right);
Temperature operator/(Temperature& left, const int division);
Temperature operator/=(Temperature& left, const int division);

//пункт 13
Temperature MaxTemp(vector<Temperature> temp);
Temperature MeanTemp(vector<Temperature> temp);
Temperature MinTemp(vector<Temperature> temp);
