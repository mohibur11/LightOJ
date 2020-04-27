/** Bismillahir Rahmanir Rahim **/

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

bool cmp(int a,int b)
{
    return a>b;
}
long long bigmod(long long int a, long long int b, int M) {

    long long remainder, answer = 1;
    remainder = a%M;
    while(b!=0)
    {
        if(b%2==1) answer = (answer*remainder)%M;

        remainder = (remainder*remainder)%M;
        b/=2;
    }
    return answer;
}
int main()
{
    int t,T, n;
    scin(T);
    ll product, m[50], a[50], M[50], Y[50], x;
    RUN_CASE(t,T)
    {
        scin(n);
        product = 1;x = 0ll;
        for(int i=0;i<n;i++)
        {
            scln(m[i]);scln(a[i]);
            product *= m[i];
        }
        for(int i=0;i<n;i++)
        {
            M[i] = product / m[i];
            Y[i] = bigmod(M[i],m[i]-2,m[i]);
        }
        for(int i=0;i<n;i++)
        {
            x+=(a[i]*M[i]*Y[i]);
        }
        CASE(t);
        pf("%lld\n", x%product);
    }
    return 0;
}
