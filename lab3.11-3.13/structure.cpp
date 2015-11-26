#include "convert.h"
#include "sdt.h"
Temperature::Temperature()
{
    this->value=451;
    this->scale=Fahrenheit;
}

Temperature::Temperature(double value, Scale scale)
{
    this->value=value;
    this->scale=scale;
}

//операторы ввода-вывода для структуры
istream& operator>>(istream& input, Temperature& temp)
{
    input>>temp.value >>temp.scale;
    return input;
}

ostream& operator<<(ostream& output, const Temperature& temp)
{
    output<<temp.value <<temp.scale;
    return output;
}
//операторы ввода-вывода для перечисления
istream& operator>>(istream& input, Scale& scale)
{
    char s;
    input>>s;
    switch(s)
    {
        case 'C': scale=Celsius;
        break;
        case 'K': scale=Kelvin;
        break;
        case 'F': scale=Fahrenheit;
        break;
        default: input.setstate(ios_base::failbit); //ошибка
    }
    return input;
}
ostream& operator<<(ostream& output, const Scale& scale)
{
    switch(scale)
    {
        case Celsius: output<<'C';
        break;
        case Kelvin: output<<'K';
        break;
        case Fahrenheit: output<<'F';
        break;
    }
    return output;
}
//перегрузка операторов
bool operator>(const Temperature& left, const Temperature& right)
{
    Temperature newT=convert(right, left.scale);
    return left.value>newT.value;
}

Temperature operator+(const Temperature& left, const Temperature& right)
{
    Temperature newT=convert(right, left.scale);
    return  {left.value+newT.value,
             left.scale};
}

Temperature operator+=(Temperature& left, const Temperature& right)
{
    Temperature newT=convert(right, left.scale);
    left.value+=newT.value;
    return left;
}

Temperature operator/(Temperature& left, const int division)
{
    return  {left.value/division,
             left.scale};
}


Temperature operator/=(Temperature& left, const int division)
{
    left.value/=division;
    return left;
}

//пункт 13
Temperature MaxTemp(vector<Temperature> temp)
{
    Temperature MaxT={-373, Celsius};
    for (int i=0; i < temp.size(); i++)
    {
        if (temp[i].value > MaxT.value)
            MaxT=temp[i];
    }
    return MaxT;
}

Temperature MinTemp(vector<Temperature> temp)
{
    Temperature MinT={10000, Celsius};
    for (int i=0; i < temp.size(); i++)
    {
        if (temp[i].value < MinT.value)
            MinT=temp[i];
    }
    return MinT;
}

Temperature MeanTemp(vector<Temperature> temp)
{
    Temperature MeanT={0, Celsius};
    for (int i=0; i < temp.size(); i++)
    {
        MeanT+=temp[i];
    }
    MeanT/=temp.size();
    return MeanT;
}
