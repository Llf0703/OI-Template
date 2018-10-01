#include<bits/stdc++.h>
using namespace std;

int mn[10005],vis[10005],head[1000005],n,m,a,b,c,s,cnt=1;
struct Edge{
    int next,to,w;
} edge[1000005];
struct cmp{
    bool operator()(int x,int y){
        return mn[x]>mn[y];
    }
};

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

inline void add(int u,int v,int w)
{
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    edge[cnt].w=w;
    head[u]=cnt++;
}

inline void dijkstra()
{
    priority_queue<int,vector<int>,cmp > q;
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;i++) mn[i]=2147483647;
    mn[s]=0;
    q.push(s);
    while (!q.empty())
    {
        int x=q.top();
        q.pop();
        if (vis[x]) continue;
        vis[x]=1;
        for (int i=head[x];i;i=edge[i].next)
        {
            int y=edge[i].to,w=edge[i].w;
            mn[y]=min(mn[y],mn[x]+w);
            q.push(y);
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
    for (int i=1;i<=n;i++) printf("%d ",mn[i]);
    return 0;
}