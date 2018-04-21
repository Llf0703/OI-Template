#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int next,to;
} edge[200005];
int fa[200005],size[200005],deep[200005],w[200005],wnew[200005],head[200005],son[200005],id[200005],top[200005];
struct Tree{
    int left,right,sum,delta;
} tree[800005];
int cnt=1,ans,n,m,a,b,c,d,p,dfsord,root;
inline void add(int u,int v)
{
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void build(int x,int l,int r)
{
    tree[x].left=l;
    tree[x].right=r;
    if (r-l==1) tree[x].sum=wnew[l];
    else
    {
        build(x*2,l,(l+r)/2);
        build(x*2+1,(l+r)/2,r);
        tree[x].sum=(tree[x*2].sum+tree[x*2+1].sum)%p;
    }
}
inline void update(int x)
{
    tree[x*2].sum+=tree[x].delta*(tree[x*2].right-tree[x*2].left);
    tree[x*2+1].sum+=tree[x].delta*(tree[x*2+1].right-tree[x*2+1].left);
    tree[x*2].sum%=p;
    tree[x*2+1].sum%=p;
    tree[x*2].delta+=tree[x].delta;
    tree[x*2+1].delta+=tree[x].delta;
    tree[x].delta=0;
}
void change(int x,int l,int r,int delta)
{
    if (l<=tree[x].left && r>=tree[x].right) 
    {
        tree[x].delta+=delta;
        tree[x].sum+=delta*(tree[x].right-tree[x].left);
        tree[x].sum%=p;
    }
    else
    {
        if (tree[x].delta!=0) update(x);
        if (l<(tree[x].left+tree[x].right)/2) change(x*2,l,r,delta);
        if (r>(tree[x].left+tree[x].right)/2) change(x*2+1,l,r,delta);
        tree[x].sum=(tree[x*2].sum+tree[x*2+1].sum)%p;
    }
}
int query(int x,int l,int r)
{
    if (l<=tree[x].left && r>=tree[x].right) return tree[x].sum%p;
    else
    {
        if (tree[x].delta!=0) update(x);
        int ans=0;
        if (l<(tree[x].left+tree[x].right)/2) ans+=query(x*2,l,r);
        if (r>(tree[x].left+tree[x].right)/2) ans+=query(x*2+1,l,r);
        return ans%p;
    }
}               
/*  dfs1
    标记每个点的深度dep[]   
    标记每个点的父亲fa[]
    标记每个非叶子节点的子树大小(含它自己)    
    标记每个非叶子节点的重儿子编号son[]
*/
void dfs1(int x,int f,int depth)
{
    deep[x]=depth;
    fa[x]=f;
    size[x]=1;
    int mx=-1;
    for (int i=head[x];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if (v==f) continue;//不搜索父节点
        dfs1(v,x,depth+1);
        size[x]+=size[v];
        if (size[v]>mx) //更新重儿子
        {
            mx=size[v];
            son[x]=v;
        }
    }
}
/*  dfs2
    标记每个点的新编号
    赋值每个点的初始值到新编号上
    处理每个点所在链的顶端
    处理每条链
*/
void dfs2(int x,int topf)
{
    id[x]=++dfsord;//标记每一个节点的dfs序
    wnew[dfsord]=w[x];//得到新编号（dfs序）
    top[x]=topf;//得到这条链的顶端
    if (!son[x]) return;//无儿子返回
    dfs2(son[x],topf);//先处理重儿子
    for (int i=head[x];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if (v==fa[x] || v==son[x]) continue;
        dfs2(v,v);//如果是轻儿子，新的链一定以自己为顶端
    }
}
int qrange(int u,int v)//求u到v节点的路径中节点之和
{
    int ans=0;
    while (top[u]!=top[v])//不停将u向上跳，直到在一条链上
    {
        if (deep[top[u]]<deep[top[v]]) swap(u,v);//交换成更深的点
        ans+=query(1,id[top[u]],id[u]+1);
        ans%=p;
        u=fa[top[u]];//向上跳
    }
    //已经在一条链上
    if (deep[u]>deep[v]) swap(u,v);
    ans+=query(1,id[u],id[v]+1);
    ans%=p;
    return ans;
}
void uprange(int u,int v,int delta)
{
    delta%=p;
    while (top[u]!=top[v])
    {
        if (deep[top[u]]<deep[top[v]]) swap(u,v);
        change(1,id[top[u]],id[u]+1,delta);
        u=fa[top[u]];
    }
    if (deep[u]>deep[v]) swap(u,v);
    change(1,id[u],id[v]+1,delta);
}
inline int qson(int u)
{
    return query(1,id[u],id[u]+size[u]);//子树区间右端点为id[x]+siz[x]-1 
}
inline void upson(int u,int delta)
{
    change(1,id[u],id[u]+size[u],delta);
}
int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d%d%d%d",&n,&m,&root,&p);
    for (int i=1;i<=n;i++) scanf("%d",&w[i]);
    for (int i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    dfs1(root,0,1);
    dfs2(root,root);
    build(1,1,n+1);//注意先搜索以后再建树
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&a);
        if (a==1)
        {
            scanf("%d%d%d",&b,&c,&d);
            uprange(b,c,d);
        }
        if (a==2)
        {
            scanf("%d%d",&b,&c);
            printf("%d\n",qrange(b,c));
        }
        if (a==3)
        {
            scanf("%d%d",&b,&c);
            upson(b,c);
        }
        if (a==4)
        {
            scanf("%d",&b);
            printf("%d\n",qson(b));
        }
    }
    return 0;
}