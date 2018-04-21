#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,n,m;
priority_queue <int,vector <int>, greater<int> > q;
int main()
{
    cin>>n;
    for (a=1;a<=n;a++)
    {
        cin>>b;
        if (b==1)
        {
            cin>>c;
            q.push(c);
            continue;
        }
        if (b==2)
        {
            cout<<q.top()<<endl;
            continue;
        }
        if (b==3) q.pop();
    }
    return 0;
}