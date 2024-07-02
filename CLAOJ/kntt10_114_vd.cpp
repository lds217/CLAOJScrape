#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a,maxx=0,pos=0;
    for(int x=0;x<n;x++)
    {
        cin>>a;
        if(a>maxx)
        {
            maxx=a;
            pos=x;
        }
    }
    cout<<"Giá trị lớn nhất của dãy A: "<<maxx<<endl;
    cout<<"Chỉ số là: "<<pos;
}
