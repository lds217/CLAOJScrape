#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a;
    cin>>a;
    int gt;
    cin>>gt;
    int sum=0;
    for(int x=0;x<a.size();x++)
    {
        sum+=(a[x]-'a'+gt)%26;
    }
    cout<<sum;
}
