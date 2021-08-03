#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
struct cmd
{
    bool operator()(pair<int ,int> a , pair<int ,int> b)
    {
        return a.second>b.second;
    }
};

bool cmd1(pair<int , int>p , pair<int , int>q)
       { return p.second<q.second;} 


priority_queue <pair<int , int> ,vector<pair<int , int>> , cmd> pq;

class Solution{
  public:
  /*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */

    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // Code here
        
        
        vector <pair<int , int>> ans;
        vector <int> ans1(V,0);
        
        vector <bool> vi(V,false);
        
        pq.push(make_pair(S,0));
        
        pair <int ,int> pai;
        
        while(!pq.empty())
         {
             pai = pq.top();
             pq.pop();
             
             if(vi[pai.first])
               {
                   continue;
               }
               
               vi[pai.first] = true;
               ans.push_back( {pai.second , pai.first});
             
             for(auto m : adj[pai.first])
               {
                      if(!vi[m[0]])
                       pq.push(make_pair(m[0] , pai.second + m[1]));
                      
               }
               
               
             
         }

         sort(ans.begin(),ans.end(),cmd1);

         for(int i=0;i<V;i++)
         {
             ans1[i] = ans[i].first;
         }
        return ans1;
    }
    
    
};




// { Driver Code Starts.


int main()
{
    

      #ifndef ONLINE_JUDGE
      freopen("input.txt" , "r" , stdin);
      freopen("output.txt" , "w" , stdout);
      #endif

    
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
      vector<int> res = obj.dijkstra(V, adj, S);
      
      for(int i=0; i<V; i++)
          cout<<res[i]<<" ";
      cout<<endl;
    

    return 0;
}