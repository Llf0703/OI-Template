#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct bian{
    LL w,f,g;
};
bian dian[500005];
LL n,m,s,a,b,c,d,e,i,j,cs;
LL ans[10005];
void songchi(int x,int y,int jl)
{
    if (ans[x]+jl<ans[y]) cs++;
    if (ans[x]<2147483647) ans[y]=min(ans[y],ans[x]+jl);
}
int main()
{
    cin>>n>>m>>s;
    for (a=1;a<=m;a++)
    cin>>dian[a].f>>dian[a].g>>dian[a].w;
    for (a=1;a<=n;a++)
    ans[a]=2147483647;
    ans[s]=0;
    cs=1;
    while (cs!=0)
    {
        cs=0;
        for (a=1;a<=m;a++)
        songchi(dian[a].f,dian[a].g,dian[a].w);
    }
    for (a=1;a<=n;a++)
    cout<<ans[a]<<" ";
    return 0;
}
