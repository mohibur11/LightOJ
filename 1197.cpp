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

#define SIZE 10000007
vector<int> prime; /*Stores generated primes*/
char sieve[SIZE]; /*0 means prime*/
void primeSieve ( int n )                /// O(sqrt(N)/ln(sqrt(N))
{
    sieve[0] = sieve[1] = 1; /*0 and 1 are not prime*/ /// for 10000007 it is O(395)

    prime.push_back(2); /*Only Even Prime*/
    for ( int i = 4; i <= n; i += 2 )
        sieve[i] = 1; /*Remove multiples of 2*/

    int sqrtn = sqrt ( n );
    for ( int i = 3; i <= sqrtn; i += 2 )
    {
        if ( sieve[i] == 0 )
        {
            for ( int j = i * i; j <= n; j += 2 * i )
                sieve[j] = 1;
        }
    }

    for ( int i = 3; i <= n; i += 2 )
        if ( sieve[i] == 0 )
            prime.push_back(i);
}



// Returns number of primes between segment [a,b]
int segmentedSieve ( ll  a, ll  b ) {
    bool arr[b-a+3];
    if ( a == 1 ) a++;

    int sqrtn = sqrt ( b );

    memset ( arr, 0ll, sizeof (arr) ); // Make all index of arr 0.

    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        int p = prime[i];
        ll j = p * p;

        // If j is smaller than a, then shift it inside of segment [a,b]
        if ( j < a ) j = ( ( a + p - 1 ) / p ) * p;

        for ( ; j <= b; j += p ) {
            arr[j-a] = 1; // mark them as not prime
        }
    }

    int res = 0;
    for ( ll i = a; i <= b; i++ ) {
        // If it is not marked, then it is a prime
        if ( arr[i-a] == 0 ) res++;
    }
    return res;
}
int main()
{
    primeSieve(SIZE);
    ll a,b;
    int t,T;
    scin(T);
    RUN_CASE(t,T)
    {
        scln(a);
        scln(b);
        CASE(t);
        pf("%d\n", segmentedSieve(a,b));
    }
    return 0;
}


