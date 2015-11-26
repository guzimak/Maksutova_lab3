#include "sdt.h"
enum error
{
 ErrScale, //неизвестная шкала
 ErrTemp,  //температура меньше абсолютного нуля
};

error convert(double, char, char,double*);

int main()
{
    double x,result; //значение температуры
    char scale;
    vector<double> temp; //хранение значений температуры
    cout << "Enter temperature with its scale: ";
    while (cin>>x>>scale)
    {
        switch (convert(x,scale,'C',&result))
        {
           case (ErrScale): cout <<"Unknow scale.\n";
                       break;
           case (ErrTemp): cout <<"Temperature less than absolute zero!\n";
                       break;
           default:
                  convert(x,scale,'C',&result);
                  temp.push_back(result);
                  convert(x,scale,'K',&result);
                  temp.push_back(result);
                  convert(x,scale,'F',&result);
                  temp.push_back(result);
        };
        cout << "Enter temperature with its scale: ";
    }
    cout <<"C\t K\t F\t\n";
    for (int i=0; i<temp.size(); i++)
    {
       printf("%6.2f\t",temp[i]);
        //cout <<temp[i] <<"\t";
        if ((i+1)%3==0) cout <<endl;
    }
}

error convert(double temp, char from, char to, double* result)
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
        default: return ErrScale; //ошибка: неизвестная шкала
    }
    if (tempC<-273.15)
    {
        return ErrTemp; //ошибка: недопустимая температура
    }
    //перевод в нужную шкалу
    switch (to)
    {
        case 'C': *result=tempC;
             break;
        case 'K': *result=tempC+273.15;
             break;
        case 'F': *result=1.8*tempC+32;
             break;
        default: return ErrScale; //ошибка: неизвестная шкала
    }
}
