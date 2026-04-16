// [SWEA] 1222. [S/W 문제해결 기본] 6일차 - 계산기1

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables


int main(int argc, char **argv) {
   FASTIO
   
   //int T; std::cin >> T;
   constexpr int T = 10;
   for(int t = 1; t <= T; ++t){
      int N;
      std::cin >> N;

      int result = 0;
      char ch;
      for(int i = 0; i < N; ++i){
         std::cin >> ch;
         if(ch == '+') ;
         else result += ch - '0';
      }
      std::cout << '#' << t << ' ' << result << '\n';
   }

   return 0;
}