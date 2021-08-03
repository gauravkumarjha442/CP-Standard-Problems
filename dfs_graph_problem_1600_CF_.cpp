#include <bits/stdc++.h>

const long long SZ = 1e5 + 7;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
const long long MOD = 998244353;
long long opnmbr = 1;

#define ll                  long long
#define int                 long long int
#define ld                  long double

#define pll                 pair<ll, ll>
#define vi                  vector<ll>
#define mi                  map<ll, ll>
#define umi                 unordered_map<ll, ll>

#define sz(x)               (ll)x.size()
#define endl                "\n"

#define pb                  push_back
#define F                   first
#define S                   second
#define mp(x,y)             make_pair(x,y)
#define all(a)              a.begin(),a.end()
#define rall(a)             a.rbegin(),a.rend()
#define rev(a)              reverse(all(a))
#define unq(a)              a.erase(std::unique(all(a)),a.end());

#define max(a,b)            ((a > b) ? a : b)
#define min(a,b)            ((a < b) ? a : b)

#define ci(X)               ll X; cin>>X
#define cii(X, Y)           ll X, Y; cin>>X>>Y
#define ciii(X, Y, Z)       ll X, Y, Z; cin>>X>>Y>>Z
#define ciiii(W, X, Y, Z)   ll W, X, Y, Z; cin>>W>>X>>Y>>Z

#define dbg(x)              cout<<#x<<"="<<(x)<<endl;
#define dbg2(x,y)           cout<<#x<<"="<<(x)<<" "<<#y<<"="<<(y)<<endl;
#define dbg3(x,y,z)         cout<<#x<<"="<<(x)<<" "<<#y<<"="<<(y)<<" "<<#z<<"="<<(z)<<endl;
#define dbg4(x,y,z,w)       cout<<#x<<"="<<(x)<<" "<<#y<<"="<<(y)<<" "<<#z<<"="<<(z)<<" "<<#w<<"="<<(w)<<endl;

#define kick()               cout<<"Case #"<<opnmbr++<<": ";
#define start_karo           ll ___t; cin>>___t; while (___t--)
#define chalo_achha_hai      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define kardia               solve();

#define fr(i,a,b)           for(ll i=a;i<b;i++)
#define rf(i,a,b)           for(ll i=a;i>=b;i--)

#define mem0(X)             memset((X), 0, sizeof((X)))
#define mem1(X)             memset((X), -1, sizeof((X)))
#define setbits(x)          __builtin_popcountll(x)

#define yes()      cout<<"YES"<<endl
#define no()       cout<<"NO"<<endl
#define err()      cout<<"===========\n";
#define errA(A)    for(auto i:A) cout<<i<<" ";cout<<"\n";
#define err1(a)    cout<<#a<<" "<<a<<"\n"
#define err2(a,b)  cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<"\n"

using namespace std;

ll powermod(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1) ans = (ans * a) % MOD;
        b = b / 2;
        a = (a * a) % MOD;
    }
    return ans;
}

/* GCD and LCM of two numbers */

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

/* Prime Numbers Sieve Method */

const long long nod = 1000000;
vector<char> is_prime(nod+1, true);

vector<int> prime;

void sieve(){

is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= nod; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= nod; j += i)
            is_prime[j] = false;
                     }
              }

     for(int i=0;i<=nod;i++)
     {
         if(is_prime[i])
           prime.push_back(i);

     }

 }

/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/*..................................................................................................................................................................................................*/
/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
const int N = 200005;
vector<int> adj[N]; 
int dp[N], lev[N];
int mark[N]; 
int ans; 

void dfs(int node, int par = -1, int level = 0) 
{
  lev[node] = level; 
  int cnt = 0; 
 
  for(auto it : adj[node])
  {
    if(it==par) continue;
    dfs(it, node, level+1); 
    cnt += dp[it]; 
  }
 
  dp[node] += (1+cnt); 
  
}


void solve(){
int n,k;
  cin >> n >> k; 
  fr(i,0,n-1)
  {
    int u,v;
    cin >> u >> v;
    adj[u].pb(v); 
    adj[v].pb(u);
  }
 
  dfs(1);
 
  vector< int > dist; 
  fr(i,1,n+1) dist.push_back(lev[i] - (dp[i]-1));
 
  //fr(i,1 ,n+1) cout << i << " " << lev[i] - (dp[i]-1) << endl;
  sort(all(dist));
  reverse(all(dist)); 
  fr(i,0,k) ans += dist[i];  
  cout <<ans; 

          }
      

signed main()
{

  chalo_achha_hai

     #ifndef ONLINE_JUDGE
     freopen("input.txt" , "r" , stdin); freopen("output.txt" , "w" , stdout);
     #endif

     //sieve();
    /*  start_karo
       {
           // kick()
            kardia
       }*/
     kardia
  return 0;
}