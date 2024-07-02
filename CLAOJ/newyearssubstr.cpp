#include <iostream>
#include <string>
using namespace std;

bool check ( char &a,char &b, char &c, char &d)
{
    string str="";
    str+=a;
    str+=b;
    str+=c;
    str+=d;
    return str == "2023";
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        string str;
        cin>>n>>str;
        if(check(str[0],str[1],str[2],str[3])||check(str[0],str[1],str[2],str[n-1])||check(str[0],str[1],str[n-2],str[n-1])||check(str[0],str[n-3],str[n-2],str[n-1])||check(str[n-4],str[n-3],str[n-2],str[n-1]))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
