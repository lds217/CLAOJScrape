#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,A,B;cin>>a>>b;A=a;B=b;
    string stra="",strb="";
    while(A>0)
    {
        stra+=(A%2)+'0';
        A=A/2;
    }
    reverse(stra.begin(),stra.end());
    while(B>0)
    {
        strb+=(B%2)+'0';
        B=B/2;
    }
    if(a==0)
        stra="0";
    if(b==0)
        strb="0";
    reverse(strb.begin(),strb.end());
   // cout<<stra<<" "<<strb<<endl;
  //  cout<<stra<<" "<<strb<<endl;
    if(strb.find(stra)!= string::npos)
    {
        cout<<a<<" nam trong "<<b<<endl;
        long long res=0;
        for(int x=0;x<stra.size();x++)
        {
            
            res+=(stra[x]-'0')*pow(2,stra.size()-x-1);
           // cout<<x<<" "<<res<<endl;
        }
        cout<<"So lon nhat nam trong "<<a<<" va "<<b<<" la: "<<res;
    }
    else
    {
        cout<<a<<" khong nam trong "<<b<<endl;
        string temp="";long long res=0,maxx=-1;bool yes=true;
         for(int x=0;x<stra.size();x++)
             for(int y=0;y<stra.size();y++)
                if(strb.find(stra.substr(x,y-x+1))!= string::npos)
                {
                    yes=false;
                    res=0;
                    temp=stra.substr(x,y-x+1);
                   // cout<<temp<<endl;
                    for(int x=0;x<temp.size();x++)
                        res+=(temp[x]-'0')*pow(2,temp.size()-x-1);
                    maxx=max(res,maxx);
                }
            if(yes==true)
            cout<<"Vo nghiem"  ; 
            else
             cout<<"So lon nhat nam trong "<<a<<" va "<<b<<" la: "<<maxx;
            
    }
}
