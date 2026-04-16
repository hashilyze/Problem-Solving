// [SWEA] 1288. 새로운 불면증 치료법

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables
int N;

int solution(int n){
   constexpr int MASK = 0x3FF;
   int digits = 0x00;
   
   int x = 0;
   while((digits & MASK) != MASK){
      ++x;

      int xN = x * n;
      while(xN > 0){
         digits |= 0x01 << (xN % 10);
         xN /= 10;
      }
   }
   return x * n;
}

int main(int argc, char **argv) {
   FASTIO
   
   int T;
   std::cin >> T;
   for(int t = 1; t <= T; ++t){
      std::cin >> N;
      std::cout << '#' << t << ' ' << solution(N) << '\n';
   }

   return 0;
}