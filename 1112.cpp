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
#define rep(i,a,b)      for(__typeof(i) i=a; i<=b; i++)
#define rev(i,a,b)      for(__typeof(i) i=a; i>=b; i--)


using namespace std;

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

long long BigMod(long long int a, long long int b, int M) { /// a function to determine a^b(mod M)
    long long remainder, answer = 1;                            /// set two variables for remainder and answer
    remainder = a%M;                                         /// setting remainder as
    while(b!=0)                                                     ///  loop occurs until b is not equal to 0
    {
        if(b%2==1) answer = (answer*remainder)%M;                  /// checking if b is odd
                /// taking the present remainder in the answer if b is odd
        remainder = (remainder*remainder)%M;    /// making remainder double on each turn of the loop
        b/=2;                                  /// reducing b by dividing it by 2 in every turn,
    }
    return answer;
}
bool cmp(int a,int b)
{
    return a>b;
}
int tree[100005],a[100005], n;
void less_update(int pos)
{
    int tmp = a[pos];
    a[pos] = 0;
    while(pos<=n)
    {
        tree[pos] -=tmp;
        pos = pos + (pos & -pos);
    }
}
void loop_update(int pos, int money)
{
    while(pos<=n)
    {
        tree[pos] +=money;
        pos = pos + (pos & -pos);
    }
}
void update(int pos, int money)
{
    a[pos]+=money;
    while(pos<=n)
    {
        tree[pos] +=money;
        pos = pos + (pos & -pos);
    }
}
int query(int pos)
{
    int res = 0;
    while(pos>0)
    {
        res+=tree[pos];
        pos-=(pos & -pos);
    }
    return res;
}
int main()
{
    int t, caseno=1, q, num ,x, y;
    scin(t);
    while(t--)
    {
        scin(n);scin(q);
        for(int i=1;i<=n;i++)
            {scin(a[i]);
            loop_update(i, a[i]);
        }
        //for(int i=0;i<=n;i++) pf("%5d", a[i]);
        pf("Case %d:\n",caseno++);
        while(q--)
        {
            scin(num);
            if(num==1)
            {
                scin(x);
                pf("%d\n", a[x+1]);
                less_update(x+1);
            }
            else if(num == 2)
            {
                scin(x);scin(y);
                update(x+1,y);
            }
            else if(num == 3)
            {
                scin(x);scin(y);
                int ans = query(y+1) - query(x);
                pf("%d\n", ans);
            }
        }ms(tree,0);
    }
    return 0;
}

