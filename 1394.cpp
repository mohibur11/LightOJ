/** Bismillahir Rahmanir Rahim **/
/*** Hard DigitDP
Approach : here main problem is sum of all valid number cause the number can be large
here tricks is adding sum by ith digit value
***/
///#pragma GCC optimize("Ofast")
///#pragma GCC target("avx,avx2,fma")

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
int  Maxone, Idealnumber, k, binary_size;
vi nums,ideal_nums;
pll dp[33][33][33][22][2];
ll PowofTwo[34]; /// this is for pre calculation of all digit binary value
/***

we need pair for store two values
pair ->first   = for count how many number satisfy this condition
pair ->second  = for store summation of numbers

pos = current digit position
cnt_one = currently how many ones counted
cnt_ideal = currently how many mismatch counted with ideal number
number = main digit in decimal form % 21(cause 3 * 7)
flag = for limit
***/
pll call(int pos, int cnt_one,int cnt_ideal,ll number, bool flag)
{
    if(cnt_one > Maxone || cnt_ideal > k)  /// check for ones and mismatch limit
    {
        return mp(0,0);
    }

    if(pos == nums.size())
    {
        pll res = pll(0,0);
        if(number>0 && number%3==0) res.first++;
        return res;
    }
    if( dp[pos][cnt_one][cnt_ideal][number][flag].first != -1 ) return dp[pos][cnt_one][cnt_ideal][number][flag];

    int LMT = 1;
    if(flag == 0) LMT = nums[pos];

    pll res = pll(0,0);
    pll tmp;
    for(int dgt = 0;dgt<=LMT; dgt++)
    {
        bool n_flag = flag;
        int n_cnt_one = cnt_one;
        int n_cnt_ideal = cnt_ideal;
        ll n_number = number;

        if(flag == 0 && dgt<LMT ) n_flag = 1;
        if(dgt)
        {
            n_number = (n_number + PowofTwo[ binary_size - pos -1]); /// convert binary to decimal
            n_cnt_one++;                                            ///if dgt is 1 then one 1 found and add it;
        }
        if(dgt != ideal_nums[binary_size - pos -1]) n_cnt_ideal++;

        tmp = call(pos+1,n_cnt_one, n_cnt_ideal, n_number%21, n_flag);
        /// tmp is current pair values after recursion return
        res.first+=tmp.first;
        res.second+=tmp.second;
        if(dgt)
        {
            /// till now how many valid number found multiply with their corresponding digit value
            res.second+= tmp.first*PowofTwo[binary_size - pos -1];
        }
    }

    return dp[pos][cnt_one][cnt_ideal][number][flag] = res;
}
void init()
{
    for(int i=0;i<33;i++)
    for(int j=0;j<33;j++)
    for(int k=0;k<33;k++)
    for(int x=0;x<22;x++)
    for(int y=0;y<2;y++)
        dp[i][j][k][x][y] = mp(-1,0);
}
pll solve(int n)
{
    nums.clear();
    while(n)
    {
        nums.pb(n%2);
        n/=2;
    }
    reverse(all(nums));
    binary_size = nums.size();

    init();
    /// find how many mismatch found without any compare
    int mismatchh = 0;
    for(int i = 32;i>=binary_size;i--) mismatchh+=ideal_nums[i];
    return call(0,0,mismatchh,0,0);
}
int main()
{
    PowofTwo[0] = 1;
    for(int i=1;i<32;i++)
    {
        PowofTwo[i] = (PowofTwo[i-1] * 2);
    }

    int t,T, Start, End;
    scin(T);
    RUN_CASE(t, T)
    {
        scin3(Start, End, Maxone);scin2(Idealnumber, k);
        ideal_nums.clear();
        while(Idealnumber)
        {
            ideal_nums.pb(Idealnumber%2);
            Idealnumber/=2;
        }
        while(ideal_nums.size()<33)ideal_nums.pb(0);/// add leading zeros into remaing bit upto 32 bit

        pll ans1,ans2 = pll(0,0);
        ans1 = solve(End);
        if(Start)ans2 = (solve(Start -1));
        CASE(t);
        pf("%lld\n", ans1.ss - ans2.ss);
    }
    return 0;
}
