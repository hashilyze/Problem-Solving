// [SWEA] 1976. 시각 덧셈

#include <iostream>
#include <tuple>
#include <utility>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int, int>;
// constants
// variables


pii solution(int hh1, int mm1, int hh2, int mm2){
   return {
      (hh1 + hh2 + (mm1 + mm2) / 60 - 1) % 12 + 1
      , (mm1 + mm2) % 60
   };
}

int main(int argc, char **argv) {
   FASTIO
   
   int T;
   std::cin >> T;
   for(int t = 1; t <= T; ++t){
      int hh1, mm1, hh2, mm2;
      std::cin >> hh1 >> mm1 >> hh2 >> mm2;

      int h, m;
      std::tie(h, m) = solution(hh1, mm1, hh2, mm2);
      std::cout << '#' << t << ' ' << h << ' ' << m << '\n';
   }

   return 0;
}