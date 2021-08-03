#include <bits/stdc++.h>
using namespace std;

string bits(int a)
{
    string s1;

    while(a>0)
    {
       if(a%2==0)
       {
          s1 += '0';
       }
       else
       {
          s1 += '1';
       }

       a = a/2;
    }

    reverse(s1.begin() , s1.end());

   return s1;
}

int main()
{
    int n;
    cin >>n;

    string s1 = bits(n);

    cout<<s1;
}