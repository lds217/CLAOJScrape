#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long N,K,a,b,res=0;
    vector  <pair<long long,long long>   > v;
    cin>>N>>K;
    for(int x=1;x<=N;x++)
    {
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());
 
    for(int x=0;x<N;x++)
    {
        if(v[x].first*v[x].second<K)
        {
            K=K-(v[x].first*v[x].second);
            res+=v[x].second;
        }
        else
            if(v[x].first*v[x].second>K)
            {
                res+=K/v[x].first;
                break;
            }
            else
            if(v[x].first*v[x].second==K)
            {
                res+=v[x].second;
                break;
            }

    }
    cout<<res;
}
