#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    int limit;
    cin >> limit;
    string str;
    cin >> str;
    string HH, MM;
    HH = str.substr(0, 2);
    MM = str.substr(3, str.length());
    int numHH = stoi(HH);
    int numMM = stoi(MM);
    if (numHH > limit)
        HH[0] = '0';
    if (numMM > 59)
        MM[0] = '0';
    if(limit==12&&HH=="00")
        HH="10";
    cout<<HH<<":"<<MM;
}
