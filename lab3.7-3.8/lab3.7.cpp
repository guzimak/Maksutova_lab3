#include "sdt.h"
#include "convert.h"

int main()
{
    double x, tempC; //значение температуры
    char scale;
    vector<double> temp; //хранение значений температуры
    cout << "Enter temperature with its scale: ";
    while (cin>>x>>scale)
    {
        try
        {
            Scale s=change_format_scale(scale);
            temp.push_back(convert(x,s,Celsius));
            temp.push_back(convert(x,s,Kelvin));
            temp.push_back(convert(x,s,Fahrenheit));
        }
        catch (const invalid_argument& e)
        {
            cerr <<e.what();
        }
        catch (const logic_error& er)
        {
            cerr <<er.what();
        }
        catch (...)
        {
            cerr <<"Unknow error.\n";
        }
        cout << "Enter temperature with its scale: ";
    }
    //вывод на экран
    cout <<"   C\t   K\t   F\t\n";
    for (int i=0; i<temp.size(); i++)
    {
       printf("%6.2f\t",temp[i]);
        //cout <<temp[i] <<"\t";
        if ((i+1)%3==0) cout <<endl;
    }
}
