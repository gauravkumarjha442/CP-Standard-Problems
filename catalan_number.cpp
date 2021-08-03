#include<bits/stdc++.h>
using namespace std;


void solve() {


    int n;
    cin >>n;

    n = n - 2;

    vector<int> dp(n+1,0);

    dp[0]= 1;
    dp[1] =1;

    for(int i=2;i<=n;i++)
    {
        int l = 0;
        int r = i-1;

        while(l<=i-1)
        {
             dp[i] += dp[l]*dp[r]; 
          l++;
          r--;
        }

    }
  cout<<dp[n];


}


int main()
{    
        #ifndef ONLINE_JUDGE
      freopen("input.txt" , "r" , stdin);
      freopen("output.txt" , "w" , stdout);
      #endif

       solve();


    return 0;
}