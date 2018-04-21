#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c,d,e;
bool ss[10000005];
int main()
{
    cin>>n>>m;
    memset(ss,false,sizeof(ss));
    ss[1]=true;
    for (a=2;a<=sqrt(n);a++)
    for (b=2;b<=n/a;b++)
    ss[a*b]=true;
    for (a=1;a<=m;a++)
    {
        cin>>d;
        if (ss[d]==false) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
