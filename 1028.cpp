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

/***Time Complexity

O(√N/ln(√N)+log2(N)

*/

#define SIZE 10000007
vector<int> prime; /*Stores generated primes*/
char sieve[SIZE]; /*0 means prime*/
void primeSieve ( int n ) {              /// O(sqrt(N)/ln(sqrt(N))
    sieve[0] = sieve[1] = 1; /*0 and 1 are not prime*/

    prime.push_back(2); /*Only Even Prime*/
    for ( int i = 4; i <= n; i += 2 ) sieve[i] = 1; /*Remove multiples of 2*/

    int sqrtn = sqrt ( n );
    for ( int i = 3; i <= sqrtn; i += 2 ) {
        if ( sieve[i] == 0 ) {
            for ( int j = i * i; j <= n; j += 2 * i ) sieve[j] = 1;
        }
    }

    for ( int i = 3; i <= n; i += 2 ) if ( sieve[i] == 0 ) prime.push_back(i);
}

ll factorize( ll n ) {         /// O(lof2(N))
    ll sqrtn = sqrt ( n );
    ll tmp = 1ll,divisors = 1ll;
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
    //if ( sieve[n] == 0 ) break; ///*Checks if n is prime or not*/
        if ( n % prime[i] == 0 ) {
                tmp = 1ll;
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
                tmp++;
            }
            divisors *=tmp;
            sqrtn = sqrt ( n );
        }
    }
    if ( n != 1ll ) {
        divisors*=2ll;
    }
    return divisors;
}
int main()
{
    primeSieve(SIZE);
    int t,T;
    scin(T);
    ll n;
    RUN_CASE(t,T)
    {
        scln(n);
        CASE(t);
        pf("%lld\n", factorize(n)-1ll);
    }
	return 0;
}



