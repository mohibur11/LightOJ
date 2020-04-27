#include<bits/stdc++.h>

#define ll              long long int
#define ull             unsigned long long int
#define pii             pair < int, int>
#define pll             pair < ll, ll>
#define sc              scanf
#define scin(x)         sc("%d",&(x))
#define scln(x)         sc("%lld",&(x))
#define pf              printf

using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}
ull phi[5000001];
int mark[5000001];

void sievephi(int n)
{
    int i,j;
    for(int i=1;i<=n;i++) phi[i] = i;
    phi[1] = 1;
    mark[1] = 1;

    for(int i=2;i<=n;i++)
    {
        if(!mark[i])
        {
            for(int j=i;j<=n;j+=i)
            {
                mark[j] = 1;
                phi[j] = phi[j]/i * (i-1);
            }
        }
    }
}
int main()
{
    sievephi(5000001);
    int i;
    for(i=1;i<=5000002;i++)
    {
        phi[i]*=phi[i];
        phi[i]+=phi[i-1];
    }
    int n,t,a,b;
    scin(n);
    for(i=1;i<=n;i++)
    {
        scin(a);scin(b);
        pf("Case %d: %llu\n", i,phi[b]-phi[a-1]);
    }

    return 0;
}

