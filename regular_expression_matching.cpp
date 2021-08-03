#include<bits/stdc++.h>
using namespace std;

void solve()
{
     string s,p;
     cin >>s>>p;

  
     int n = p.size();
     int m = s.size();

     vector<vector<bool> > dp(n+1,vector<bool>(m+1,false));


     for(int i=0;i<=n;i++)
     {
        for(int j=0;j<=m;j++)
        {
            if(i==0 && j==0)
            {
                 dp[i][j] = true;
            }

            else if(i!=0 && j==0)
            {
                  if(p[i-1]=='*')
                  {
                      if(dp[i-2][j])
                        dp[i][j] = true;

                      else
                        dp[i][j] = false;
                  }

                  else
                    dp[i][j]=false;
            }

            else if(i==0 && j!=0)
            {
                dp[i][j] = false;
            }

            else
            {
                 if(p[i-1]=='.')
                 {
                     dp[i][j] = dp[i-1][j-1];
                 }

                 else if(p[i-1]=='*')
                 {
                        if(p[i-2]=='.')
                        {
                            if(dp[i][j-1])
                            {
                               dp[i][j] = true;
                            }

                            else if(dp[i-2][j])
                               dp[i][j] = true;


                            else
                               dp[i][j] = false;

                        }

                        else
                        {
                            if(dp[i-2][j])
                            {
                               dp[i][j] = true;
                            }

                            else if(dp[i][j-1] && p[i-2]==s[j-1])
                            {
                               dp[i][j] = true;
                            }

                            else
                              dp[i][j] = false;
                        }
                 }
                 else
                 {
                     if(p[i-1]==s[j-1])
                     {
                         dp[i][j] = dp[i-1][j-1];
                     }

                     else
                     {
                        dp[i][j] = false;
                     }
                 }
            }
        }
     }

     

     if(dp[n][m])
       cout<<"true"<<"\n";

     else
       cout<<"false"<<"\n";


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