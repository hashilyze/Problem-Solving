// [SWEA] 1217. [S/W 문제해결 기본] 4일차 - 거듭 제곱
#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables


int pow(int base, int exp){
   if(exp == 0) return 1;

   int half = pow(base, exp >> 1);
   if(exp % 2) return half * half * base;
   else return half * half;
}

int main(int argc, char **argv) {
   FASTIO
   
   int T = 10;
   //std::cin >> T;
   for(int t = 1; t <= T; ++t){
      std::cin >> t;
      int b, e;
      std::cin >> b >> e;
      std::cout << '#' << t << ' ' << pow(b, e) << '\n';
   }

   return 0;
}