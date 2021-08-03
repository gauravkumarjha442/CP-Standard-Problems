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

// FOR policy based data structure (pbds)//
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>



void solve()
{
     
   ordered_set st;

   st.insert(5);
   st.insert(1);
   st.insert(3);
   st.insert(10);

   // { 1 , 3 , 5 , 10}

    cout<<*(st.find_by_order(2))<<endl;   // find element at index 2 it return 5//


    cout<<st.order_of_key(6);    // it return 3 which is  count of numbers , strictly less then 6 //
    cout<<endl;


    st.insert(6);
  
     // { 1 , 3 , 5 , 6 , 10}

    cout<<st.order_of_key(6);    // it return 3 which is  count of numbers , strictly less then 6 //
    cout<<endl;


    // These two functions are different from set //
    // All other functions are same as in set //

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