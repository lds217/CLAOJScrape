#include <bits/stdc++.h>

using namespace std;

bool upperPrime(long long x){
	if (x%2==0 && x>2)
		return 0;
	else if (x%3==0 && x>3)
		return 0;
	else{
		long long k = (sqrt(x)+1)/6;
		for (int i=1;i<=k;i++)
			if ((x%(6*i+1) == 0) && (6*i+1 < x))
				return 0;
			else if((x%(6*i-1) == 0) && (6*i-1 < x))
				return 0;
	}
	return 1;
}

int main()
{
    int n;
    cin>>n;
    queue <long long> q;
    q.push(2);
    q.push(3);
    q.push(5);
    q.push(7);
//    cout<<q.front();
    if(n==1)
    {
        cout<<4<<endl;
        while(!q.empty())
             {
                cout<<q.front()<<endl;
                q.pop();
        
            }
    }
    int cnt=1;
    while(cnt<n)
    {
        int k=0;
        queue <long long> q2;
        while(!q.empty())
        {
            if(upperPrime(q.front()*10+1))
                q2.push(q.front()*10+1),k++;
            if(upperPrime(q.front()*10+3))
                q2.push(q.front()*10+3),k++;
            if(upperPrime(q.front()*10+7))
                q2.push(q.front()*10+7),k++;
            if(upperPrime(q.front()*10+9))
                q2.push(q.front()*10+9),k++;
            q.pop();
        }
        cnt++;
        q=q2;
        if(cnt==n)
        {
            cout<<k<<endl;
             while(!q2.empty())
             {
                cout<<q2.front()<<endl;
                q2.pop();
        
            }
        }
        
    }
   
}
