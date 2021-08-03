#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

unsigned mod_pow(unsigned a, unsigned b, unsigned mod) {
    unsigned result = 1;
 
    while (b > 0) {
        if (b & 1)
            result = unsigned(uint64_t(result) * a % mod);
 
        a = unsigned(uint64_t(a) * a % mod);
        b >>= 1;
    }
 
    return result;
}
 
bool miller_rabin(unsigned n) {
    if (n < 2)
        return false;
 
    // Check small primes.
    for (unsigned p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
        if (n % p == 0)
            return n == p;
 
    int r = __builtin_ctz(n - 1);
    unsigned d = (n - 1) >> r;
 
    // https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Testing_against_small_sets_of_bases
    for (unsigned a : {2, 7, 61}) {
        unsigned x = mod_pow(a % n, d, n);
 
        if (x <= 1 || x == n - 1)
            continue;
 
        for (int i = 0; i < r - 1 && x != n - 1; i++)
            x = unsigned(uint64_t(x) * x % n);
 
        if (x != n - 1)
            return false;
    }
 
    return true;
}

void solve()
{
     
   
   if(miller_rabin(1e9+7))
   {
       cout<<"prime number"<<endl;
   }
    


}


int main()
{
    ios_base::sync_with_stdio(0); 
     cin.tie(0); cout.tie(0);

     #ifndef ONLINE_JUDGE
     freopen("input.txt" , "r" , stdin); freopen("output.txt" , "w" , stdout);
     #endif
    int t = 1;; 
     cin>>t;
    for (int t1=0;t1<t;t1++)
    {
        solve();
    }

    return 0;

}