#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c,d,e;
int f[10005];
int zx(int x)
{
    if (f[x]==x) return f[x];
    f[x]=zx(f[x]);
    return f[x];
}
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    f[i]=i;
    for (int i=1;i<=m;i++)
    {
        cin>>a>>b>>c;
        if (a==1&&zx(b)!=zx(c)) f[zx(b)]=zx(c);
        if (a==2) if (zx(b)==zx(c)) cout<<"Y"<<endl;
                  else cout<<"N"<<endl;
    }
    return 0;
}