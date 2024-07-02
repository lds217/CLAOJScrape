#include <bits/stdc++.h>
using namespace std;

string reverse(string a)
{
    string b;
    for(int x=a.size()-1; x>=0; x--)
        b+=a[x];
    return b;
}

int main(int argc, char** argv)
{
    string a,b;
    cin>>a>>b;
    a=reverse(a);
    b=reverse(b);
    cout<<max(stoi(a),stoi(b));
}
