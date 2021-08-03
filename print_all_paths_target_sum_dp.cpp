#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<bool>>dp, vector<int> arr , int n , int t)
{
        queue < pair<string , pair<int ,int>>> q;

        q.push(make_pair("",make_pair(n,t)));

         pair <string , pair<int , int>> pai;

        while(!q.empty())
        {
             pai = q.front();
             q.pop();

             string s = pai.first;
             int i = pai.second.first;
             int j = pai.second.second;

             if(j==0)
             {
                  cout<<s<<"\n";
             }

           /*  else if(i==0 && j!=0)
             {
                  q.push(make_pair(s,make_pair(i,j-1)));

                   
             }*/

             /*else if(i!=0 && j==0)
             {
                 
                 //q.push(make_pair(s,make_pair(i-1,j)));
                   cout<<s<<"\n";
                  
             }*/

             else
             {
                  if(dp[i-1][j])
                  {
                     q.push(make_pair(s,make_pair(i-1,j)));
                  }

                  if(j>=arr[i-1] && dp[i-1][j-arr[i-1]])
                  {
                    q.push(make_pair(to_string(i-1)+ " " + s, make_pair(i-1,j-arr[i-1])));
                  }
             }
        }
}

void solve(){
     

        int n,t;
        cin>>n;

        vector<int> arr(n,0);

        for(int i=0;i<n;i++)
        {
             int x;
             cin >>x;

             arr[i] = x;
        }

        cin >>t;

        vector< vector<bool> > dp(n+1,vector<bool>(t+1,false));

        for(int i=0;i<=n;i++)
        {
              for(int j=0;j<=t;j++)
              {
                  if(i==0 && j==0)
                  {
                        dp[i][j] = true;
                  }

                  else if(i==0 && j!=0)
                  {
                       dp[i][j] = false;
                  }

                  else if(i!=0 && j==0)
                  {
                       dp[i][j] = true;
                  }

                  else
                  {
                         if(dp[i-1][j]==true)
                         {
                            dp[i][j] = true;
                         }

                         else if(j>=arr[i-1] && dp[i-1][j-arr[i-1]]==true)
                         {
                            dp[i][j] = true;
                         }

                         else
                           {
                             dp[i][j] = false;
                           }


                  }
              }
        }
          
          if(dp[n][t])
            cout<<"true"<<"\n";
         else 
            {cout<<"false"<<"\n";
                return;
            }
   
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
4
2
7
1
3
10

OUTPUT :

true
2 4 
1 2 3 
0 1 3 4 







*/