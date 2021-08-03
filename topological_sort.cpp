#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
  vector<int> topoSort(int v, vector<int> adj[]) {
     
      vector<int> ans;
      vector<bool> vi(v,false);
      
      stack <int> st;
      
      
   for (int i = 0; i < v; i++)
        if (vi[i] == false)
             dfs(adj,st,vi,i);
      
      while(!st.empty())
      {
           ans.push_back(st.top());
           
           st.pop();
      }
      
      return ans;
      
      
  }
  
  
  void dfs(vector<int>adj[] ,stack <int>st, vector<bool>vi , int v)
  {
       
     vi[v] = true;
         
      for(auto z : adj[v]){
         if(!vi[z])
         {
             dfs(adj,st,vi,z);
         }
         
      }
         
         st.push(v);
       
  }
  
  
  
};

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {


      #ifndef ONLINE_JUDGE
      freopen("input.txt" , "r" , stdin);
      freopen("output.txt" , "w" , stdout);
      #endif

    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}