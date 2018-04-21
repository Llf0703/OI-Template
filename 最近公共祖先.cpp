#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int to,next;
} edge[1000005];
struct Edge2{
    int to,next,lca;
} ask[1000005];
bool vis[500005];
int f[500005];
int head[1000005],hask[1000005];
int n,m,a,b,c,cnte,cnta,root;
inline void addedge(int u,int v)
{
    edge[cnte].to=v;
    edge[cnte].next=head[u];
    head[u]=cnte++;
}
inline void addask(int u,int v)
{
    ask[cnta].to=v;
    ask[cnta].next=hask[u];
    hask[u]=cnta++;
}
int find(int x)
{
    if (f[x]==x) return f[x];
    f[x]=find(f[x]);
    return f[x];
}
void merge(int x,int y)
{
    if (find(x)!=find(y)) f[find(x)]=find(y);
}
void tarjan(int u)
{
    vis[u]=true;
    for (int i=head[u];i!=-1;i=edge[i].next) 
    if (!vis[edge[i].to])
    {
        tarjan(edge[i].to);
        merge(edge[i].to,u);
    }
    for (int i=hask[u];i!=-1;i=ask[i].next)
    if (vis[ask[i].to]) ask[i].lca=ask[i^1].lca=find(ask[i].to);//i^1的含义是(0,1),(1,2)这些组的另一项
}
int main()
{
    memset(vis,false,sizeof(vis));
    memset(head,-1,sizeof(head));
    memset(hask,-1,sizeof(hask));
    scanf("%d%d%d",&n,&m,&root);
    for (int i=1;i<=n;i++) f[i]=i;
    for (int i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        addedge(a,b);
        addedge(b,a);
    }
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        addask(a,b);
        addask(b,a);
    }
    tarjan(root);
    for (int i=0;i<m*2;i+=2) printf("%d\n",ask[i].lca);//因为加入两次，而相邻两次的lca又相同
    return 0;
}