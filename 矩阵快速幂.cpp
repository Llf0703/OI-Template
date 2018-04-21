#include<bits/stdc++.h>
using namespace std;
long long n,k,a,b,c,d,e;
long long jz[105][105],x[105][105],y[105][105];
int main()
{
    cin>>n>>k;
    for (a=1;a<=n;a++)
    for (b=1;b<=n;b++)
        cin>>jz[a][b];
    for (a=1;a<=n;a++)
    x[a][a]=1;
    while (k!=0)
    {
        if (k&2!=0)//x=x*jz 
        {
            for (a=1;a<=n;a++)
            for (b=1;b<=n;b++)
            for (c=1;c<=n;c++)
            y[a][b]=(y[a][b]+(x[a][c]%1000000007)*(jz[c][b]%1000000007))%1000000007;
            for (a=1;a<=n;a++)
            for (b=1;b<=n;b++)
            x[a][b]=y[a][b]%1000000007;
            memset(y,0,sizeof(y));
        }
        k=k/2;
        for (a=1;a<=n;a++)
        for (b=1;b<=n;b++)
        for (c=1;c<=n;c++)
        y[a][b]=(y[a][b]+(jz[a][c]%1000000007)*(jz[c][b]%1000000007))%1000000007;		
        for (a=1;a<=n;a++)
        for (b=1;b<=n;b++)
        jz[a][b]=y[a][b]%1000000007;
        memset(y,0,sizeof(y));//jz=jz*jz;
    }
    for (a=1;a<=n;a++)
    {
        for (b=1;b<=n;b++)
        cout<<x[a][b]<<" ";
        cout<<endl;
    }
    return 0;
}