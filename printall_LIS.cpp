#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> dp ,vector<int> arr , int n)
{
      queue < pair< pair< vector<int > , int> , pair<int ,int> > > q;

      vector <int> vec;

      vec.push_back(arr[n-1]);

      q.push(make_pair( make_pair(vec , n-1) , make_pair(dp[n-1],arr[n-1])));

      pair < pair<vector<int> , int > , pair<int , int>> pai;

     while(!q.empty())
     {
         pai = q.front();
         q.pop();

         vector <int> res = pai.first.first;
         int idx = pai.first.second;
         int dp1 = pai.second.first;
         int arr1 = pai.second.second;
        

         for(int i = idx-1; i>=0;i--)
               {  
                     if( (dp1==dp[i]+1) && arr1>arr[i])
                      { 
                            res.push_back(arr[i]);

                          q.push(make_pair( make_pair( res , i) , make_pair(dp[i],arr[i])));

                            res.pop_back();
                      }

               }

               if(dp1==1)
                  {   
                      reverse(res.begin(),res.end());

                        string s = "";

                     for(int i=0;i<res.size();i++)
                        {  
                           if(i<res.size()-1)
                            s += to_string(res[i]) + " -> ";
                           
                           else
                             s += to_string(res[i]);

                        }
                            

                      cout <<s<<"\n";
                  }



     }
    
}

void solve()
{
     int n;
     cin >>n;

     vector <int> arr(n,0);
     vector <int> dp(n,0);

     for(int i=0;i<n;i++)
     {
         int x;
         cin >>x;

         arr[i] = x;
     }

    dp[0] =1;
    int maxele = 0;
    int maxsum =0;
    int idx;

    for(int i=0;i<n;i++)
    {
         maxele = 0;
         for(int j=0;j<i;j++)
         {
            if(arr[i] > arr[j])
              maxele = max(maxele,dp[j]);
         }

         dp[i] = maxele + 1;

         if(dp[i]>maxsum)
         {
            maxsum = dp[i];
            idx = i;
         }
    }
    

   cout <<maxsum<<"\n";

  for(int i=0;i<n;i++)
       if(dp[i]==maxsum)
         bfs(dp,arr,i+1);


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