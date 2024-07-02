#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int n;
    cin>>n;
    long long a[100000];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n%2==0)
    {
        cout<<'[';
        for(int i=1;i<=n;i++)
        {
            if(i==n/2||i==n/2+1)
                continue;
            else
            {
                if(i!=n)
                    cout<<a[i]<<", ";
                else
                    cout<<a[i];
            }
        }
        cout<<']';
    }
    else
    {
        cout<<'[';
        for(int i=1;i<=n;i++)
        {
            if(i==n/2+1)
                continue;
            else
            {
                if(i!=n)
                    cout<<a[i]<<", ";
                else
                    cout<<a[i];
            }
        }
        cout<<']';
    }
}
