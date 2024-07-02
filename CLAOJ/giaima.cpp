#include <iostream>
#include <string>
using namespace std;

int main()
{
    char res[20000];
    string str,num;cin>>num>>str;
    int size=str.size();
    int sz=num.size();
    for(int x=0;x<sz;x++) 
    {
        int run=(x+1)*(size/sz);  
        int cnt=num[x]-'0';   
        for(int y=run-((size/sz))+1;y<=run;y++)  
        {
            res[cnt]=str[y-1]; 
            cnt+=sz;
        }
    }
    for(int x=1;x<=size;x++)
            cout<<res[x];
    
}
