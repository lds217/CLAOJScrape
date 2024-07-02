#include <iostream>
#include <map>
using namespace std;
map <long long,int> k;
int main()
{
    int t;
    cin>>t;
    int sum=0;
    for(int i=1;i<=10000;i++)
        sum+=i,k[sum]=1;
    while(t--)
    {
        int tmp;
        cin>>tmp;
        cout<<(k[tmp]?"YES":"NO")<<endl;
    }
}
