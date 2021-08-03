#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends




class Solution {
public:
	bool isCyclic(int V, vector<int> adj[]) {
	   	// code here
	   	
	   	vector <int> vi(V,0);
	   	vector <int> recst(V,0);
	   	
	   	
	    for(int i=0;i<V;i++)
	           if(dfs(i,vi,recst,adj))
	               return true;
	    
	    return false;
	    
	}
	
	
	bool dfs(int v,vector<int>&vi ,vector<int>&recst,vector<int> adj[])
	{
	    
	      if(vi[v]==0){
	    
	        vi[v]=1;
	        recst[v]=1;
	        
	        for(auto j : adj[v])
	        {
	           
	            if(vi[j]==0 && dfs(j,vi,recst,adj))
	              return true;
	              
	              else if(recst[j]==1)
	                 return true;
	            
	              
	              
	        }
	        
	      }
	        
	    
	    
	  
	        recst[v] = 0;
	       
	    return false;
	    
	    
	}
	
	
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends