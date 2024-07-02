#include <iostream>
using namespace std;
int main()
{
    double S1, S2, v1, v2, t;
    cin >> S1 >> v1 >> S2 >> v2;
    if(v1 == v2)
	{
        cout << "-1";
		 return 0;
	}
    t = (S2 - S1)/(v1 - v2);
    if(t>=0)
        cout << (long long)t;
    else cout << "-1";
}
