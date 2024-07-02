#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    int N;
    cin>>N;
    while(N--)
    {
        string a;
        cin>>a;
        map <long long,int> k;
        while(a!="1")
        {
            long long sum=0;
            for(int i=0; i<a.size(); i++)
                sum+=(a[i]-'0')*(a[i]-'0');
            if(k[sum]==1)
            {
                cout<<"NO"<<endl;
                break;
            }
            else
                k[sum]++;
            a=to_string(sum);
          //   cout<<sum<<" ";
        }
        if(a=="1")
            cout<<"YES"<<endl;
    }
}
