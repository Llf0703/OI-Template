#include<bits/stdc++.h>
using namespace std;
double f[105][105];
int n,a,b,c;
double jie[101],m;
void change(int a,int b)
{
    for (int i=1;i<=n+1;i++)
    {
        double c=f[a][i];
        f[a][i]=f[b][i];
        f[b][i]=c;
    }
}
void big(int k)
{
    int mx=k;
    double mxz=f[k][k]; 
    for (int i=k;i<=n;i++)
    if (f[i][k]>mxz)
    {
        mxz=f[i][k];
        mx=i;
    }
    change(k,mx);
}
void tone(int k)
{
    double v=f[k][k];
    for (int i=k;i<=n+1;i++)
    f[k][i]/=v;
}
void xiaoyuan(int k)
{
    for (int i=k+1;i<=n;i++)
    {
    	double v=f[i][k];
        for (int j=k;j<=n+1;j++)
        f[i][j]-=v*f[k][j];
    }
}
int main()
{
    cin>>n;
    for (a=1;a<=n;a++)
        for (b=1;b<=n+1;b++)
        cin>>f[a][b];
    for (a=1;a<=n-1;a++)
    {
        big(a);
        tone(a);
        xiaoyuan(a);
    }
    tone(n);
    for (a=1;a<=n;a++)
    if (f[a][a]!=1)
    {
    	cout<<"No Solution";
    	return 0;
	}
	for (a=2;a<=n;a++)
	for (b=1;b<=a-1;b++)
	if (f[a][b]!=0)
	{
		cout<<"No Solution";
		return 0;
	}
    int v;
    for (a=n;a>=1;a--)
    {
        m=0;
        for (b=1;b<=n-a;b++)
        m+=jie[b]*f[a][n+1-b];
        v++;
        jie[v]=(f[a][n+1]-m)/f[a][a];
    }
    for (a=n;a>=1;a--)
    cout<<fixed<<setprecision(2)<<jie[a]<<endl;
    return 0;
}
