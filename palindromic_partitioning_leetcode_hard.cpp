#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int RunningCounter=nums[0];
        int Ans=nums[0];
        for(int i=1; i<nums.size(); i++){
            RunningCounter=max(RunningCounter+nums[i], nums[i]);
            Ans=max(Ans, RunningCounter);
        }
        return Ans;
    }
};


void solve()
{
    int n;
    cin >>n;

    vector <int> res(n,0);

    for(int i=0;i<n;i++)
    {
        int x;
        cin >>x;

        res[i] = x;
    }

    Solution obj;

   int ans = obj.maxSubArray(res);

   cout<<ans<<"\n";

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


/*

INPUT :

5
3 -4 5 -2 6

OUTPUT :

9

*/