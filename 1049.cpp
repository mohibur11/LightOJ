#include<bits/stdc++.h>

#define ll              long long int
#define ull             unsigned long long int
#define pii             pair < int, int>
#define pll             pair < ll, ll>
#define sc              scanf
#define scin(x)         sc("%d",&(x))
#define scln(x)         sc("%lld",&(x))
#define pf              printf
#define NL              pf("\n")
#define ms(a,b)         memset(a,b,sizeof(a))
#define pb(a)           push_back(a)
#define mp              make_pair
#define db              double
#define EPS             10E-10
#define ff              first
#define ss              second
#define sqr(x)          (x)*(x)
#define vi              vector< int >
#define vl              vector< ll >
#define vii             vector<vector< int > >
#define vll             vector<vector< ll > >
#define DBG             pf("HI\n")
#define MOD             1000000007
#define CIN             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define RUN_CASE(t,T)   for(__typeof(t) t=1;t<=T;t++)
#define CASE(t)         printf("Case %d: ",t)
#define CASEL(t)        printf("Case %d:\n",t)
#define intlimit        2147483648
#define longlimit       9223372036854775808
#define infinity        (1<<28)
#define gcd(a, b)       __gcd(a,b)
#define lcm(a, b)       ((a)*(b)/gcd(a,b))
#define mx              1234567899
#define PI              2*acos(0.0)
#define rep(i,a,b)      for(ll i=a; i<=b; i++)
#define rev(i,a,b)      for(ll i=a; i>=b; i--)
#define file            freopen("E:\\file.txt", "r", stdin);ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(x)            x.begin(),x.end()
using namespace std;

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

bool cmp(int a,int b)
{
    return a>b;
}
map < pair < int,int>, int > MAP;
int visited[1005];
vector<int >adj[1005];
int ans1, ans2, tmp;
void dfs(int node)
{
    visited[node]=1;
    for(int i=0;i<adj[node].size();i++)
    {
        tmp = adj[node][i];

        if(tmp==1)
        {
            if(visited[tmp]==2)
            {
                if(MAP[mp(node,tmp)]>0)
                {
                    ans2+=MAP[mp(node,tmp)];
                }
                else
                    ans1+=MAP[mp(tmp,node)];
            }
            else if(visited[tmp]==1)
                visited[tmp] = 2;

        }
        if(!visited[tmp])
        {
            if(MAP[mp(node,tmp)]>0)
            {
                ans2+=MAP[mp(node,tmp)];
            }
            else
            {
                ans1+=MAP[mp(tmp,node)];
            }


            dfs(tmp);
        }
    }
}
void reset(int n)
{
    for(int i=0;i<=n;i++)
    {
        visited[i] = 0;
        adj[i].clear();
    }
    MAP.clear();
}
int main()
{
    int t,T, n, x, y, c;
    scin(T);
    RUN_CASE(t,T)
    {
        scin(n);
        for(int i=0;i<n;i++)
        {
            scin(x);scin(y);scin(c);
            adj[x].pb(y);
            adj[y].pb(x);
            MAP[mp(x,y)] = c;
        }
        for(int i=1;i<=n;i++) sort(adj[i].begin(), adj[i].end());

        ans1=ans2=0;
        dfs(1);
        CASE(t);
        pf("%d\n", min(ans1,ans2));
        reset(n);
    }
    return 0;
}
