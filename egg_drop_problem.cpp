#include<bits/stdc++.h>
using namespace std;






    int eggdrop(int n, int k) 
{
    // your code here
    
    vector<vector<int> >dp(n+1,vector<int>(k+1,0));
    
   // n eggs  i
   // k floors   j
    
   
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(i==0 || j==0)
              dp[i][j] = 0;
              
            else if(i==1)
            {
                dp[i][j] = j;
            }
            
            else if(j==1)
            {
                dp[i][j] = 1;
            }
            
            else
            {
                int j_s = 0;
                int j_e = j-1;
                
                int min1 = INT_MAX;
                int max1;
                
                while(j_s<j)
                {
                    max1 = max(dp[i-1][j_s] , dp[i][j_e]);
                    
                   if(min1==INT_MAX)
                      min1 = max1;

                    min1 = min(min1 , max1);


                    
                    j_s++;
                    j_e--;
                }
                
                dp[i][j] = min1+1;
            }
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
             cout<<dp[i][j]<<" ";
        }

        cout<<endl;
    }
     
     return dp[n][k];
    
}

int main()
{    
        #ifndef ONLINE_JUDGE
      freopen("input.txt" , "r" , stdin);
      freopen("output.txt" , "w" , stdout);
      #endif

     int n,k;
     cin >>n>>k;

     int ans = eggdrop(n,k);

     cout<<ans<<"\n";

    return 0;
}