#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequences(string s) {

        int n = s.size();

        long long mod = 1000000007;

        vector <vector<int>> dp(n,vector<int>(n,0));
   
       map <char , int> mp;
   
     vector<int> next(n,0);
     vector<int> prev(n,0);

     for(int i=0;i<n;i++)
     {
         if(mp[s[i]]==0)
            prev[i] = -1;

         else if(mp[s[i]]==2000)
             prev[i] = 0;

        else
            prev[i] = mp[s[i]];
        
          mp[s[i]] = i;

         if(i==0)
           mp[s[i]] = 2000;

         
     }

     map <char , int> mp1;

     for(int i=n-1;i>=0;i--)
     {
         if(mp1[s[i]]==0)
            next[i] = -1;

        else
            next[i] = mp1[s[i]];
        
          mp1[s[i]] = i;

         
     }

    
    for(int g=0;g<n;g++)
    {
         for(int i=0,j=g;j<n;i++,j++)
         {
               if(g==0)
                {
                    dp[i][j] = 1;
                }

              else if(g==1)
              {
                    dp[i][j] = 2;
              }

              else
              {
                    if(s[i]!=s[j])
                    {
                        dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
                    }

                    else
                    {
                         if(next[i]==j && prev[j]==i)
                           dp[i][j] = 2*dp[i+1][j-1] + 2;

                         else if(next[i]==prev[j])
                         {
                            dp[i][j] = 2*dp[i+1][j-1] + 1;
                         }

                         else
                            {
                               dp[i][j] = 2*dp[i+1][j-1] - dp[next[i]+1][prev[j]-1];
                            }
                    }
              }
         }
    }

    
    
  return dp[0][n-1];
        
    
    }
};


int main()
{    
        #ifndef ONLINE_JUDGE
      freopen("input.txt" , "r" , stdin);
      freopen("output.txt" , "w" , stdout);
      #endif

     string s;
     cin >>s;

     Solution obj;

     int ans = obj.countPalindromicSubsequences(s);

     cout<<ans<<"\n";
    
    return 0;
}