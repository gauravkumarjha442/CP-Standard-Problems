   int n = str.size();
   
   vector<vector<string> >dp(n,vector<string>(n ,""));
   vector<vector<int> >torf(n,vector<int>(n,0));
   
   
   
   
   for(int g=0;g<n;g++)
   {
       for(int i=0 , j=g;j<n;i++,j++)
       {
            if(g==0)
            {
                dp[i][j] = str[i];
                
                torf[i][j] = 1;
                  
            }
            
            else if(g==1)
            {
                dp[i][j] = dp[i][j-1] + str[j];
                
                if(str[i]==str[j])
                  torf[i][j] = 3;
                  
                else
                   torf[i][j] = 2;
                
            }
            
            else
            {
                 dp[i][j] = dp[i][j-1] + str[j];
                 
                 if(str[i]==str[j])
                 {
                    torf[i][j] = torf[i][j-1] + torf[i+1][j] + 1;
                 }
                 
                 else if(str[i]!=str[j])
                 {
                     torf[i][j] = torf[i][j-1] + torf[i+1][j] - torf[i+1][j-1];
                 }
                
            }
            
       }
   }
           
           
           
      return torf[0][n-1];
}