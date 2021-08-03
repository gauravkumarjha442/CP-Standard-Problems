
//calc  nCr  of big number

   int mxn = 1e5 + 5;

   vector<int> fact(mxn);
   vector<int> invfact(mxn);

   ll nCr(ll A,ll B) {
   return fact[A]*invfact[B]%MOD*invfact[A-B]%MOD; }

  // USE THIS IN  MAIN FUNCTION
   
   fact[0] = 1;
   for (int i = 1; i <mxn; i++) {
    fact[i] = fact[i - 1] * i % MOD;
      }

    for(int i = 0;i <mxn;i++) {
        invfact[i] = powermod(fact[i],MOD-2);
    }