#include <iostream>
using namespace std;

int main()
{
    for(int x=1;x<=100;x++)
    {
        cout<<x<<" ";
        if(x%10==0)
            cout<<endl;
    }
}
