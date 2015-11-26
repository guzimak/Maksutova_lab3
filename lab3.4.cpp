#include "sdt.h"
int last_error=0;

int get_last_error()
{
    return last_error;
}

double convert(double, char, char);

int main()
{
    double x, tempC; //�������� �����������
    char scale;
    vector<double> temp; //�������� �������� �����������
    cout << "Enter temperature with its scale: ";
    while (cin>>x>>scale)
    {
        //cout << "Enter temperature with its scale: ";
        //cin >>x;
        //cin >>scale;
        tempC=convert(x,scale,'C');
        switch (get_last_error())
        {
           case (1): cout <<"Unknow scale.\n";
                       break;
           case (2): cout <<"Temperature less than absolute zero!\n";
                       break;
           default:
                  temp.push_back(tempC);
                  temp.push_back(convert(x,scale,'K'));
                  temp.push_back(convert(x,scale,'F'));
        }
        last_error=0;
        cout << "Enter temperature with its scale: ";
    }
    //����� �� �����
    cout <<"C\t K\t F\t\n";
    for (int i=0; i<temp.size(); i++)
    {
       printf("%6.2f\t",temp[i]);
        //cout <<temp[i] <<"\t";
        if ((i+1)%3==0) cout <<endl;
    }
}

double convert(double temp, char from, char to)
{
    //������� � ����� �
    double tempC;
    switch (from)
    {
        case 'C': tempC=temp;
             break;
        case 'K': tempC=temp-273.15;
             break;
        case 'F': tempC=5/9.0*(temp-32);
             break;
        default: last_error=1; //������: ����������� �����
             return 0;
    }
    if (tempC<-273.15)
    {
        last_error=2; //������: ������������ �����������
        return 0;
    }
    //������� � ������ �����
    switch (to)
    {
        case 'C': return tempC;
             break;
        case 'K': return tempC+273.15;
             break;
        case 'F': return 1.8*tempC+32;
             break;
        default: last_error=1; //������: ����������� �����
        return 0;
    }
}
