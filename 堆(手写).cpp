#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c,d,e;
int f[1000005];
void change(int &a,int &b)
{
    int c;
    c=a;
    a=b;
    b=c;
}
void putf(int a)
{
    m++;
    f[m]=a;
    int k;
    k=m;
    while (f[k/2]>f[k]&&k>=2) 
    {
        change(f[k/2],f[k]);
        k=k/2;
    }
}
void deletef()
{
    int k;
    f[1]=f[m];
    m--;
    k=1;
    while ((f[k*2]<f[k]||f[k*2+1]<f[k])&&k*2<=m)
    {
        if ((f[k*2]<f[k*2+1])||k*2+1>m) 
        {
            change(f[k*2],f[k]);
            k*=2;
        }
        else
        {
            change(f[k*2+1],f[k]);
            k=k*2+1;
        }
    }
}
void writef()
{
    cout<<f[1]<<endl;
}
int main()
{
    cin>>n;
    for (a=1;a<=n;a++)
    {
        cin>>b;
        if (b==1) 
        {
            cin>>c;
            putf(c);
        }
        if (b==2) writef();
        if (b==3) deletef();
    }
    return 0;
}
