#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        string str;
        int dup[27]={0},res=0;   
        cin>>str;
        for(int i=0; i<str.size(); i++)
            dup[str[i]-'a']++;
       for(int i=0; i<str.size(); i++)
       {
            if(dup[str[i]-'a']==1)
            {
                cout<<i+1<<endl;
                break;
            }
            if(i==str.size()-1)
                cout<<-1<<endl;
       }
    
    }
}
