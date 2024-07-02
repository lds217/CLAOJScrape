#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
    char n;
    string str;
    cin>>n>>str;
    list<char> v1;
    v1.push_back(n);
    char temp=n;
    for(int i = 0; i <str.size(); i++)
    {
        if(str[i]<=n)
        {
            v1.push_front(str[i]);
            n=str[i];
        }
        else
            v1.push_back(str[i]);
    }
    for(auto it = v1.begin(); it != v1.end(); it++)
        cout<<*it;
}
