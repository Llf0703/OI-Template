#include<bits/stdc++.h>
#define pr pair<int,int>
#define mp make_pair

using namespace std;

inline int read()
{
    char ch=getchar();
    int f=1,x=0;
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

struct Edge{
    int next,to,w;
} edge[400005];
int n,m,a,b,c,cnt,ct,head[5005],ans,mn[5005];
bool vis[5005];

inline void add(int u,int v,int w)
{
    edge[++cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
}

inline void prim()
{
    priority_queue <pr,vector<pr>,greater<pr> > q;
    q.push(mp(0,1));
    for (int i=1;i<=n;i++) mn[i]=1e9;
    mn[1]=0;
    memset(vis,0,sizeof(vis));
    while (!q.empty() && ct<n)
    {
        int x=q.top().second,qf=q.top().first; q.pop();
        if (vis[x]) continue;
        ans+=qf;
        ct++;
        vis[x]=1;
        for (int i=head[x];i;i=edge[i].next)
        {
            int y=edge[i].to,w=edge[i].w;
            if (w<mn[y])
            {
                mn[y]=w;
                q.push(mp(mn[y],y));
            }
        }
    }
}

int main()
{
    n=read(); m=read();
    for (int i=1;i<=m;i++)
    {
        a=read(); b=read(); c=read();
        add(a,b,c);
        add(b,a,c);
    }
    prim();
    if (ct==n) printf("%d",ans);
    else printf("orz");
    //system("pause");
    return 0;
}