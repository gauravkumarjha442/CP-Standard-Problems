#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution{
  public:
  /*  Function to find the number of strongly connected components
    *   using Kosaraju's algorithm
    *   V: number of vertices
    *   adj[]: array of vectors to represent graph
    */


int kosaraju(int V, vector<int> adj[]) {
        
       // code here

      stack <int> st;
      vector<bool> vi(V,false);
      vector<bool> vit(V,false);
      vector<int> adjt[V];

      
     for(int i=0;i<V;i++)
        if(!vi[i])
            dfs(i,adj , st , vi);

       /*int edge = 0;

      for(int i=0;i<V;i++)
            edge += adj[i].size(); */

     transpose(adj , V , adjt);

     int max1 = 1;

     vector<int> vec;
     
       
       while(!st.empty())
       {

          if(!vit[st.top()])
             {  
                vec.push_back(st.top());

                dfstranspose(st.top(),adjt , vit , vec);

            }    
  
         // cout<<comp<<" "<<st.top()<<"\n";
            int nlp = vec.size();

            for(int i=0;i<nlp;i++)
               cout<<vec[i]<<" ";

             cout<<"\n";

           max1 = max(nlp , max1);
           vec.clear();


            st.pop();

       }
     



    /*  for(int i=0;i<V;i++)
      {  
          cout<<i<<" : ";

          for(auto z : adjt[i])
                cout<<z<<" ";

          cout<<"\n";
      } */

      


      //cout<<edge<<"\n";
      
     /* while(st.size()>0)
      {
          cout<<st.top()<<" ";
           st.pop();
      }

      cout<<"\n"; */

      return max1;
          
        
    }


    void dfs(int v , vector<int>adj[] ,stack <int>&st , vector<bool>&vi)
   {
          vi[v] = true;

          for(auto z : adj[v])
          {
              if(!vi[z])
                dfs(z,adj,st,vi);
          }

          st.push(v);
  }

  void transpose(vector<int> adj[] , int v , vector<int> adj1[])
  {
         
        

         for(int i=0;i<v;i++)
         {
              for(auto z : adj[i])
              {
                   adj1[z].push_back(i);
              }
         }

  }

  void dfstranspose(int v , vector<int> adj[] , vector<bool>&vi , vector<int>&vec)
   {
           vi[v] = true;

          for(auto z : adj[v])
          {             
              if(!vi[z])
                {  
                   vec.push_back(z);
                   dfstranspose(z,adj,vi,vec);
                }
          }
  }
        


};




int main()
{
       
       #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" , stdin);
        freopen("output.txt" , "w" , stdout);
       #endif

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
      cout <<obj.kosaraju(V, adj) << "\n";
    

    return 0;
}


/*
8 10
0 1
1 2
2 0
2 3
3 4
4 5
4 7
5 6
6 4
6 7




*/