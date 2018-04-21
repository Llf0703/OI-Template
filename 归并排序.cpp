#include<bits/stdc++.h>
using namespace std;
int n,m,p,i,j,k;
queue <int> q;
int f[100005];
void merge_sort(int a,int b)
{
	int s;
    if (a==b) return;
    s=(a+b)/2;
    merge_sort(a,s);
    merge_sort(s+1,b);
    i=a;
    j=s+1;
    while (i<=s&&j<=b)
    {
        if (f[i]>f[j]) 
        {
            q.push(f[j]);
            j++;
        }
        else
        {
            q.push(f[i]);
            i++;
        }
    }
    if (i>s) 
    for (int e=j;e<=b;e++) q.push(f[e]);
    if (j>b)
    for (int e=i;e<=s;e++) q.push(f[e]);
    k=a-1;
    while (!q.empty())
    {
        k++;
        f[k]=q.front();
        q.pop();
    }
}
int main()
{
    cin>>n;
    for (int a=1;a<=n;a++)
    cin>>f[a];
    merge_sort(1,n);
    for (int a=1;a<=n;a++)
    cout<<f[a]<<" ";
    return 0;
}
