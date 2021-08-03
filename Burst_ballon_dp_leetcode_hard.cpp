#include<bits/stdc++.h>
using namespace std;


 class Solution {
public:
    int maxCoins(vector<int>& arr) {
        
        int n = arr.size();

        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int g=0;g<n;g++)
        {
             for(int i=0 , j=g;j<n;i++,j++)
             {  
                   int max1 = INT_MIN;
                 
                           for(int k=i;k<=j;k++)
                           {
                               int left = k==i? 0 : dp[i][k-1];
                               int right = k==j ? 0 : dp[k+1][j];
                               int val = (i==0? 1 : arr[i-1])*arr[k]*(j==n-1? 1: arr[j+1]);

                                max1 = max(max1 , left + right + val);
                           }

                    dp[i][j] = max1;
             }
        }

         


    /*for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
       {
             cout <<dp[i][j]<<" ";
       }

       cout<<"\n";
    }*/









      return dp[0][n-1];
    }
};


int main()
{    
        #ifndef ONLINE_JUDGE
      freopen("input.txt" , "r" , stdin);
      freopen("output.txt" , "w" , stdout);
      #endif

     int n;
     cin >>n;
     vector <int>arr(n,0);

     for(int i=0;i<n;i++)
            {
                int x;
                cin >>x;

                arr[i] = x;
            }
    
     Solution obj;

     int ans = obj.maxCoins(arr);

     cout <<ans<<"\n";

    return 0;
}
