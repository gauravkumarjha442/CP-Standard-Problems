#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(string s, string p) {
        
            int n = p.size();
            int m = s.size();
        
        vector<vector<pair<bool , bool>>> dp(n+1,vector<pair<bool , bool>>(m+1,make_pair(false,false)));
        
        
          for(int i=n;i>=0;i--)
          {
             for(int j=m;j>=0;j--)
              {
                   if(i==n && j==m)
                   { dp[i][j] = make_pair(true,true);
                   }
                 
                   else if(i==n && j!=m)
                   {
                       dp[i][j] = make_pair(false,true);
                   }
                 
                   else if(i!=n && j==m)
                   {
                       if(p[i]=='*')
                           dp[i][j] = dp[i+1][j];
                       
                       else
                       dp[i][j] = make_pair(false,false);
                   }
                 
                   else
                   {
                       if(p[i]=='?')
                       {
                           if(dp[i+1][j+1].first)
                               dp[i][j] = make_pair(true,true);
                           else
                               dp[i][j] = make_pair(false,false);
                       }
                       
                       else if(p[i]=='*')
                       {
                           if(dp[i+1][j].second)
                               dp[i][j] = make_pair(true,true);
                           
                           else
                               dp[i][j] = make_pair(false,false);
                       }
                       
                       else
                       {
                           if(p[i]==s[j])
                           {
                               if(dp[i+1][j+1].first)
                               {
                                   dp[i][j] = make_pair(true,true);
                               }
                               else
                                  dp[i][j] = make_pair(false,false); 
                           }
                           else
                           {
                               dp[i][j] = make_pair(false,false);
                           }
                       }
                           
                   }
                 
                 
                    if(j!=m && dp[i][j+1].second)
                       dp[i][j].second = true;
              }
          }
        
     
        if(dp[0][0].first)
            cout<<"true"<<"\n";

        else
           cout<<"false"<<"\n";
    }
};


int main()
{    
        #ifndef ONLINE_JUDGE
      freopen("input.txt" , "r" , stdin);
      freopen("output.txt" , "w" , stdout);
      #endif

      string s,p;
      cin >>s>>p;
                                    
     
    
     Solution obj;

     obj.solve(s,p);
    
    return 0;
}
