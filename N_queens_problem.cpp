#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //vector<vector<string>> solveNQueens(int n) {
        
        bool isSafe(vector<string> &v,int row,int column,int n)
    {
        int i,x,y;
        for(i=0;i<row;i++)
        {
            if(v[i][column]=='Q')
                return false;
        }
        x=row-1;
        y=column-1;
        while(x>=0 && y>=0)
        {
            if(v[x][y]=='Q')
                return false;
            x--;
            y--;
        }
        x=row-1;
        y=column+1;
        while(x>=0 && y<n)
        {
            if(v[x][y]=='Q')
                return false;
            x--;
            y++;
        }
        return true;
    }
    bool placequeen(vector<vector<string>> &sol,int i,int &n,vector <string> v)
    {
        if(i==n)
        {
            sol.push_back(v);
            return false;
        }
        for(int j=0;j<n;j++)
        {
            if(isSafe(v,i,j,n))
            {
                v[i][j]='Q';
                if(placequeen(sol,i+1,n,v))
                    return true;
            }
            v[i][j]='.';
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> sol;
        string s;
        for(int i=0;i<n;i++)
        {
            s+='.';
        }
        vector<string> v(n,s);
        bool y=placequeen(sol,0,n,v);
        return sol;
    }  
    
};

int main() {

      /*#ifndef ONLINE_JUDGE
      freopen("input.txt" , "r" , stdin);
      freopen("output.txt" , "w" , stdout);
      #endif*/

     /*int t;
     cout<<"Enter : ";
     cin >>t; */
     int t = 9;

     Solution obj;

    vector < vector <string>> v = obj.solveNQueens(t);

    for(int i=0;i<t;i++)
    {
      for(int j=0;j<t;j++)
         cout<<v[i][j]<<" ";

       cout<<endl;
    }
  

return 0;
}