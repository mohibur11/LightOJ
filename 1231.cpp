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
#define MOD             100000007
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
#define rep(i,a,b)      for( i=a; i<=b; i++)
#define rev(i,a,b)      for( i=a; i>=b; i--)
#define file            freopen("E:\\file.txt", "r", stdin);ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(x)          x.begin(),x.end()
#define DEBUG(args...)    do {   cerr << #args << ' ' ;  print(args); } while(0); cerr<< endl ;
int get(int n,int p){int res = 0;while(n>=p) res+=n/p,n/=p;return res;}
using namespace std;

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

int main()
{
    int n,current_limit, ans;
    int coin[105];
    int t, T, k, limit[105],tmp,tmp1;
    scin(T);int combination[1005];
    RUN_CASE(t,T)
    {
        ms(coin,0);
        ms(limit,0);
        scin(n);
        scin(k);
        for(int i=0; i<n; i++) scin(coin[i]);
        for(int i=0; i<n; i++) scin(limit[i]);
        CASE(t);
        //int cnt[102]= {0};
		ms(combination,0);
        combination[0] = 1;
        for(int i=0; i<n; i++)
        {
            current_limit = limit[i];
            for(int j=k; j>=0; j--)
            {
                for(int x = 1;x<=current_limit;x++)
                {
                    if((j-x*coin[i])>=0) combination[j]+= combination[j-(x*coin[i])];
                }

            }
            for(int j=0;j<=k;j++) combination[j]%=MOD;
            //NL;
            //for(int x=0;x<=k;x++)pf("%lld ", combination[x]);NL;
        }

        //for(int x=1;x<=k;x++) if(combination[x])ans++;
        pf("%d\n",combination[k]);


    }
    return 0;
}
