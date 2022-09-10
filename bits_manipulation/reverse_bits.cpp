#include<bits/stdc++.h>
using namespace std;
// uint32_t means contain 32 bits for number(min)=>00000000000000000000000000000000
// max number can be=>11111111111111111111111111111111

uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        for(int i=0;i<32;i++){
            //if bit is set then add to ans(n&1);
            //left shift ans bits
            ans=(ans<<1)+(n&1);
            //right shift n bits
           n= n>>1;
        }
        return ans;
    }