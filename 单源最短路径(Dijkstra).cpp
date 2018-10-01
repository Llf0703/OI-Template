#include<bits/stdc++.h>
#define ll long long
#define pr pair<long long,long long>
#define mp make_pair

using namespace std;

ll mn[100005],vis[100005],head[200005],n,m,a,b,c,s,cnt=1;
struct Edge{
    ll next,to,w;
} edge[400005];

inline ll read()
{
    char ch=getchar();
    ll f=1,x=0;
    while (ch<'0' || ch>'9')
    {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0' && ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return f*x;
}

inline void add(ll u,ll v,ll w)
{
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    edge[cnt].w=w;
    head[u]=cnt++;
}

inline void dijkstra()
{
    priority_queue<pr,vector<pr>,greater<pr> > q;
    memset(vis,0,sizeof(vis));
    for (ll i=1;i<=n;i++) mn[i]=2e9;
    mn[s]=0;
    q.push(mp(mn[s],s));
    while (!q.empty())
    {
        ll x=q.top().second;
        q.pop();
        if (vis[x]) continue;
        vis[x]=1;
        for (ll i=head[x];i;i=edge[i].next)
        {
            ll y=edge[i].to,w=edge[i].w;
            if (mn[y]>mn[x]+w)
            {
                mn[y]=mn[x]+w;
                q.push(mp(mn[y],y));
            }
        }
    }
}

int main()
{
    n=read(); m=read(); s=read();
    for (int i=1;i<=m;i++)
    {
        a=read(); b=read(); c=read();
        add(a,b,c);
    }
    dijkstra();
    for (int i=1;i<=n;i++) printf("%lld ",mn[i]);
    //system("pause");
    return 0;
}