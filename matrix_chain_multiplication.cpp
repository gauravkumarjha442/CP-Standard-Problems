#include<bits/stdc++.h>
using namespace std;


   
    class Solution{
public:
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        
        int dp[n][n];
        memset(dp , 0 , sizeof(dp));
        
        for(int g=0;g<n-1;g++)
        {
            for(int i=0,j=g;j<n-1;j++,i++)
            {
                if(g==0)
                {
                    dp[i][j] = 0;
                }
                else if(g==1)
                {
                     dp[i][j] = arr[j-1]*arr[j]*arr[j+1];
                }
                else
                {
                      int row1 = i+1;
                      int col2 = i;
                      
                      int min1 = INT_MAX;
                      
                      while(col2<j)
                      {
                          
                          min1 = min(min1 , dp[i][col2]+dp[row1][j] + arr[i]*arr[row1]*arr[j+1]);
                          col2++;
                          row1++;
                      }
                      
                      dp[i][j] = min1;
                }
            }
        }

        
        return dp[0][n-2];
        
        
    }
};


int main()
{    
        #ifndef ONLINE_JUDGE
      freopen("input.txt" , "r" , stdin);
      freopen("output.txt" , "w" , stdout);
      #endif

     int n;
     cin >>n;

     int arr[n];

     for(int i=0;i<n;i++)
     {
          cin >>arr[i];
     }

     Solution obj;

    cout<<obj.matrixMultiplication(n,arr);

    return 0;
}
/* 
INPUT : 
4
10 30 5 60

OUTPUT :
4500


*/