#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,z,a,b,c,k,ans;
int f[5005];
struct lj{
    int qi,zhong,zhi;
};
lj map1[200005];
bool com(lj a,lj b)
{
    return a.zhi>b.zhi;
}
int zx(int a)
{
    if(a==f[a]) return a;
    else 
    {
        f[a]=zx(f[a]);
        return f[a];
    } 
}
int main()
{
    cin>>n>>m;
    for (a=1;a<=n;a++)
    f[a]=a;
    for (a=1;a<=m;a++)
    {
        cin>>x>>y>>z;
        map1[a].qi=x;
        map1[a].zhong=y;
        map1[a].zhi=z;
    }
    sort(map1,map1+m+1,com);
    while (m>0)
    {
        x=map1[m].qi;
        y=map1[m].zhong;
        if (zx(x)!=zx(y)) 
        {
            f[zx(y)]=zx(x);
            ans+=map1[m].zhi;
        }
        m--;
    }
    for (a=2;a<=n;a++)
    if (zx(a)!=zx(1))
    {
        cout<<"orz";
        return 0;
    }
    cout<<ans;
    return 0;
}
