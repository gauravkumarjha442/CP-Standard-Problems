#include<bits/stdc++.h>
using namespace std;


void bfs(vector<vector <int> >dp ,int n , int m)
{
      pair <string , pair<int , int> > pai;
      queue < pair<string , pair<int , int> > > q;

      q.push(make_pair("",make_pair(0,0)));


      while(!q.empty())
      {
          pai = q.front();
          q.pop();

          int i = pai.second.first;
          int j = pai.second.second;
          string s = pai.first;


          if(i==n-1 && j==m-1) 
          {
                cout<<s<<"\n";
          }

          else if(i==n-1)
          {
                 q.push(make_pair(s + 'H' , make_pair(i,j+1)));
          }

          else if(j==m-1)
          {
                    q.push(make_pair(s + 'V' , make_pair(i+1,j)));
          }

          else
          {
                 if(dp[i+1][j]>dp[i][j+1])
                 {
                        q.push(make_pair(s + 'H' , make_pair(i,j+1)));
                 }

                 else if(dp[i+1][j]<dp[i][j+1])
                 {
                        q.push(make_pair(s + 'V' , make_pair(i+1,j)));
                 }

                 else
                 {
                      q.push(make_pair(s + 'V' , make_pair(i+1,j)));
                      q.push(make_pair(s + 'H' , make_pair(i,j+1)));
                 }
          }
      }



}

/*
    OUTPUT :--
23
23 23 24 20 21 19 
24 22 23 18 13 17 
20 19 17 13 13 13 
21 19 19 12 9 7 
23 20 19 16 7 5 
23 21 14 14 6 1 

*/

void solve()
{
    int n,m;
    cin >>n>>m;

    int arr[n][m];
   // int dp[n][m];

    vector < vector <int> > dp(n,vector<int>(m,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
             cin >>arr[i][j];
        }
    }

    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(j==m-1 && i==n-1)
                dp[i][j] = arr[i][j];

            else if(j==m-1)
                  dp[i][j] = dp[i+1][j] + arr[i][j];

            else if(i==n-1)
                   dp[i][j] = dp[i][j+1] + arr[i][j];

            else
                dp[i][j] = min(dp[i][j+1] , dp[i+1][j]) + arr[i][j];

        }
    }

     cout <<dp[0][0]<<endl;

     bfs(dp,n,m);
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