#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> stk;
stack<int> trace;
int a[1000001]={0},open,close;
void rightbracket(string str)
{
    for(int x=0;x<str.length();x++)
    {   
        if(str[x]=='(')
        {
            stk.push(str[x]);
            trace.push(x+1);
        }
        else
        {
            if(stk.empty())
                close=x+1;
            else
            {
                stk.pop();
                trace.pop();
            }
        }
    }
    while(!trace.empty())
    {
        open=str.size()-trace.top()+1;
        trace.pop();
    }
}

int main()
{
    string str;
    cin>>str;
    int check=0;
    for(int x=0;x<str.size();x++)
        if(str[x]=='(')
            check++;
        else
            check--;
    if(check != 0)
    {
        cout<<-1;
        return 0;
    }
    else
    {
        rightbracket(str);
        cout<<min(open,close);
    }
}
