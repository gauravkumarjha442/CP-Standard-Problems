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
#define int         long long int


/*///////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////*/

template <typename T>    // we can use different datatypes but same function
T myMax(T x, T y)
{
   return (x > y)? x: y;
}

void solve()
{
     
  cout << myMax<int>(3, 7) << endl;  // Call myMax for int
  cout << myMax<double>(3.0, 7.034) << endl; // call myMax for double
  cout << myMax<char>('g', 'e') << endl;   // call myMax for char
     

     
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////*/


signed main()
{
    ios_base::sync_with_stdio(0); 
     cin.tie(0); cout.tie(0);

     #ifndef ONLINE_JUDGE
     freopen("input.txt" , "r" , stdin); freopen("output.txt" , "w" , stdout);
     #endif
       
    int t = 1;
    cin >> t;
  
    for(int t1=1;t1<=t;++t1){
        //cout << "Case #" << t1 << ": ";
        solve();
        //cout << '\n';
    }
  return 0;

}