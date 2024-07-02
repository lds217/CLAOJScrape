#include <iostream>
#include <cmath>
using namespace std;


int main(int argc, char **argv)
{
    double u,d,x;
    cin >> u >> d >> x ;
    double p=1;
     double n  =(x-u);
     n=n/d;
     n++;
    if(round(n)==n)
        cout<< n;
    else
        cout<<-1;

}
