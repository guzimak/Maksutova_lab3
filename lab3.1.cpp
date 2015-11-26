#include "sdt.h"
double convert(double, char, char);

int main()
{
    double x; //значение температуры
    char scale;
    vector<double> temp; //хранение значений температуры
    while (cin)
    {
        cout << "Enter temperature with its scale: ";
        cin >>x;
        cin >>scale;
        temp.push_back(convert(x,scale,'C'));
        temp.push_back(convert(x,scale,'K'));
        temp.push_back(convert(x,scale,'F'));
    }
    //вывод на экран
    cout <<"C\t K\t F\t\n";
    for (int i=0; i<temp.size(); ++i)
    {
        cout <<temp[i] <<"\t";
        if ((i+1)%3==0) cout <<endl;
    }
}

double convert(double temp, char from, char to)
{
    //перевод в шкалу С
    double tempC;
    switch (from)
    {
        case 'C': tempC=temp;
             break;
        case 'K': tempC=temp-273.15;
             break;
        case 'F': tempC=5/9.0*(temp-32);
             break;
        default: cout <<"Unknow scale.\n";
             return 0;
    }
    if (tempC<-273.15)
    {
        cout <<"Temperature less than absolute zero!\n";
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
        default: cout <<"Unknow scale.\n";
    }
}
