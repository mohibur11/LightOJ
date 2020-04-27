/** Bismillahir Rahmanir Rahim **/

#include<bits/stdc++.h>

#define sc              scanf
#define scin(x)         sc("%d",&(x))
#define scln(x)         sc("%lld",&(x))
#define pf              printf
#define NL              pf("\n")
#define ms(a,b)         memset(a,b,sizeof(a))
#define pb(a)           push_back(a)
#define mp              make_pair
#define sqr(x)          (x)*(x)
#define vi              vector< int >
#define RUN_CASE(t,T)   for(__typeof(t) t=1;t<=T;t++)
#define CASE(t)         printf("Case %d: ",t)
#define CASEL(t)        printf("Case %d:\n",t)

using namespace std;


#define MAX 105
int n, m, visited_zero[MAX], visited_one[MAX], ans, vertex, mode, node;
vi adj[MAX];
void bfs()
{
    visited_one[1] = 0;
    queue<pair<int,int > > Q;
    Q.push(mp(1, 0));
    while(!Q.empty())
    {
        vertex = Q.front().first;
        mode = Q.front().second;
        Q.pop();
        if(mode)
        {
            for(int i=0;i<adj[vertex].size();i++)
            {
                node = adj[vertex][i];
                if(visited_zero[node] == 0 )
                {
                    ans++;
                    visited_zero[node] = 1;
                    Q.push(mp(node, 0));
                }
            }
        }
        else
        {
            for(int i=0;i<adj[vertex].size();i++)
            {
                node = adj[vertex][i];
                if(visited_one[node] == 0)
                {
                    visited_one[node] = 1;
                    Q.push(mp(node, 1));
                }
            }
        }
    }
}
void reset()
{
    for(int i=0;i<=100;i++)
    {
        adj[i].clear();
        visited_one[i] = 0;
        visited_zero[i] = 0;
    }
    ans = 0;
}
int main()
{
    int t, T, u, v;
    scin(T);
    RUN_CASE(t,T)
    {
        scin(n);scin(m);
        for(int i=0;i<m;i++)
        {
            scin(u);scin(v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        bfs();
        CASE(t);
        pf("%d\n", ans);
        reset();
    }
    return 0;
}

