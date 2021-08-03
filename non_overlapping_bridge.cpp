#include <bits/stdc++.h>
using namespace std;

bool cmd(pair<int , int>a , pair<int ,int> b)
  {
       if(a.first==b.first)
          {
               return a.second < b.second;
          }

       return a.first < b.first ;
  }

int longestSubsequence(int n, int a[])
{
   
   vector <int> seq;
   
   seq.push_back(a[0]);
   
   for(int i=1;i<n;i++)
   {
       if(seq.back()<a[i])
         seq.push_back(a[i]);
         
        else
           {
               int ind = lower_bound(seq.begin(),seq.end(),a[i]) - seq.begin();
                seq[ind] = a[i];
           }
   }
   
   return seq.size();
   
}
 
void solve()
{
    int n;
    cin >>n;
 
    long long x1[n];
    long long x2[n];

    vector < pair<int , int> > arr;
 
    for(int i=0;i<n;i++)
          cin >>x1[i];
 
    for(int i=0;i<n;i++)
         cin >>x2[i];

     for(int i=0;i<n;i++)
     {
         arr.push_back(make_pair(x1[i],x2[i]));
     }

     sort(arr.begin(),arr.end(),cmd);

     int a[n];

     for(int i=0;i<n;i++)
        {
            a[i] = arr[i].second;
        }

    int ans = longestSubsequence(n,a);


    cout <<ans<<endl;
      



 
  /* long long maxele = 0;
   int maxb =1;
 
     long long dp[n];
 
     dp[0]=1;
 
     for(int i=1;i<n;i++)
     {
           maxele = 0;
 
           for(int j=0;j<i;j++)
           {
                if( (x1[i]>x1[j] && x2[i]>x2[j]) || (x1[i]<x1[j] && x2[i]<x2[j]) )
                    maxele = max(maxele , dp[j]);
           }
 
           dp[i] = maxele + 1;
 
           if(dp[i] > maxb )
             maxb = dp[i];
     }
 
 
     cout <<maxb<<endl;  
     }*/
 
 
}
 
int main() {
 
     
      #ifndef ONLINE_JUDGE
      freopen("input.txt" , "r" , stdin);
      freopen("output.txt" , "w" , stdout);
      #endif
 
      int t;
      cin >>t;
 
      while(t--)
      {
         solve();
      }
      
   return 0;
     
}