#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector <long long> s1;
    int n,k,t;
    cin>>n>>k;

    for(int x=0;x<n;x++)
        {
            cin>>t;
            s1.push_back(t);
        }
    int cnt=0;
    long long res=0,res1=0;
    sort(s1.begin(),s1.end());
    for(int i=0;i<k;i++)
        res+=s1[i];
 
    for(int i=n-2;i>n-2-k;i--)
        res1+=s1[i];

    
    cout<<res<<" "<<res1;
}
