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
#include <stdexcept>
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
#include <cassert>
#include <random>
using namespace std;

long long sol(long long a, long long b, long long lima, long long limb,long long n)
{
    if(n>a-lima) n-=(a-lima),a=lima;
    else    a-=n,n=0;
    
    if(n>b-limb)    b=limb;
    else    b-=n;
    return a*b;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b,lima,limb,n;
        cin>>a>>b>>lima>>limb>>n;
        cout<<min(sol(a,b,lima,limb,n),sol(b,a,limb,lima,n)) <<endl;  
    }
}
