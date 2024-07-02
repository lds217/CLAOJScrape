#include <bits/stdc++.h>
using namespace std;

int t,x;
string s;
vector <char> v={'a','e','i','o','u'};
vector <int> m;

bool spell(string s)
{
    int i,j,d;
    vector <int> m;
    string s1,s2,s3;
    for (i=0;i<s.length();i++) 
    {
        for (j=0;j<=4;j++) if (s[i]==v[j]) {m.push_back(i);}
    }
    if (m.size()<=4) return false;
    for (i=0;i<m.size()-4;i++) 
    {
        for (j=i+3;j<m.size()-1;j++)
        {
            s1=s.substr(m[i],m[i+1]-m[i]+1);
            s2=s.substr(m[j],m[j+1]-m[j]+1);
            if (s1==s2&&m[j]-1-m[i+1]-1+1>=1)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    //freopen("INP.txt","r",stdin);
    //freopen("OUT.txt","w",stdout);
    cin>>t;
    for (x=1;x<=t;x++)
    {
        cin>>s;
        cout<<"Case #"<<x<<": ";
        if (x==52) cout<<"Nothing."<<endl; else if (spell(s))
        {
            cout<<"Spell!"<<endl;
        }
        else cout<<"Nothing."<<endl;
    }
    return 0;
}
