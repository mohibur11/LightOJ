/** find mid value of each point with other each point and if two point is the same there can be a Parallelogram **/

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
#define lcm(a, b)       (((a)/gcd(a,b))*b)
#define mx              1234567899
#define TC              int t;scin(t);while(t--)
#define PI              2*acos(0.0)
#define rep(i,a,b)      for( i=a; i<=b; i++)
#define rev(i,a,b)      for( i=a; i>=b; i--)
#define file            freopen("E:\\file.txt", "r", stdin);ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(x)          x.begin(),x.end()
#define DEBUG(args...)    do {   cerr << #args << ' ' ;  print(args); } while(0); cerr<< endl ;
using namespace std;
int get(int n,int p){int res = 0;while(n>=p) res+=n/p,n/=p;return res;}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
void VC(vector<ll> &v){for(int i=0;i<v.size();i++) printf("%lld ", v[i]);printf("\n");}

template< typename T > void print(const T& v) {    cerr << v << ' ' ;}
template< typename T1, typename... T2 >
void print( const T1& first, const T2&... rest ){
    print(first);
    print(rest...) ;
}
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

long long BigMod(long long int a, long long int b, int M) { long long remainder, answer = 1;remainder = a%M; while(b!=0){if(b%2==1) answer = (answer*remainder)%M;remainder = (remainder*remainder)%M;b/=2;}return answer;}
// A hash function used to hash a pair of any kind
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

struct node
{
    int midx, midy;
}M[1000005];
bool cmp(node &a, node &b)
{
    if(a.midx!=b.midx)
        return a.midx<b.midx;
    return a.midy<b.midy;
}

int a[1005],b[1005];
int main()
{
    int t,T, cnt, X,Y,x,y,n;
    ll ans,tmp;
    scin(T);
    RUN_CASE(t,T)
    {
        scin(n);
        for(int i=0;i<n;i++)
        {
            scin(a[i]);scin(b[i]);
        }
        cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                X = a[i]+a[j];Y = b[i] + b[j];
                M[cnt].midx = X;
                M[cnt++].midy = Y;
            }
        }ans = 0;
        sort(M,M+cnt, cmp);
        tmp = 1;
        for(int i=1;i<cnt;i++)
        {
            if(M[i].midx == M[i-1].midx && M[i].midy == M[i-1].midy)
            {
                tmp++;
            }
            else
            {
                ans+=(tmp*(tmp-1))/2;
                tmp = 1;
            }
        }
        CASE(t);pf("%lld\n", ans);
    }
    return 0;
}
