#include<bits/stdc++.h>
using namespace std;

void solve(){
        
      
        int n;
        cin >>n;

        long long fact;

        // Binet's formula for calculating fibonacci numbers :-

        fact =  (pow( (1+sqrt(5)) , n) -  pow( (1-sqrt(5)) , n))/(pow(2,n)*sqrt(5));


        cout<<fact<<"\n";
       
         
 }



int main(){
   ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

      #ifndef ONLINE_JUDGE
      freopen("input.txt" , "r" , stdin);
      freopen("output.txt" , "w" , stdout);
      #endif

 /* int t=1,p;
  cin>>t;

  p = t;
  t=1;

  while(p--) 
     {
        cout<<"Case #"<<t<<": "; */
        solve();
        // t++;
    // }

  return 0;
}