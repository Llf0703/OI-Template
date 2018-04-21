#include<bits/stdc++.h>
using namespace std;
int a[100005];
int f[100005][20];
int n,m,b,c;
void st(int n)
{
    for (int i=1;i<=n;i++) f[i][0]=a[i];
    for (int j=1;(1 << j)<=n;j++)
        for (int i=1;i+(1 << j)-1<=n;i++)
        f[i][j]=max(f[i][j-1],f[i+(1 << (j-1))][j-1]);
}
inline int query(int l,int r)
{
    int k=log2(r-l+1);
    return max(f[l][k],f[r-(1 << k)+1][k]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) cin>>a[i];
    st(n);
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&b,&c);
        printf("%d\n",query(b,c));
    }
    return 0;
}