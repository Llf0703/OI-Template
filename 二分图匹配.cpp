#include<bits/stdc++.h>
using namespace std;
bool edge[1005][1005];
bool used[1005];
int mch[1005];
int n,m,e,a,b,c,ans;
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
    return x*f;
}
bool find(int x)
{
    for (int i=1;i<=m;i++)
        if (!used[i] && edge[x][i])
        {
            used[i]=true;
            if (!mch[i] || find(mch[i]))
            {
                mch[i]=x;
                return true;
            }
        }
    return false;
}
int main()
{
    memset(edge,false,sizeof(edge));
    n=read();m=read();e=read();
    for (int i=1;i<=e;i++)
    {
        int u=read(),v=read();
        if (v>m) continue;
        edge[u][v]=true;
    }
    for (int i=1;i<=n;i++)
    {
        memset(used,false,sizeof(used));
        ans+=find(i);
    }
    printf("%d",ans);
    return 0;
}