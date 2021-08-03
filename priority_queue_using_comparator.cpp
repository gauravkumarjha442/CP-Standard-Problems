#include<bits/stdc++.h>
using namespace std;

//#define int long long
//pair<int , int>p , pair<int , int>q
struct cmd
{
    bool operator()(pair<int ,int> a , pair<int ,int> b)
    {
        return a.second<b.second;
    }
};

void solve(){
        
         priority_queue <pair<int ,int> , vector<pair<int ,int>> , cmd> pq;

         pq.push(make_pair(2,4));
         pq.push(make_pair(3,3));
         pq.push(make_pair(1,0));
         pq.push(make_pair(4,6));
         
      while(!pq.empty())
         {  
              cout<<"("<<pq.top().first<<","<<pq.top().second<<")"<<" ";

           pq.pop();

         }
      
 }



signed main(){
   ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

      #ifndef ONLINE_JUDGE
      freopen("input.txt" , "r" , stdin);
      freopen("output.txt" , "w" , stdout);
      #endif

  int t=1,p;
  cin>>t;

  p = t;
  t=1;

  while(p--) 
     {
       // cout<<"Case #"<<t<<": "; 
        solve();
         t++;
     }

  return 0;
}