/** Bismillahir Rahmanir Rahim **/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>

#define ll              long long int
#define ull             unsigned long long int
#define pii             pair < int, int>
#define pll             pair < ll, ll>
#define sc              scanf
#define scin2(x,y)      sc("%d %d",&(x), &(y));
#define scin3(x,y,z)    sc("%d %d %d",&(x), &(y), &(z));
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
#define rep(a,b)        for(int i=a; i<=b; i++)
#define rev(a,b)        for(int i=a; i>=b; i--)
#define srep(s)         for(int i=0; i<s.size(); i++)
#define file            freopen("E:\\file.txt", "r", stdin);
#define fast            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(x)          x.begin(),x.end()
#define rall(x)         x.rbegin(),x.rend()
#define yes             pf("YES\n")
#define no              pf("NO\n");
#define DEBUG(args...)    do {   cerr << #args << ' ' ;  print(args); } while(0); cerr<< endl ;
#define VIN(v)          for(auto &i:v)cin>>i;
#define VOUT(v)         for(auto i:v)cout<<i<<" ";NL;
#define prntArray(array, N) for(int i=1;i<=N;i++){printf("c", array[i], " \n"[i==N]);}
using namespace std;
int get(int n,int p){int res = 0;while(n>=p) res+=n/p,n/=p;return res;}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
// A hash function used to hash a pair of any kind /// used in unordered map /// example unordered_map<pair<int,int> , int , hash_pair> M;
struct hash_pair {template <class T1, class T2>size_t operator()(const pair<T1, T2>& p) const{auto hash1 = hash<T1>{}(p.first); auto hash2 = hash<T2>{}(p.second);return hash1 ^ hash2;}};
template< typename T > void print(const T& v) {    cerr << v << ' ' ;}
template< typename T1, typename... T2 >
void print( const T1& first, const T2&... rest ){
    print(first);
    print(rest...) ;
}
/***    Factorial[n] % M -> fact[n] ### inverse factorial [n] -> ifact[n] ###
        Bigmod( b , p) - > mod(b,p) ### inverse Mod(b, p ) -> inverse(b,p) ###
        nCr % M -> nCr(n , r)
*/
const int Maxn = 1e5 + 1;
template<typename T, typename T1> T mod(T x, T1 p){x %= p;if (x < 0)x += p;return x;}
// x must be relatively prime to p
int fact[Maxn];
void factorial(){fact[0] = 1;for(int i = 1; i < Maxn; i++){
    fact[i] = 1LL * fact[i - 1] * i % MOD;}}
// x must be relatively prime to p
int inv[Maxn], ifact[Maxn];
template<typename T>T inverse(T x, T p){x = mod(x, p);if (x == 1)return x;
    return mod((1LL * (-p / x) * (inv[p % x] % p)), p);
    // Since inverse of p % x is already calculated.
}
void inverse_fact(){ifact[0] = 1;for(int i = 1; i < Maxn; i++){
    inv[i] = inverse(i, MOD);ifact[i] = (1LL * ifact[i - 1] * inv[i]) % MOD;}
}
int nCr(int n, int r){int ret = (1LL * ifact[n - r] * ifact[r]) % MOD ;
    ret = (1LL * ret * fact[n]) % MOD;return ret;
}
/***END***/
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

bool cmp(int a,int b) ///false means swap
{
    return a>b;
}
vi digits;
ll dp[15][15][2];
int m;
ll call(int pos, int parent, bool flag)  /// flag is for first time  entry
{
    if(pos == m)
    {
        return 1;
    }
    if( dp[pos][parent][flag] != -1 ) return dp[pos][parent][flag];
    int LMT = digits.size()-1;
    ll res = 0ll;
    rep(0,LMT)
    {
        int n_flag = flag;
        if( abs(digits[i]-parent)>2 && n_flag)continue;
        if(flag == 0) n_flag = 1;
        res+=call(pos+1, digits[i], n_flag);
    }
    return dp[pos][parent][flag] = res;
}
int main()
{
    int t, T, n, x;
    scin(T);
    RUN_CASE(t,T)
    {
        scin2(n,m);
        digits.clear();
        rep(1,n)
        {
            scin(x);
            digits.pb(x);
        }
        ms(dp,-1);
        CASE(t);
        pf("%lld\n", call(0,digits[0],0));
    }
    return 0;
}
