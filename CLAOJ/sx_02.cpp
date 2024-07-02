#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#define ll  long long
#define ull  long long
using namespace std;

long long n, a[1000000], a1[1000000],sum=0;
vector< pair<ll, ll> > vect;

void input()
{
    cin >> n;
    for (ull i = 0; i < n; i++)
        cin >> a[i];
    for (ull i = 0; i < n; i++)
    {
        cin>>a1[i];
        a1[i]+=a[i]+1000000;
        a[i]+=1000000;
    }
}

bool firstsort(pair<ull, ull> a, pair<ull, ull> b)
{
    if (a.first < b.first)
        return true;
    else if (a.first > b.first)
            return false;
    else
        return a.second < b.second;
}

void pairarr()
{
    for (ull i = 0; i < n; i++)
        vect.push_back(make_pair(a[i], a1[i]));
    sort(vect.begin(), vect.end(), firstsort);
   //     cout<<endl;
  //  for (ull i = 0; i < n; i++)
  //      cout << vect[i].first << " " << vect[i].second << endl;
}

void xuly()
{

    ull maxx=0;
    for (ull i = 0; i < n; i++)
    {
       // fst = &vect[i].first;
       // sec = &vect[i].second;

        if(vect[i].second>=maxx||i==0)
        {
            if(vect[i].first <=maxx&&i!=0)
                sum=sum+(vect[i].second-vect[i].first)-(maxx-vect[i].first);
            else
                sum=sum+vect[i].second-vect[i].first;
           // cout<<sum<<" ";
       }
        if(vect[i].second>maxx)
            maxx=vect[i].second;
     //   cout<<sum<<" ";
    }
    cout<<sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    pairarr();
    xuly();
    return 0;
}
