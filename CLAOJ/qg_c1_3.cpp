#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <unordered_set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <cmath>
#include <array>
#include <random>
#define FOR(i, a, b) for(int i=a, _b=b; i<=_b; ++i)
#define FORD(i, a, b) for(int i=a, _b=b; i>=_b; --i)
#define pb push_back
#define fi first
#pragma GCC optimize ("O3")
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define task "SKP"

using namespace std;
typedef pair<int, int> ii;
const int maxn=3e5+1;
typedef long long ll;
bool minimize(int &A, int B)
{
    return A>B ? A=B, true : false;
}


//main
int n;
ii a[maxn];
ll dp[maxn];
void input()
{
	cin>>n;
    FOR(i,1,n)  cin>>a[i].fi;
    FOR(i,1,n) cin>>a[i].se;
}
int opt[maxn];
void lds_go_goooo()
{
	mset(dp,-0x3f);
    dp[0]=0;
    opt[0]=1;
    FOR(i,1,n)
    {
        int h=a[i].fi;
        int minn=a[i].se;
        FORD(j,i,opt[i-1])
        {  
            if(a[j].fi<h)   
            {
                h=a[j].fi;
                minn=a[j].se;
            }
            if(dp[i]<dp[j-1]+minn)
                opt[i]=j;
            dp[i]=max(dp[i],dp[j-1]+minn);
        }
    }
    cout<<dp[n];
}

int main()
{
 //	ios_base::sync_with_stdio(false);
  //  cin.tie(0);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
   // int test_case=1; //cin>>test_case;
   // while(test_case--)
    //{
        input(), lds_go_goooo();
        cout<<'\n';
   // }
    return 0;
}
