#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL C[500005];
LL n,m,a,b,c;
LL lowbit(LL x)
{
    return x&-x;
}
void add(LL x,LL y)
{
    for (int i=x;i<=n;i+=lowbit(i)) C[i]+=y;
}
LL query(LL x)
{
    LL ans=0;
    for (int i=x;i;i-=lowbit(i)) ans+=C[i];
    return ans;
}
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++) 
    {
        scanf("%lld",&a);
        add(i,a);
    }
    for (int i=1;i<=m;i++)
    {
        scanf("%lld",&a);
        if (a==1)
        {
            scanf("%lld%lld",&b,&c);
            add(b,c);
        }
        if (a==2)
        {
            scanf("%lld%lld",&b,&c);
            LL ans=query(c)-query(b-1);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
