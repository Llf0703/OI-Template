#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct tree{
    LL left,right,sum,delta;
};
tree jd[300005];
LL f[100005];
LL n,m,a,b,c,d,e,x,y,k;
void build(LL x,LL l,LL r)
{
    jd[x].left=l;
    jd[x].right=r;
    for (int i=l;i<r;i++) jd[x].sum+=f[i];
    if (r-l>1)
    {
        build(x*2,l,(r+l)/2);
        build(x*2+1,(r+l)/2,r);
    }
}
void update(LL x)
{
    jd[x*2].sum+=jd[x].delta*(jd[x*2].right-jd[x*2].left);
    jd[x*2+1].sum+=jd[x].delta*(jd[x*2+1].right-jd[x*2+1].left);
    jd[x*2].delta+=jd[x].delta;
    jd[x*2+1].delta+=jd[x].delta;
    jd[x].delta=0;
}
void change(LL x,LL l,LL r,LL delta2)
{
    if (l<=jd[x].left && r>=jd[x].right)
    {
        jd[x].sum+=delta2*(jd[x].right-jd[x].left);
        jd[x].delta+=delta2;
    }
    else
    {
        if (jd[x].delta!=0) update(x);
        if (l<(jd[x].right+jd[x].left)/2) change(x*2,l,r,delta2);
        if (r>(jd[x].right+jd[x].left)/2) change(x*2+1,l,r,delta2);
        jd[x].sum=jd[x*2].sum+jd[x*2+1].sum;
    }
}
LL query(LL x,LL l,LL r)
{
    if (l<=jd[x].left && r>=jd[x].right) return jd[x].sum;
    else
    {
        if (jd[x].delta!=0) update(x);
        LL ans=0;
        if (l<(jd[x].left+jd[x].right)/2) ans+=query(x*2,l,r);
        if (r>(jd[x].left+jd[x].right)/2) ans+=query(x*2+1,l,r);
        return ans;
    }
}
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    cin>>f[i];
    build(1,1,n+1);
    for (int i=1;i<=m;i++)
    {
        cin>>a;
        if (a==1)
        {
            cin>>x>>y>>k;
            change(1,x,y+1,k);
        }
        if (a==2)
        {
            cin>>x>>y;
            cout<<query(1,x,y+1)<<endl;
        }
    }
    return 0;
}
