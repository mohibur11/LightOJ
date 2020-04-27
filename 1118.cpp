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
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int T,t;
    db x1,x2,y1,y2,r1,r2,c1c2, base,mn,mxx,c1c2sq, theta, calc, areaofchap,areaoftri,ans1,ans2,main_ans;
    scin(T);
    RUN_CASE(t,T)
    {
        sc("%lf %lf %lf %lf %lf %lf",&x1, &y1, &r1, &x2, &y2, &r2);
        c1c2sq = ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        c1c2 = sqrt(c1c2sq);
        mn = min(r1,r2);
        mxx = max(r1,r2);
        if(c1c2 >r1+r2) main_ans = 0.0;
        else if(c1c2 + mn>mxx)
        {
            /// left side calculation
            calc = ((r1*r1) + c1c2sq - (r2*r2))/(2.0*r1*c1c2);
            theta = acos(calc);
            theta*=2;
            areaofchap = (theta * r1*r1)/2.0;
            areaoftri = 0.5 * r1 * r1 * sin(theta);
            ans1  = areaofchap - areaoftri;
            ///Right Side calculation
            calc = ((r2*r2) + c1c2sq - (r1*r1))/(2.0*r2*c1c2);
            theta = acos(calc);
            theta*=2;
            areaofchap = (theta * r2*r2)/2.0;
            areaoftri = 0.5 * r2 * r2 * sin(theta);
            ans2  = areaofchap - areaoftri;
            main_ans = ans1 + ans2;
        }
        else
        {
            main_ans = PI * mn * mn;
        }CASE(t);
        pf("%0.08f\n", main_ans);

    }
    return 0;
}
