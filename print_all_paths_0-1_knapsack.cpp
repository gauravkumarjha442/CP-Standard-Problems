#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>dp, vector<pair<int , int>> arr , int n , int t)
{
        
     queue <pair<string , pair<int , int>>> q;

     q.push(make_pair("" , make_pair(n,t)));

     pair <string , pair<int , int>> pai;

     while(!q.empty())
     {
         pai = q.front();
         q.pop();

         string s = pai.first;
         int i = pai.second.first;
         int j = pai.second.second;

         if(j==0 || i==0)
           {
                cout<<s<<"\n";
           }

        else 
        {
                 if(j>=arr[i-1].first)
                   {
                        if( (arr[i-1].second + dp[i-1][j-arr[i-1].first] ) == dp[i][j])
                           {
                               q.push(make_pair(to_string(i-1)+" " + s , make_pair(i-1,j-arr[i-1].first)));
                           }

                        if(dp[i-1][j]==dp[i][j])
                           {
                               q.push(make_pair(s, make_pair(i-1,j)));
                           }
                   }

                else
                {
                    q.push(make_pair(s , make_pair(i-1,j)));
                }
        }


     }



}

void solve(){
     
           int n,t;
           cin >>n;

           int val[n];
           int wt[n];

          for(int i=0;i<n;i++)
                cin >>val[i];

          for(int i=0;i<n;i++)
                cin >>wt[i];
         
          cin >>t;

      vector <pair<int , int>> arr;

      for(int i=0;i<n;i++)
      {
         arr.push_back(make_pair(wt[i] , val[i]));
      }

      vector <vector<int> > dp(n+1 , vector<int>(t+1,0));

      for(int i=0;i<=n;i++)
      {
         for(int j=0;j<=t;j++)
         {
               if(i==0 || j==0)
               {
                  dp[i][j] = 0;
               }
               else
               {
                   if(j>=arr[i-1].first)
                   {
                        dp[i][j] = max(dp[i-1][j] , arr[i-1].second + dp[i-1][j-arr[i-1].first]);
                   }

                   else
                    { 
                         dp[i][j] = dp[i-1][j];
                    }
               }
         }
      }

       cout<<dp[n][t]<<"\n";

      bfs(dp,arr,n,t);

        
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


/*

INPUT :

5
15 14 10 45 30
2 5 1 3 4
7

OUTPUT :
75
3 4 


DP : 
0 0 0 0 0 0 0 0 
0 0 15 15 15 15 15 15 
0 0 15 15 15 15 15 29 
0 10 15 25 25 25 25 29 
0 10 15 45 55 60 70 70 
0 10 15 45 55 60 70 75 


*/