#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    set <int> s1;
    int N,M,S,temp;
    cin>>N>>M>>S;
    int a[200000]={0},b[200000],cnta=1;
    for(int x=1;x<=M;x++)
    {
        cin>>temp;
        s1.insert(temp);
    }
    for(auto it = s1.begin();it!=s1.end();it++)
        a[cnta++]=*it;
    sort(a,a+M+1);
    for(int x=1;x<=N;x++)
    {
        b[x]=x;
        if(x>=cnta)
            a[x]=0;
    }
    int r=1,l=1;
    
    int cnt=0;
    for(int x=1;x+M-1<=N;x++)
    {
        while(a[l]<b[x]&&l<cnta)
            l++;
        while(a[l]>=b[x]&&a[r]<=b[x+M-1]&&r<cnta)
        {
            
            if(M-(r-l+1)<=S)
            {
               // cout<<M-(r-l+1)<<" ";
              //  cout<<x<<endl;
                cnt++;
                break;
            }
            if(r<cnta-1)
                r++;
            else
                break;
        }
    }
    cout<<cnt;
}
