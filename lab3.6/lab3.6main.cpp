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
            temp.push_back(convert(x,scale,'C'));
            temp.push_back(convert(x,scale,'K'));
            temp.push_back(convert(x,scale,'F'));
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
