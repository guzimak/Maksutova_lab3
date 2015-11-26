#include "sdt.h"
#include "convert.h"

int main()
{
    Temperature vvod;
    vector<Temperature> temp, tempC; //temp хранение значений температуры
                                     //tempC хранение в одной шкале
    cout << "Enter temperature with its scale: ";
    while (cin>>vvod)
    {
        try
        {
            temp.push_back(convert(vvod,Celsius));
            temp.push_back(convert(vvod,Kelvin));
            temp.push_back(convert(vvod,Fahrenheit));
            tempC.push_back(convert(vvod,Celsius));
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
        if ((i+1)%3==0) cout <<endl;
    }
    cout <<"\nMax temperature=" <<MaxTemp(tempC)<<endl;
    cout <<"Min temperature=" <<MinTemp(tempC)<<endl;
    cout <<"Mean temperature=" <<MeanTemp(tempC)<<endl;
}
