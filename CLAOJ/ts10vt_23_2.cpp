#include <bits/stdc++.h>
using namespace std;

long long get(string &a)
{
    reverse(a.begin(), a.end());
    long long ans=0;
    for(int i=0;i<a.size();i++)
        ans+=(a[i]-'0')*pow(2,i);
    return ans;
}

int main(int argc, char** argv){
    string a,b;
    freopen("BAI2.INP","r",stdin);
    freopen("BAI2.OUT","w",stdout);
    cin>>a>>b;
    cout<<(long long)((floor)(sqrt(get(b)))-(ceil)(sqrt(get(a)))+1);
}
