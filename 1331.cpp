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
    int t,T;
    cin >> T;
    db r1,r2,r3, ans,A,B,C,s,a,b,c,COSA,COSB,COSC,AoA,AoB,AoC,area;
    RUN_CASE(t,T)
    {
        sc("%lf %lf %lf", &r1,&r2,&r3);
        a = r1+r2;
        b = r1+r3;
        c = r3+r2;
        pf("Hello world\n");
        s = (a+b+c)/2.0;
        area = sqrt(s*(s-a)*(s-b)*(s-c));

        COSA = (c*c+b*b - a*a)/(2*b*c);
        COSB = (a*a+c*c - b*b)/(2*a*c);
        COSC = (a*a+b*b - c*c)/(2*a*b);

        A = acos(COSA);
        B = acos(COSB);
        C = acos(COSC);

        AoA = (A*r3*r3)/2.0;
        AoB = (B*r2*r2)/2.0;
        AoC = (C*r1*r1)/2.0;

        ans = area - (AoA+AoB+AoC);
        CASE(t);
        pf("%0.8f\n", ans);
    }
    return 0;
}

