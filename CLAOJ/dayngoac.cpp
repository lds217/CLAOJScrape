#include <bits/stdc++.h>
using namespace std;

bool check(char a)
{
    if (a == '(' || a == '{' || a == '[' || a == '<')
        return true;
    else
        return false;
}

bool checks(char a, char b)
{
    if ((a == ')' && b == '(') || (a == '>' && b == '<') || (a == ']' && b == '[') || (a == '}' && b == '{'))
        return 0;
    else
        return 1;
}

int main()
{
    stack<char> bracket;
    string str;
    cin >> str;
    int ans = 0;
    int open=0;
    for (int x = 0; x < str.length(); x++)
    {
        if (check(str[x]))
        {
            bracket.push(str[x]);
            open++;
        }
        else
        {
            if(bracket.empty())
            {
                cout<<-1;
                return 0;
            }
            char temp = bracket.top();
            bracket.pop();
            if (checks(str[x], temp))
                ans++;
        }
    }
    if(open==str.length()||!bracket.empty())
    {
        cout<<-1;
        return 0;
    }
    cout << ans;
}
